#ifndef ONEGIN_H
#define ONEGIN_H

#include <stdio.h>

const int CORRECT_NUMBER_OF_FILES = 3;
const int NUMBER_OF_BLANK_STRINGS = 30;

struct text_data
{
    char** array_of_pointers;
    size_t number_of_strings;
};

void parse_argc_argv(int argc, const char* argv[]);
void check_files(FILE* poem_file, FILE* output_file);

char* read_file_to_buffer(FILE* poem_file);
void count_strings(char* buffer, size_t* number_of_strings);
void post_pointers(char** array_of_pointers, char* start_of_buffer, char* buffer);
char** strings_addresses_to_array(char* buffer, size_t* number_of_strings);

void bubble_sort(struct text_data* text, int (*comparison_function)(const void*, const void*));
void exchange_values(char** element_1, char** element_2);

int compare_strings(const void* string_1_address, const void* string_2_address);
int my_strcmp(const char* string_1, const char* string_2);
int compare_strings_reverse(const void* string_1_address, const void* string_2_address);
int my_strcmp_reverse(const char* string_1, const char* string_2);

void output_sorted_text(struct text_data* text, FILE* output_file);
void output_poem_text(size_t number_of_strings, char* buffer, FILE* output_file);

#endif // ONEGIN_H
