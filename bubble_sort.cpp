#include <assert.h>

#include "onegin.h"

void bubble_sort(char** array_of_pointers, int number_of_strings, int (*comparison_function)(const void*, const void*))
{
    assert(array_of_pointers);
    assert(*array_of_pointers);
    assert(comparison_function);
    for (int i = 0; i < number_of_strings - 1; i++)
    {
        for (int j = 0; j < number_of_strings - 1; j++)
        {
            if (comparison_function(&(array_of_pointers[j]), &(array_of_pointers[j+1])) == 1)
            {
                exchange_values(&(array_of_pointers[j]), &(array_of_pointers[j+1]));
            }
        }
    }
}

void exchange_values(char** element_1, char** element_2)
{
    assert(element_1);
    assert(element_2);
    assert(*element_1);
    assert(*element_2);

    char* first_element_1 = *element_1;
    *element_1 = *element_2;
    *element_2 = first_element_1;
}
