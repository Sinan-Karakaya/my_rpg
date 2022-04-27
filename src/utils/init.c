/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init
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
    rpg->debug = malloc(sizeof(debug_t));
    if (!rpg->debug)
        return 1;
    rpg->debug->text = sfText_create();
    sfText_setPosition(rpg->debug->text, (sfVector2f){10, 10});
    rpg->debug->font = sfFont_createFromFile(FONT_PATH);
    sfText_setFont(rpg->debug->text, rpg->debug->font);
    sfText_setOutlineColor(rpg->debug->text, sfBlack);
    sfText_setOutlineThickness(rpg->debug->text, 1);
    rpg->ow_can_move = true;
    return 0;
}

int init_all(rpg_t *rpg)
{
    rpg->combat = init_combat();
    init_cam(rpg);
    init_world(rpg);
    // init_shaders(rpg);
    init_sound(rpg);
    init_menu(rpg);
    init_buttons(rpg);
    init_player_overworld(rpg);
    init_keybind(rpg);
    init_inventory(rpg);
    // read_save(rpg);          CRASH?
    rpg->texture = init_struct_texture("assets/environement/pr.png", rpg);
    rpg->scene = OVERWORLD;
    play_music(rpg);
    return 0;
}
