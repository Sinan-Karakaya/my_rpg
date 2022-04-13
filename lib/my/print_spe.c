/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** print %S
*/

#include "my.h"

static void check_zeros(char c)
{
    if (c < 8)
        my_putstr("00");
    else if (c > 7 && c < 32)
        my_put_nbr(0);
    else
        return;
}

void special_str(va_list list)
{
    char *str = va_arg(list, char *);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            check_zeros(str[i]);
            my_put_nbr_base(str[i], "01234567");
        } else
            my_putchar(str[i]);
    }
}
