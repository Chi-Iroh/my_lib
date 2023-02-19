/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** my_real_printf
*/

#include <stdlib.h>
#include <unistd.h>
#include <my.h>
#include "my_printf.h"

int my_vfprintf(int fd, const char *restrict format, va_list args)
{
    va_list args;
    int return_code = 0;
    wchar_t *wformat = wstr_to_str(format);

    va_start(args, format);
    return_code = my_vfwprintf(fd, wformat, args);
    va_end(args);
    free(wformat);
    return return_code;
}

int my_vprintf(const char *restrict format, va_list args)
{
    return my_vfprintf(STDOUT_FILENO, format, args);
}

int my_fprintf(int fd, const char *restrict format, ...)
{
    va_list args;
    int return_code = 0;

    va_start(args, format);
    return_code = my_vfprintf(fd, format, args);
    va_end(args);
    return return_code;
}

int my_printf(const char *restrict format, ...)
{
    return my_fprintf(STDOUT_FILENO, format, ...);
}
