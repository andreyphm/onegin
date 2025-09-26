#include <assert.h>
#include <string.h>

#include "font.h"
#include "onegin.h"

void output_sorted_text(struct text_data* text, FILE* output_file)
{
    assert(text);
    assert(output_file);

    for (size_t i = 0; i < text->number_of_strings; i++)
    {
        fputs(text->array_of_pointers[i], output_file);
        putc('\n', output_file);
    }

    for (int j = 0; j < NUMBER_OF_BLANK_STRINGS; j++)
    {
        putc('\n', output_file);
    }
}

void output_poem_text(size_t number_of_strings, char* buffer, FILE* output_file)
{
    assert(buffer);
    assert(output_file);

    for (size_t i = 0; i < number_of_strings; i++)
    {
        buffer += fprintf(output_file, "%s\n", buffer);
    }
}
