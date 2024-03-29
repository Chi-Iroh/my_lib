/*
** EPITECH PROJECT, 2022
** char_traits.c
** File description:
** ->   some character traits
*/

#include "my_printf.h"

bool wis_letter(wchar_t c)
{
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

bool wis_nonzero_digit(wchar_t c)
{
    return '1' <= c && c <= '9';
}

bool wis_digit(wchar_t c)
{
    return c == '0' || wis_nonzero_digit(c);
}

bool wis_modifier(wchar_t c)
{
    return char_in_wstr(L" +-#0", c);
}

wchar_t wto_lower(wchar_t c)
{
    return ('A' <= c && c <= 'Z') ? c - ('A' - 'a') : c;
}
