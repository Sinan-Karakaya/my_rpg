/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_stats
*/

#include "my_rpg.h"
#include <stdio.h>

const sfVector3f my_stats[] = {
    (sfVector3f){0, 0, 0},
    (sfVector3f){0, 5, 20},
    (sfVector3f){0, 0, 0},
    (sfVector3f){10, 0, 5},
    (sfVector3f){0, 20, 50},
    (sfVector3f){0, 10, 20},
    (sfVector3f){20, 0, 10},
    (sfVector3f){0, 10, 20}
};

void init_stats(rpg_t *rpg)
{
    size_t item_id = 0;
    sfVector3f stats = {0, 0, 0};
    rpg->combat->player->stat->stuff->attack = 0;
    rpg->combat->player->stat->stuff->defense = 0;
    rpg->combat->player->stat->stuff->life = 0;

    for (size_t i = 30; i < 34; i++) {
        if (rpg->menu->inventory->slots[i]->item_id != 0) {
            item_id = rpg->menu->inventory->slots[i]->item_id;
            stats = my_stats[item_id];
            rpg->combat->player->stat->stuff->attack += stats.x;
            rpg->combat->player->stat->stuff->defense += stats.y;
            rpg->combat->player->stat->stuff->life += stats.z;
        }
    }
}
