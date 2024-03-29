/*
** EPITECH PROJECT, 2022
** flag_xX.c
** File description:
**  ->  implements %x which prints an unsigned integer as hexadecimal
*/

#include <my.h>
#include "my_printf.h"

static wchar_t *uint_to_hex(uintmax_t n, bool is_lower)
{
    if (is_lower) {
        return u_my_wputnbr_base(n, L"0123456789abcdef");
    }
    return u_my_wputnbr_base(n, L"0123456789ABCDEF");
}

wchar_t *flag_x(uintmax_t n, bool is_lower, unsigned precision)
{
    wchar_t *str = NULL;
    size_t str_length = 0;

    if (precision == 0 && n == 0) {
        return my_wstrdup(L"");
    }
    str = uint_to_hex(n, is_lower);
    str_length = my_wstrlen(str);
    while (str_length++ < precision) {
        str = wstr_prepend(str, '0');
    }
    return str;
}
