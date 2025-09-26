#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "onegin.h"

int compare_strings(const void* string_1_address, const void* string_2_address)
{
    assert(string_1_address);
    assert(string_2_address);

    const char* string_1 = *(char*const*) string_1_address;
    const char* string_2 = *(char*const*) string_2_address;

    return my_strcmp(string_1, string_2);
}

int compare_strings_reverse(const void* string_1_address, const void* string_2_address)
{
    assert(string_1_address);
    assert(string_2_address);

    const char* string_1 = *(char*const*) string_1_address;
    const char* string_2 = *(char*const*) string_2_address;

    return my_strcmp_reverse(string_1, string_2);
}

int my_strcmp(const char* string_1, const char* string_2)
{
    assert(string_1);
    assert(string_2);
    
    size_t strlen_1 = strlen(string_1);
    size_t strlen_2 = strlen(string_2);
    size_t i = 0, j = 0;
    while (i < strlen_1 && j < strlen_2)
    {
        if (isalpha(string_1[i]) && isalpha(string_2[j]))
        {
            if (tolower(string_1[i]) == tolower(string_2[j]))
            {
                i++;
                j++;
                continue;
            }
            else if (tolower(string_1[i]) > tolower(string_2[j]))
                return 1;
            else
                return -1;
        }
        else if (isalpha(string_1[i]) && !isalpha(string_2[j]))
        {
            j++;
        }
        else if (!isalpha(string_1[i]) && isalpha(string_2[j]))
        {
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    return 0;
}

int my_strcmp_reverse(const char* string_1, const char* string_2)
{
    assert(string_1);
    assert(string_2);

    int strlen_1 = strlen(string_1);
    int strlen_2 = strlen(string_2);
    int i = strlen_1, j = strlen_2;
    while (i >= 0 && j >= 0)
    {
        if (isalpha(string_1[i]) && isalpha(string_2[j]))
        {
            if (tolower(string_1[i]) == tolower(string_2[j]))
            {
                i--;
                j--;
                continue;
            }
            else if (tolower(string_1[i]) > tolower(string_2[j]))
                return 1;
            else
                return -1;
        }
        else if (isalpha(string_1[i]) && !isalpha(string_2[j]))
        {
            j--;
        }
        else if (!isalpha(string_1[i]) && isalpha(string_2[j]))
        {
            i--;
        }
        else
        {
            i--;
            j--;
        }
    }
    return 0;
}

