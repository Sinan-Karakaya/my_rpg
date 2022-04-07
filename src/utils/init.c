/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init
*/

#include <stdlib.h>
#include "my_rpg.h"

int init_sfml(rpg_t *rpg)
{
    rpg->mode = (sfVideoMode){RES_X, RES_Y, 32};
    rpg->window = sfRenderWindow_create(rpg->mode, "my_rpg", sfClose, NULL);
    if (!rpg->window)
        return 1;
    sfRenderWindow_setPosition(rpg->window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(rpg->window, 60);
    rpg->game_clock = sfClock_create();
    return 0;
}
