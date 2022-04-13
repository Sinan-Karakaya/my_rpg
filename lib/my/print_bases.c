/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** print bases
*/

#include "my.h"

void print_octal(va_list list)
{
    my_put_nbr_base(va_arg(list, long), "01234567");
}

void print_hex(va_list list)
{
    my_put_nbr_base(va_arg(list, long), "0123456789abcdef");
}

void print_hex_cap(va_list list)
{
    my_put_nbr_base(va_arg(list, long), "0123456789ABCDEF");
}

void print_bin(va_list list)
{
    my_put_nbr_base(va_arg(list, long), "01");
}
