/*
** EPITECH PROJECT, 2022
** str_array2.c
** File description:
** -> functions to work with arrays of strings
*/

#include <stddef.h>
#include <stdlib.h>
#include <my_macros.h>

void str_array_free(char **array, size_t length)
{
    for (size_t i = 0; array && i < length; i++) {
        FREE_IF_ALLOCATED(array[i], free);
    }
    FREE_IF_ALLOCATED(array, free);
}
