/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rand func
*/

#include <stdlib.h>

int get_rand_small_range(void)
{
    int rand_num = rand() % 5;
    int neg_rand = rand() % 2;

    if (neg_rand == 0)
        return rand_num;
    else
        return rand_num * -1;
    return 0;
}
