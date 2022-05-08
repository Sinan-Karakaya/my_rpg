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

static npc_t cnpc(sfVector2i pos, sfVector2i value, sfVector2i value2, size_t i)
{
    npc_t my_npc;

    my_npc.name = "";
    my_npc.pos = pos;
    my_npc.type = value.x;
    my_npc.max_life = value.y;
    my_npc.attack = value2.x;
    my_npc.defense = value2.y;
    my_npc.speed = i;
    return my_npc;
}

int main(int ac, char **av, char **env)
{
    int debug_mode = handle_args(ac, av);
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (debug_mode == -1)
        return 0;
    if (!rpg || errors_manager(env) == 84 || init_sfml(rpg, debug_mode))
        return 84;
    if (sfRenderWindow_isOpen(rpg->window))
        if (init_all(rpg) == 84)
            return 84;

    rpg->world->npc_list[0] = cnpc((sfVector2i){18, 18}, (sfVector2i){1, 50},
    (sfVector2i){20, 20}, 20);
    rpg->world->npc_list[1] = cnpc((sfVector2i){110, 75}, (sfVector2i){2, 78},
    (sfVector2i){78, 20}, 20);
    fill_map(rpg);
    srand(time(NULL));
    do_loop(rpg);
    save_game(rpg), free_rpg(rpg);
    return 0;
}
