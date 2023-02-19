/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** ->   puts a single char in stdout stream
*/

#include <my.h>

void my_fwputchar(int fd, wchar_t c)
{
    my_fputchar(fd, c);
}

void my_wputchar(wchar_t c)
{
    my_fwputchar(STDOUT_FILENO, c);
}
