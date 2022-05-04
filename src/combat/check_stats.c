/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** check stats
*/

#include "my_rpg.h"

void check_stat(rpg_t *rpg)
{
    if (STAT->xp >= STAT->xp_needed) {
        STAT->level++;
        STAT->xp_needed = (STAT->level * 1.25) * 20;
        STAT->xp = 0;
        rpg->combat->player->max_life += 10;
        STAT->attack += 3;
        STAT->defense += 3;
    }
}
