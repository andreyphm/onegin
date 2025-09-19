#include "onegin.h"

void bubble_sort(struct text_data* text, int (*comparison_function)(const void*, const void*))
{
    for (size_t i = 0; i < text->number_of_strings - 1; i++)
    {
        for (size_t j = 0; j < text->number_of_strings - 1; j++)
        {
            if (comparison_function(&(text->array_of_pointers[j]), &(text->array_of_pointers[j+1])) == 1)
            {
                exchange_values(&(text->array_of_pointers[j]), &(text->array_of_pointers[j+1]));
            }
        }
    }
}

void exchange_values(char** element_1, char** element_2)
{
    char* first_element_1 = *element_1;
    *element_1 = *element_2;
    *element_2 = first_element_1;
}
