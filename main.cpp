#include <stdlib.h>

#include "font.h"
#include "onegin.h"

int main(int argc, const char* argv[])
{
    FILE* poem_file = fopen(argv[1], "r");
    FILE* output_file = fopen(argv[2], "w");

    parse_argc_argv(argc, argv);
    check_files(poem_file, output_file);

    size_t number_of_strings = 0;
    char* buffer = read_file_to_buffer(poem_file);
    char** array_of_pointers = strings_addresses_to_array(buffer, &number_of_strings);

    //bubble_sort(array_of_pointers, number_of_strings, compare_strings);
    qsort(array_of_pointers, number_of_strings, sizeof(char*), compare_strings);
    output_sorted_text(array_of_pointers, number_of_strings, output_file);

    //bubble_sort(array_of_pointers, number_of_strings, compare_strings_reverse);
    qsort(array_of_pointers, number_of_strings, sizeof(char*), compare_strings_reverse);
    output_sorted_text(array_of_pointers, number_of_strings, output_file);

    output_poem_text(number_of_strings, buffer, output_file);

    free(buffer);
    free(array_of_pointers);

    printf(MAKE_BOLD("Program completed. COMMIT GITHUB\n"));
    return 0;
}

void parse_argc_argv(int argc, const char* argv[])
{
    if (argc != CORRECT_NUMBER_OF_FILES)
    {
        printf(MAKE_BOLD_RED("Please, use: %s poem_file output_file.\n\n"), argv[0]);
        exit(EXIT_FAILURE);
    }
}

void check_files(FILE* poem_file, FILE* output_file)
{
    if (poem_file  == NULL)
    {
        printf(MAKE_BOLD_RED("Can't open poem file.\n\n"));
        exit(EXIT_FAILURE);
    }
    else if (output_file == NULL)
    {
        printf(MAKE_BOLD_RED("Can't open output file.\n\n"));
        exit(EXIT_FAILURE);
    }
}
