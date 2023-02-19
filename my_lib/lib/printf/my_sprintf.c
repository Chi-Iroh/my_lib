/*
** EPITECH PROJECT, 2022
** my_sprintf.c
** File description:
** -> sprintf function family
*/

#include "my_printf.h"

int my_vswprintf
(wchar_t *restrict wstr, const wchar_t *restrict wformat, va_list args)
{
    int written = 0;
    wchar_t *buffer = NULL;

    while (*wformat) {
        if (*wformat != '%') {
            *wstr++ = *wformat++;
            written++;
            continue;
        }
        written += perform_flag_in_str(&buffer, wformat, args, written);
        for (size_t i = 0; buffer && buffer[i]; i++) {
            *wstr++ = buffer[i];
        }
        free(buffer);
    }
    return written;
}

int my_vsprintf(char *restrict str, const char *restrict format, va_list args)
{

}

int my_swprintf(wchar_t *restrict wstr, const wchar_t *restrict wformat, ...)
{
    va_list args;
    int return_code = 0;

    va_start(args, wformat);
    return_code = my_vswprintf(wstr, wformat, args);
    va_end(args);
    return return_code;
}

int my_sprintf(char *restrict str, const wchar_t *restrict format, ...)
{

}
