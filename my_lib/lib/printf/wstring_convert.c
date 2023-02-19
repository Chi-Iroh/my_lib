/*
** EPITECH PROJECT, 2022
** wstring_convert.c
** File description:
**  ->  converts char * to wchar_t *
*/

#include <my.h>
#include "my_printf.h"

wchar_t *str_to_wstr(const char *str)
{
    wchar_t *wstr = my_wcalloc(my_strlen(str) + 1);

    for (size_t i = 0; str[i]; i++) {
        wstr[i] = str[i];
    }
    return wstr;
}
