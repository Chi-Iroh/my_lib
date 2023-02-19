/*
** EPITECH PROJECT, 2022
** my_wputstr.c
** File description:
** ->   displays a string
** ->   allowed function : my_putchar
*/

#include <my.h>

size_t my_fwputstr(int fd, const wchar_t *str)
{
    size_t length = 0;

    while (str && *str) {
        my_fwputchar(fd, *str++);
        length++;
    }
    return length;
}

size_t my_wputstr(const wchar_t *str)
{
    return my_fwputstr(STDOUT_FILENO, str);
}
