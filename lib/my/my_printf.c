/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf main file
*/

#include <stdlib.h>
#include <stdarg.h>

#include "my.h"

const flag_t FLAGS_FUNC[] = {
    {'c', &print_char},
    {'s', &print_str},
    {'d', &print_int},
    {'i', &print_int},
    {'u', &print_uns},
    {'p', &print_pointer},
    {'o', &print_octal},
    {'x', &print_hex},
    {'X', &print_hex_cap},
    {'b', &print_bin},
    {'S', &special_str},
};

void print_format(int nbr)
{
    for (int i = 0; i != nbr; i++)
        my_putchar('0');
}

int find_flag(const char *flag, va_list list, int pos)
{
    for (int i = 0; i < 11; i++) {
        if (flag[pos] == '#' && flag[pos + 1] == 'x') {
            my_putstr("0x");
            pos++;
        } if (flag[pos] == '0') {
            print_format(my_getnbr(&flag[pos]));
        } if (FLAGS_FUNC[i].flag == flag[pos]) {
            FLAGS_FUNC[i].fn(list);
            return 1;
        }
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);

    for (int i = 0; format[i]; i++) {
        if ((format[i] == '%' && (format[i - 1] != '\\' ||
        format[i - 1] != '%')) && find_flag(format, list, i + 1))
            i += 1;
        else
            my_putchar(format[i]);
    }
    va_end(list);
    return 0;
}
