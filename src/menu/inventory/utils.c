/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** utils
*/

#include "my_rpg.h"
#include "my.h"
#include <stdlib.h>

static int remove_neg(int nb)
{
    if (nb < 0) {
        if (nb == -2147483648)
            nb += 1;
        nb *= -1;
    }

    return (nb);
}

static int count_nbr(int nb)
{
    int c = 1;

    while (nb > 10) {
        nb /= 10;
        c++;
    }
    return (c);
}

void check_bignum(int *nb, int *big_num, int *n)
{
    if (*nb == -2147483648)
        *big_num = 51;
    if (*nb < 0)
        *n = 1;
    *nb = remove_neg(*nb);
}

char *int_to_str(int nb)
{
    int nb_count;
    char *str;
    int big_num = 0;
    int n = 0;
    int pos = 0;
    int data[2];

    check_bignum(&nb, &big_num, &n);
    nb_count = count_nbr(nb)-1;
    str = my_calloc(sizeof(char), nb_count + 3);
    if (!str)
        return NULL;
    clearstrnbr(str, nb_count + 2);
    data[0] = nb_count;
    data[1] = nb;
    loop_int_to_str(data, &big_num, &pos, str);
    return str;
}
