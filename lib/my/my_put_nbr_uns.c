/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** func
*/

#include "my.h"

unsigned int my_put_nbr_uns(unsigned int nb)
{
    unsigned int temp = 0;

    if (nb > 9) {
        temp = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(temp + 48);
    } else
        my_putchar(nb + 48);

    return 0;
}
