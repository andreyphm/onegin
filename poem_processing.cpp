#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>

#include "onegin.h"

char* read_file_to_buffer(FILE* poem_file)
{
    assert(poem_file);

    struct stat file_struct = {};
    fstat(fileno(poem_file), &file_struct);
    size_t file_size = file_struct.st_size;

    char* buffer = (char*) calloc(file_size + 1, sizeof(*buffer));
    file_size = fread(buffer, sizeof(*buffer), file_size, poem_file);
    *(buffer + file_size) = '\0';

    return buffer;
}

char** strings_addresses_to_array(char* buffer, size_t* number_of_strings)
{
    assert(buffer);
    assert(number_of_strings);

    char* start_of_buffer = buffer;

    count_strings(buffer, number_of_strings);

    char** array_of_pointers = (char**) calloc(*number_of_strings + 1, sizeof(char*));
    assert(array_of_pointers);

    post_pointers(array_of_pointers, start_of_buffer, buffer);
    assert(*array_of_pointers);

    return array_of_pointers;
}

void count_strings(char* buffer, size_t* number_of_strings)
{
    assert(buffer);
    assert(number_of_strings);

    char* string_pointer = 0;

    while ((string_pointer = strchr(buffer, '\n')) != NULL)
    {
        *number_of_strings += 1;
        buffer = string_pointer + 1;
    }
}

void post_pointers(char** array_of_pointers, char* start_of_buffer, char* buffer)
{
    assert(array_of_pointers);
    assert(start_of_buffer);
    assert(buffer);

    char* string_pointer = 0;
    buffer = start_of_buffer;
    array_of_pointers[0] = start_of_buffer;

    for (int i = 1; (string_pointer = strchr(buffer, '\n')) != NULL; i++)
    {
        *string_pointer = '\0';
        array_of_pointers[i] = string_pointer + 1;
        buffer = string_pointer + 1;
    }
}
