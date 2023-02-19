/*
** EPITECH PROJECT, 2022
** perofrm_flags.c
** File description:
** -> handling each flag in the format string
*/

#include "call_flags.h"
#include "my_printf.h"

size_t format_and_print(int fd, wchar_t *str, flag_t *flag)
{
    size_t final_str_length = 0;

    str = apply_plus_and_space(str, flag);
    str = apply_hashtag(str, flag);
    str = apply_padding(str, flag);
    final_str_length = my_fwputstr(fd, str);
    free(str);
    return final_str_length;
}

wchar_t *call_flag(flag_t *flag, types_t *arg)
{
    if (is_char_in_wstr(L"di", flag->flag_struct->conversion_specifier)) {
        return flag_di(arg->signed_int, get_int_precision(flag));
    }
    if (is_char_in_wstr(L"uoxX", flag->flag_struct->conversion_specifier)) {
        return call_unsigned(flag, arg);
    }
    if (is_char_in_wstr(L"fFeEgGaA", flag->flag_struct->conversion_specifier)) {
        return call_float(flag, arg);
    }
    if (flag->flag_struct->conversion_specifier == L's') {
        return call_string(flag, arg);
    }
    if (flag->flag_struct->conversion_specifier == L'c') {
        return call_char(flag, arg);
    }
    return call_additional_flags(flag, arg);
}

size_t perform_flag
(int fd, const wchar_t *restrict *format, va_list args, int written)
{
    flag_t *flag = parse_flag(*format, args);
    types_t arg;
    size_t return_code = 0;

    if (!flag->is_ok) {
        return my_fwputstr(fd, flag->flag_str);
    }
    read_arg(&arg, args, flag);
    if (flag->flag_struct->conversion_specifier == 'n') {
        flag_n(arg.flag_n_ptr, written, flag->flag_struct->length_modifier);
    } else if (flag->flag_struct->conversion_specifier == '%') {
        return_code = my_fwputstr(fd, L"%");
    } else {
        return_code = format_and_print(fd, call_flag(flag, &arg), flag);
    }
    *format += my_wstrlen(flag->flag_str);
    free_flag(flag);
    return return_code;
}
