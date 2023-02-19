/*
** EPITECH PROJECT, 2022
** flag_a.c
** File description:
** ->   flag %g
*/

#include <stdlib.h>
#include <my.h>
#include <my_macros.h>
#include "my_printf.h"

static size_t fractional_part_end_index(wchar_t *str, bool is_lower)
{
    const wchar_t exponent[2] = { is_lower ? 'e' : 'E', '\0' };
    const wchar_t *const exponent_ptr = my_wstrstr(str, &exponent[0]);

    if (exponent_ptr == NULL) {
        return my_wstrlen(str) - 1;
    }
    return exponent_ptr - str - 1;
}

static wchar_t *remove_trailing_zeros(wchar_t *str, bool is_lower)
{
    size_t exponent_index = 0;

    exponent_index = fractional_part_end_index(str, is_lower);
    while (str[exponent_index] == '0') {
        str = wstr_pop(str, exponent_index--);
    }
    if (str[exponent_index] == '.') {
        str = wstr_pop(str, exponent_index--);
    }
    return str;
}

wchar_t *flag_g
(long double n, unsigned decimals, bool is_lower, bool has_hashtag)
{
    const short exponent = get_exp10(ABS(n));
    const int precision = decimals ? decimals : 1;
    wchar_t *str = NULL;

    if (precision > exponent && exponent >= -4) {
        str = flag_f(n, precision - 1 - exponent, is_lower, has_hashtag);
    } else {
        str = flag_e(n, precision - 1, is_lower, has_hashtag);
    }
    if (!has_hashtag) {
        str = remove_trailing_zeros(str, is_lower);
    }
    return str;
}
