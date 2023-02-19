/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** flag_length
*/

#include <wchar.h>
#include <stdbool.h>
#include <stddef.h>

bool is_char_in_wstr(const wchar_t *str, wchar_t c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

size_t flag_length(const wchar_t *format, size_t start)
{
    size_t length = 1;
    wchar_t *const flag_string = L"csdioxXufFeEaAgGnp%";

    while (*format && !is_char_in_wstr(flag_string, *format++)) {
        length++;
    }
    return length;
}

size_t flag_start_point(wchar_t *format, size_t start)
{
    while (format[start] != '\0' && format[start] != '%') {
        start++;
    }
    return format[start] == '\0' ? -1 : start;
}
