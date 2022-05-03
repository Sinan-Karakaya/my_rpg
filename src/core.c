/*
** EPITECH PROJECT, 2022
** my_rph
** File description:
** main file
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"

void fill_forest(rpg_t *rpg)
{
    rpg->world->object_map[4][74] = 5;
    rpg->world->object_map[13][74] = 7;
    rpg->world->object_map[47][15] = 7;
    rpg->world->object_map[18][52] = 7;
    rpg->world->object_map[12][51] = 5;
    rpg->world->object_map[13][67] = 5;
    rpg->world->object_map[20][66] = 5;
    rpg->world->object_map[28][70] = 5;
    rpg->world->object_map[29][56] = 5;
    rpg->world->object_map[39][54] = 5;
    rpg->world->object_map[38][70] = 7;
    rpg->world->object_map[31][43] = 5;
}

void fill_spawn(rpg_t *rpg)
{
    rpg->world->object_map[47][15] = 8;
    rpg->world->object_map[31][28] = 8;
    rpg->world->object_map[36][28] = 8;
}

void fill_map(rpg_t *rpg)
{
    fill_forest(rpg);
    fill_spawn(rpg);
    rpg->world->object_map[112][74] = 3;
    rpg->world->object_map[123][76] = 4;
    rpg->world->object_map[134][75] = 2;
}

int main(int ac, char **av)
{
    int debug_mode = handle_args(ac, av);
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (errors_manager() == 84)
       return 84;
    if (debug_mode == -1)
        return 0;
    if (!rpg || init_sfml(rpg, debug_mode))
        return 84;
    if (sfRenderWindow_isOpen(rpg->window))
        init_all(rpg);
    rpg->world->npc_list[0] = (npc_t){"PNJ 1", (sfVector2i){18, 18},1 , 50 , 20 , 20 , 20};
    rpg->world->npc_list[1] = (npc_t){"PNJ 1", (sfVector2i){110, 75},2 , 78 , 78 , 20 , 20};
    fill_map(rpg);
    do_loop(rpg);
    save_game(rpg);
    free_rpg(rpg);
    return 0;
}
