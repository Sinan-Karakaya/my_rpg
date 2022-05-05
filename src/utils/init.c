/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init
*/

#include <stdlib.h>
#include <stdio.h>
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

static int change_texture(rpg_t *rpg, char *path, char *path_ow)
{
    rpg->combat->player->texture = sfTexture_createFromFile(path, NULL);
    if (!rpg->combat->player->texture)
        return 84;
    sfSprite_setTexture(rpg->combat->player->sprite,
    rpg->combat->player->texture, sfFalse);
    OW->texture = sfTexture_createFromFile(path_ow, NULL);
    sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
    return 0;
}

static int change_class_texture(rpg_t *rpg)
{
    if (rpg->combat->player->stat->class == RPG_CLASS_WARRIOR) {
        if (change_texture(rpg, OLBERIC_WA_PATH, OLBERIC_OW_PATH))
            return 84;
    } if (rpg->combat->player->stat->class == RPG_CLASS_CLERIC) {
        if (change_texture(rpg, OLBERIC_CL_PATH, OLBERIC_OW_CL_PATH))
            return 84;
    } if (rpg->combat->player->stat->class == RPG_CLASS_PEASANT) {
        if (change_texture(rpg, OLBERIC_PE_PATH, OLBERIC_OW_PE_PATH))
            return 84;
    }
    return 0;
}

static int init_all_bis(rpg_t *rpg)
{
    if (change_class_texture(rpg) || load_loop(rpg, 1))
        return error_message("Problem in the initialization of the class\n");
    if (init_cam(rpg) || load_loop(rpg, 2))
        return error_message("Problem in the initialization of the camera\n");
    if (init_world(rpg) || load_loop(rpg, 3))
        return error_message("Problem in the initialization of the world\n");
    if (init_sound(rpg) || load_loop(rpg, 4))
        return error_message("Problem in the initialization of the sound\n");
    if (init_menu(rpg) || load_loop(rpg, 5))
        return error_message("Problem in the initialization of the menu\n");
    if (init_buttons(rpg) || load_loop(rpg, 6))
        return error_message("Problem in the initialization of the buttons\n");
    if (init_class_menu(rpg) || load_loop(rpg, 7))
        return error_message("Problem in the initialization of the class\n");
    if (init_keybind(rpg) || load_loop(rpg, 8))
        return error_message("Problem in the initialization of the keybind\n");
    if (init_inventory(rpg) || load_loop(rpg, 9))
        return error_message("Problem in the initialization of the INV\n");
    return 0;
}

int init_all(rpg_t *rpg)
{
    if (init_combat(rpg) == 84)
        return error_message("Problem in the initialization of the combat\n");
    if (init_player_overworld(rpg))
        return error_message("Problem in the initialization of the player\n");
    if (init_all_bis(rpg) == 84)
        return 84;
    init_player_overworld(rpg);
    change_class_texture(rpg);
    load_loop(rpg, 1);
    init_cam(rpg), load_loop(rpg, 2);
    init_world(rpg), load_loop(rpg, 3);
    // init_shaders(rpg);
    init_sound(rpg), load_loop(rpg, 4);
    init_menu(rpg), load_loop(rpg, 5);
    init_buttons(rpg), load_loop(rpg, 6);
    init_class_menu(rpg), load_loop(rpg, 7);
    init_keybind(rpg), load_loop(rpg, 8);
    init_inventory(rpg), load_loop(rpg, 9);
    init_cinematic(rpg);
    if (!read_save(rpg)) {
        rpg->menu->no_class = true;
    } else
        assign_class_valid_save(rpg);
    rpg->texture = init_struct_texture("assets/environement/pr.png", rpg);
    if (!rpg->texture)
        return 84;
    if (play_music(rpg) == 84)
        return error_message("Problem in the initialization of the music\n");
    rpg->scene = OVERWORLD;
    return 0;
}
