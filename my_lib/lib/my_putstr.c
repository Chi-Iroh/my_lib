/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** ->   displays a string
** ->   allowed function : my_putchar
*/

#include <my.h>

void my_fputstr(int fd, const char *str)
{
    while (str && *str) {
        my_fputchar(fd, *str++);
    }
}

void my_fputs(int fd, const char *str)
{
    my_fputstr(fd, str);
    my_fputchar(fd, '\n');
}

void my_puts(const char *str)
{
    my_fputs(STDOUT_FILENO, str);
}

void my_putstr(const char *str)
{
    my_fputstr(STDOUT_FILENO, str);
}
