/*
** EPITECH PROJECT, 2022
** header.h
** File description:
** ->   protos
*/

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <wchar.h>
#include <stdbool.h>

extern const int DEFAULT_PRECISION;

bool
does_substr_match(const wchar_t *str, const wchar_t *substr, size_t start);
wchar_t *u_my_wputnbr_base(uintmax_t n, const wchar_t *base);
wchar_t *my_wputnbr_base(intmax_t n, const wchar_t *base);
wchar_t *wstr_append(wchar_t *str, wchar_t c);
wchar_t *wstr_prepend(wchar_t *str, wchar_t c);
wchar_t *wstr_back(wchar_t *str);
wchar_t *wstr_padding(wchar_t *str, size_t length, size_t left_padding, wchar_t c);
wchar_t *wstr_append_wstr(wchar_t *str, wchar_t *to_add);
wchar_t *wstr_insert(wchar_t *str, size_t index, wchar_t c);
wchar_t *wstr_pop(wchar_t *str, size_t index);
wchar_t wto_lower(wchar_t c);

wchar_t *my_wcalloc(size_t length);
long long my_wgetnbr(const wchar_t *str);
void my_fwputchar(int fd, wchar_t c);
void my_wputchar(wchar_t c);
size_t my_fwputstr(int fd, const wchar_t *str);
int my_wputstr(const wchar_t *str);
int my_wstrcmp(const wchar_t *s1, const wchar_t *s2);
wchar_t *my_wstrndup(const wchar_t *src, size_t n);
wchar_t *my_wstrdup(const wchar_t *src);
size_t my_wstrlen(const wchar_t *str);
const wchar_t *my_wstrstr(const wchar_t *str, const wchar_t *to_find);

int my_isinf(long double n);
int my_isnan(long double n);
short get_exp10(long double n);

wchar_t *flag_di(intmax_t n, unsigned precision);
wchar_t *flag_u(uintmax_t n, unsigned precision);
wchar_t *flag_o(uintmax_t n, unsigned precision);
wchar_t *flag_x(uintmax_t n, bool is_lower, unsigned precision);
wchar_t *flag_f
(long double n, unsigned decimals, bool is_lower, bool has_hashtag);
wchar_t *flag_p(void *ptr);
wchar_t *flag_e(long double n, int decimals, bool is_lower, int has_hashtag);
wchar_t *flag_g(long double n, int decimals, bool is_lower, int has_hashtag);
wchar_t *flag_a(long double n, int decimals, bool is_lower, int has_hashtag);
wchar_t *flag_s(char *str, int precision);
wchar_t *wflag_s(wchar_t *str, int precision);
wchar_t *flag_c(int c);
wchar_t *wflag_c(wint_t c);
wchar_t *flag_b(uintmax_t n);
wchar_t *flag_upper_s(char *str);

unsigned flag_start_point(wchar_t *format, int start);
unsigned flag_length(const wchar_t *format, int start);

bool is_char_in_wstr(const wchar_t *str, wchar_t c);
wchar_t *str_to_wstr(const char *str);

typedef struct {
    bool has_hyphen;
    bool has_plus;
    bool has_space;
    bool has_hashtag;
    bool has_zero;
    bool field_width;
    bool is_precision_specified;
    unsigned precision;
    wchar_t *length_modifier;
    wchar_t conversion_specifier;
} flag_struct_t;

typedef struct {
    flag_struct_t *flag_struct;
    wchar_t *flag_str;
    bool is_ok;
} flag_t;

unsigned get_int_precision(flag_t *flag);
unsigned get_str_precision(flag_t *flag);

void free_flag(flag_t *flag);
flag_t *parse_flag(const wchar_t *format, va_list args);
wchar_t *apply_hashtag(wchar_t *str, flag_t *flag);
wchar_t *apply_plus_and_space(wchar_t *str, flag_t *flag);
wchar_t *apply_padding(wchar_t *str, flag_t *flag);
void flag_n(intmax_t *integer, int written, wchar_t *length_modifier);

typedef union {
    intmax_t signed_int;
    uintmax_t unsigned_int;
    char char_;
    wchar_t wchar;
    char *str;
    wchar_t *wstr;
    long double floating_point;
    intmax_t *flag_n_ptr;
    void *flag_p_ptr;
} types_t;

int read_arg(types_t *arg, va_list args, flag_t *flag);
int format_and_print(wchar_t *str, flag_t *flag);
wchar_t *call_flag(flag_t *flag, types_t *arg);
int perform_flag(const wchar_t *restrict format, va_list args, int written);

int my_printf(const char *restrict format, ...);
int my_vprintf(const char *restrict format, va_list args);
int my_fprintf(int fd, const char *restrict format, ...);
int my_vfprintf(int fd, const char *restrict format, va_list args);

int my_wprintf(const wchar_t *restrict wformat, ...);
int my_vwprintf(const wchar_t *restrict wformat, va_list args);
int my_fwprintf(int fd, const wchar_t *restrict wformat, ...);
int my_vfwprintf(int fd, const wchar_t *wformat, va_list args);
