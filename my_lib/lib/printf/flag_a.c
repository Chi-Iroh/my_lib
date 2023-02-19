/*
** EPITECH PROJECT, 2022
** flag_a.c
** File description:
** ->   flag %a -> writes a float in hexadecimal notation
*/

#include <stdlib.h>
#include <my.h>
#include <my_macros.h>
#include "my_printf.h"
#include "flag_a.h"

static wchar_t *remove_trailing_zeros(wchar_t *str, bool has_hastag)
{
    size_t end_index = my_wstrlen(str) - 1;

    while (str[end_index] == '0') {
        str = wstr_pop(str, end_index--);
    }
    if (str[end_index] == '.' && !has_hastag) {
        free(str);
        str = NULL;
    }
    return str;
}

static wchar_t *hex_decimals
(long double n, unsigned decimals, bool has_hastag, bool is_lower)
{
    unsigned short digit = 0;
    const wchar_t *base = is_lower ? L"0123456789abcdef" : L"0123456789ABCDEF";
    wchar_t *str = my_wstrdup(L".");

    while (decimals--) {
        digit = n * 16.L;
        n = n * 16.L - digit;
        str = wstr_append_wstr(str, u_my_wputnbr_base(digit, base));
    }
    return remove_trailing_zeros(str, has_hastag);
}

static wchar_t *append_exponent(wchar_t *str, short exponent, bool is_lower)
{
    str = wstr_append(str, is_lower ? 'p' : 'P');
    if (exponent < 0) {
        str = wstr_append(str, '-');
        exponent = -exponent;
    } else {
        str = wstr_append(str, '+');
    }
    return wstr_append_wstr(str, my_wputnbr_base(exponent, L"0123456789"));
}

wchar_t *flag_a_impl
(long double n, unsigned decimals, bool is_lower, bool has_hashtag)
{
    const short exponent = get_exp2(n);
    wchar_t *str = (n < 0.L) ? my_wstrdup(L"-") : my_wstrdup(L"");
    long double power2 = 0.L;
    int bigger_than_exponent = 0;
    wchar_t *hex_digits = NULL;
    wchar_t *const prefix = is_lower ? my_wstrdup(L"0x") : my_wstrdup(L"0X");

    str = wstr_append_wstr(str, prefix);
    n = ABS(n);
    power2 = pow2(exponent);
    bigger_than_exponent = n >= power2;
    str = wstr_append(str, '0' + bigger_than_exponent);
    n = (n / power2) - bigger_than_exponent;
    hex_digits = hex_decimals(n, decimals, has_hashtag, is_lower);
    str = wstr_append_wstr(str, hex_digits);
    return append_exponent(str, exponent, is_lower);
}

wchar_t *flag_a
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
    return flag_a_impl(n, decimals, is_lower, has_hashtag);
}
