/*
** EPITECH PROJECT, 2022
** my_sring.c
** File description:
** ->   dynamic string
*/

#include <stdlib.h>
#include <stddef.h>
#include <my.h>
#include <my_macros.h>
#include "my_printf.h"

wchar_t *wstr_append(wchar_t *str, wchar_t c)
{
    const size_t length = my_wstrlen(str);
    wchar_t *new_str = my_wcalloc(length + 2);

    for (size_t i = 0; i < length; i++) {
        new_str[i] = str[i];
    }
    new_str[length] = c;
    FREE_IF_ALLOCATED(str, free);
    return new_str;
}

wchar_t *wstr_prepend(wchar_t *str, wchar_t c)
{
    const size_t length = my_wstrlen(str);
    wchar_t *new_str = my_wcalloc(length + 2);

    new_str[0] = c;
    for (size_t i = 0; i < length; i++) {
        new_str[i + 1] = str[i];
    }
    FREE_IF_ALLOCATED(str, free);
    return new_str;
}

wchar_t *wstr_back(wchar_t *str)
{
    return str + my_wstrlen(str) - 1;
}

wchar_t *wstr_padding
(wchar_t *str, size_t length, size_t left_padding, wchar_t c)
{
    const size_t str_length = my_wstrlen(str);

    for (size_t i = 0; i < length - str_length; i++) {
        str = left_padding ? wstr_prepend(str, c) : wstr_append(str, c);
    }
    return str;
}

wchar_t *wstr_append_wstr(wchar_t *str, wchar_t *to_add)
{
    const size_t str_length = str ? my_wstrlen(str) : 0;
    const size_t to_add_length = to_add ? my_wstrlen(to_add) : 0;
    wchar_t *new_str = my_wcalloc(str_length + to_add_length + 1);

    for (size_t i = 0; i < str_length; i++) {
        new_str = wstr_append(new_str, str[i]);
    }
    for (size_t i = 0; i < to_add_length; i++) {
        new_str = wstr_append(new_str, to_add[i]);
    }
    FREE_IF_ALLOCATED(str, free);
    return new_str;
}
