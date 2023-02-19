/*
** EPITECH PROJECT, 2022
** my_wprintf.c
** File description:
** -> implementing wprintf family functions
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <my.h>

int my_vfwprintf(int fd, const wchar_t *restrict wformat, va_list args)
{
    int written = 0;

    while (*wformat) {
        if (*wformat != '%') {
            my_fputchar(fd, *wformat++);
            written++;
        } else {
            written += perform_flag(fd, args, written);
        }
    }
    return written;
}

int my_fwprintf(int fd, const wchar_t *restrict wformat, ...)
{
    va_list args;
    int return_code = 0;
    wchar_t *copy_wformat = my_wstrdup(wformat);

    va_start(args, wformat);
    return_code = my_vfwprintf(copy_wformat, args);
    va_end(args);
    free(copy_wformat);
    return return_code;
}

int my_vwprintf(const wchar_t *restrict wformat, va_list args)
{
    return my_vfwprintf(STDOUT_FILENO, wformat, args);
}

int my_wprintf(const wchar_t *restrict wformat, ...)
{
    va_list args;
    int return_code = 0;
    wchar_t *copy_wformat = my_wstrdup(wformat);

    va_start(args, wformat);
    return_code = my_vfwprintf(STDOUT_FILENO, copy_wformat, args);
    va_end(args);
    free(copy_wformat);
    return return_code;
}
