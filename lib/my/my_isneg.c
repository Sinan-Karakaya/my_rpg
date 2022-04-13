/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** Check if num is negative
*/

#include "my.h"

int my_isneg(int n)
{
    if (n > 0 || n == 0)
        my_putchar('P');
    else if (n < 0)
        my_putchar('N');

    my_putchar('\n');
    return 0;
}
