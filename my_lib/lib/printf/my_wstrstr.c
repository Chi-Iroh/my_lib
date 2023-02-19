/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** ->   looks for a substring into a string
*/

#include <stdlib.h>
#include <my.h>
#include <stdbool.h>

bool does_substr_match(const wchar_t *str, const wchar_t *substr, size_t start)
{
    if (!str || !substr) {
        return false;
    }
    const unsigned substr_len = my_wstrlen(substr);
    const unsigned str_len = my_wstrlen(str);
    if (substr_len > str_len) {
        return false;
    }
    for (unsigned i = 0; i < substr_len; i++) {
        if (str[start + i] != substr[i]) {
            return false;
        }
    }
    return true;
}

const wchar_t *my_wstrstr(const wchar_t *str, const wchar_t *to_find)
{
    const bool is_ok = str && to_find;
    const size_t str_len = is_ok ? my_wstrlen(str) : 0;

    if (!is_ok) {
        return str;
    }
    if (str_len == 0) {
        return *to_find == '\0' ? str : NULL;
    }
    for (size_t i = 0; i < str_len; i++) {
        if (does_substr_match(str, to_find, i)) {
            return &str[i];
        }
    }
    return NULL;
}
