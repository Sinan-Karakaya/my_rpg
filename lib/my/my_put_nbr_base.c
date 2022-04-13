/*
** EPITECH PROJECT, 2021
** my_put_nbr_base
** File description:
** print a num in a base
*/

#include <stdlib.h>

#include "my.h"

void my_put_nbr_base(long nb, char *base)
{
    int i = 0;
    long temp = 0;

    temp = nb % my_strlen(base);
    nb /= my_strlen(base);
    if (nb > 0)
        my_put_nbr_base(nb, base);
    my_putchar(base[temp]);
}
