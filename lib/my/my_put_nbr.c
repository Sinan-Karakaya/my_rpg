/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** func
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int temp = 0;

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
