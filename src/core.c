/*
** EPITECH PROJECT, 2022
** my_rph
** File description:
** main file
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_rpg.h"

int main(int ac, char **av)
{
    int debug_mode = handle_args(ac, av);
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (debug_mode == -1)
        return 0;
    if (!rpg || errors_manager() == 84 || init_sfml(rpg, debug_mode))
        return 84;
    if (sfRenderWindow_isOpen(rpg->window))
        if (init_all(rpg) == 84)
            return 84;
    rpg->world->npc_list[0] =
    (npc_t){"", (sfVector2i){18, 18},1 , 50 , 20 , 20 , 20};
    rpg->world->npc_list[1] =
    (npc_t){"", (sfVector2i){110, 75},2 , 78 , 78 , 20 , 20};
    fill_map(rpg);
    srand(time(NULL));
    do_loop(rpg);
    save_game(rpg);
    free_rpg(rpg);
    return 0;
}
