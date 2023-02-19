/*
** EPITECH PROJECT, 2022
** my_get_nbr.h
** File description:
** ->   protos for my_get_nbr
*/

#pragma once

#include <wchar.h>
#include <stdbool.h>

bool is_wchar_valid_in_nbr(wchar_t c);
size_t my_wnbr_strlen(const wchar_t *str);
unsigned short max_power_before_long_long_overflow(void);
long long my_pow10(int n);
