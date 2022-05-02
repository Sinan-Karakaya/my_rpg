/*
** EPITECH PROJECT, 2022
** my_rph
** File description:
** main file
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"

int main(int ac, char **av)
{
    int debug_mode = handle_args(ac, av);
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (debug_mode == -1)
        return 0;
    if (!rpg || init_sfml(rpg, debug_mode))
        return 84;
    if (sfRenderWindow_isOpen(rpg->window))
        init_all(rpg);
    rpg->world->object_map[20][20] = 1;
    rpg->world->object_map[25][20] = 1;
    rpg->world->object_map[18][2] = 3;
    rpg->world->npc_list[0] = (npc_t){"PNJ 1", (sfVector2i){18, 18},2 , 50 , 20 , 20 , 20};

    do_loop(rpg);
    free_rpg(rpg);
    return 0;
}
