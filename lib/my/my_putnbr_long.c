/*
** EPITECH PROJECT, 2021
** my_putnbr_long
** File description:
** put long
*/

#include "my.h"

int my_put_nbr_long(long nb)
{
    long temp = 0;

    if (nb < 0) {
        my_putchar(45);
        nb = nb * (-1);
    } if (nb > 9) {
        temp = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(temp + 48);
    } else
        my_putchar(nb + 48);

    return 0;
}
