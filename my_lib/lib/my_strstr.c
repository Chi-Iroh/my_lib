/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** ->   looks for a substring into a string
*/

#include <my.h>

static bool does_substr_nmatch
(const char *str, const char *substr, size_t start, size_t str_length)
{
    if (!str || !substr) {
        return false;
    }
    const size_t substr_len = my_strlen(substr);
    if (substr_len > str_length) {
        return false;
    }
    for (size_t i = 0; i < substr_len; i++) {
        if (str[start + i] != substr[i]) {
            return false;
        }
    }
    return true;
}

const char *my_strnstr(const char *str, const char *to_find, size_t n)
{
    if (!str || !to_find) {
        return str;
    }
    for (size_t i = 0; i < n; i++) {
        if (does_substr_nmatch(str, to_find, i, n)) {
            return str + i;
        }
    }
    return NULL;
}

const char *my_strstr(const char *str, const char *to_find)
{
    return my_strnstr(str, to_find, my_strlen(str));
}
