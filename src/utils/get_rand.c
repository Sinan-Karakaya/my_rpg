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

    return rand_num;
}

int toss_coin(void)
{
    int rand_num = rand() % 2;

    return rand_num;
}
