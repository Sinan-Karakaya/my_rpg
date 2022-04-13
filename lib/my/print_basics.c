/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf print basics flags
*/

#include <stdlib.h>
#include <stdarg.h>

#include "my.h"

void print_char(va_list list)
{
    my_putchar(va_arg(list, int));
}

void print_str(va_list list)
{
    my_putstr(va_arg(list, char *));
}

void print_int(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

void print_uns(va_list list)
{
    my_put_nbr_uns(va_arg(list, unsigned int));
}

void print_pointer(va_list list)
{
    long var = va_arg(list, long);

    my_putstr("0x");
    my_put_nbr_base(var, "0123456789abcdef");
}
