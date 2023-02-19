/*
** EPITECH PROJECT, 2022
** float_str.c
** File description:
** ->   converts double into buffer and rounding it
*/

#include <float.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <my.h>
#include <my_macros.h>
#include "flag_f.h"
#include "my_printf.h"

const int DEFAULT_PRECISION = 6;

static wchar_t *flag_f_impl(long double n, unsigned decimals, bool has_hashtag)
{
    wchar_t *buffer = double_integer_part_to_wstr(&n);

    if (decimals) {
        buffer = wstr_append(buffer, '.');
        while (decimals--) {
            n *= 10.L;
            buffer = wstr_append(buffer, '0' + (int)n);
            n -= (int)n;
        }
    }
    if (n >= 0.5L && *wstr_back(buffer) != '0') {
        buffer = round_up(&buffer, wstr_back(buffer));
    }
    if (!my_wstrstr(buffer, L".") && has_hashtag) {
        buffer = wstr_append(buffer, '.');
    }
    return buffer;
}

wchar_t *flag_f
(long double n, unsigned decimals, bool is_lower, bool has_hashtag)
{
    if (my_isnan(n)) {
        return is_lower ? my_wstrdup(L"-nan") : my_wstrdup(L"-NAN");
    }
    if (my_isinf(n)) {
        if (n < 0) {
            return is_lower ? my_wstrdup(L"-inf") : my_wstrdup(L"-INF");
        } else {
            return is_lower ? my_wstrdup(L"inf") : my_wstrdup(L"INF");
        }
    }
    return flag_f_impl(n, decimals, has_hashtag);
}
