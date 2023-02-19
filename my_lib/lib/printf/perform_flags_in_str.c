/*
** EPITECH PROJECT, 2022
** perofrm_flags_in_str.c
** File description:
** -> handling each flag in the format string (for sprintf family functions)
*/

#include "call_flags.h"
#include "my_printf.h"

size_t format_and_print_in_str(wchar_t **buffer, wchar_t *wstr, flag_t *flag)
{
    size_t final_str_length = 0;

    wstr = apply_plus_and_space(wstr, flag);
    wstr = apply_hashtag(wstr, flag);
    wstr = apply_padding(wstr, flag);
    *buffer = wstr_append_wstr(*buffer, wstr);
    free(wstr);
    return final_str_length;
}

static size_t handle_flag_in_str
(wchar_t **wstr, int written, types_t *arg, flag_t *flag)
{
    if (flag->flag_struct->conversion_specifier == 'n') {
        flag_n(arg->flag_n_ptr, written, flag->flag_struct->length_modifier);
        return 0;
    } else if (flag->flag_struct->conversion_specifier == '%') {
        *wstr = wstr_append_wstr(*wstr, L"%");
        return 1;
    } else {
        return format_and_print_in_str(wstr, call_flag(flag, &arg), flag);
    }
}

size_t perform_flag_in_str
(wchar_t **wstr, const wchar_t *restrict *wformat, va_list args, int written)
{
    flag_t *flag = parse_flag(*wformat, args);
    types_t arg;
    size_t return_code = 0;

    if (!flag->is_ok) {
        free(*wstr);
        *wstr = wstr_append_str(*wstr, my_wstrdup(flag->flag_str));
        return my_wstrlen(*wstr);
    }
    read_arg(&arg, args, flag);
    return_code = handle_flag_in_str(wstr, written, &arg, flag);
    *wformat += my_wstrlen(flag->flag_str);
    free_flag(flag);
    return return_code;
}
