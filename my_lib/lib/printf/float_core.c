/*
** EPITECH PROJECT, 2022
** float_core.c
** File description:
** ->   core functions for floating-point numbers
*/

#include <float.h>
#include <stdlib.h>
#include "my_printf.h"

static long double max_pow10(long double n)
{
    long double pow = 1.L;

    while (pow <= n / 10.L) {
        pow *= 10.L;
    }
    return pow;
}

wchar_t *round_up(wchar_t **start, wchar_t *end)
{
    bool must_add_leading_one = 0;

    while (end >= *start) {
        if (*end == '9') {
            *end = '0';
            must_add_leading_one = end == *start;
            end--;
            continue;
        }
        if (*end != '.') {
            (*end)++;
            break;
        }
        end--;
    }
    if (must_add_leading_one) {
        *start = wstr_prepend(*start, '1');
    }
    return *start;
}

wchar_t *double_integer_part_to_wstr(long double *n)
{
    wchar_t *buffer = NULL;
    long double pow = 0.L;
    int digit = 0;

    if (*n < 0.L) {
        buffer = wstr_append(buffer, '-');
        *n = -(*n);
    }
    for (pow = max_pow10(*n); pow >= 1.L; pow /= 10.L) {
        digit = *n / pow;
        buffer = wstr_append(buffer, '0' + digit);
        *n -= pow * digit;
    }
    return buffer;
}

bool my_isnan(long double n)
{
    return n != n;
}

bool my_isinf(long double n)
{
    return n > LDBL_MAX || n < -LDBL_MAX;
}
