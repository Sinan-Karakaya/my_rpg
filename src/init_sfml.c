/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init sfml
*/

#include <stdlib.h>

#include "my_rpg.h"

int init_sfml(rpg_t *rpg, int debug_mode)
{
    rpg->mode = (sfVideoMode){RES_X, RES_Y, 32};
    rpg->window = sfRenderWindow_create(rpg->mode, "my_rpg", sfClose, NULL);
    if (!rpg->window)
        return 1;
    sfRenderWindow_setPosition(rpg->window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(rpg->window, 60);
    rpg->game_clock = sfClock_create();
    (debug_mode) ? (rpg->debug_toggle = true) : (rpg->debug_toggle = false);
    if (!(rpg->debug = malloc(sizeof(debug_t))))
        return 1;
    if (!(rpg->debug->text = sfText_create()))
        return 1;
    sfText_setPosition(rpg->debug->text, (sfVector2f){10, 10});
    if (!(rpg->debug->font = sfFont_createFromFile(FONT_PATH)))
        return 1;
    sfText_setFont(rpg->debug->text, rpg->debug->font);
    sfText_setOutlineColor(rpg->debug->text, sfBlack);
    sfText_setOutlineThickness(rpg->debug->text, 1);
    rpg->ow_can_move = true;
    return 0;
}
