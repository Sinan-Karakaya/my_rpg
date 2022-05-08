/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"

static int change_texture_class(rpg_t *rpg, char *path, char *path_ow)
{
    rpg->combat->player->texture = sfTexture_createFromFile(path, NULL);
    if (!rpg->combat->player->texture)
        return 84;
    sfSprite_setTexture(rpg->combat->player->sprite,
    rpg->combat->player->texture, sfFalse);
    OW->texture = sfTexture_createFromFile(path_ow, NULL);
    if (!OW->texture)
        return 84;
    sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
    return 0;
}

static int change_class_texture(rpg_t *rpg)
{
    if (rpg->combat->player->stat->class == RPG_CLASS_WARRIOR) {
        if (change_texture_class(rpg, OLBERIC_WA_PATH, OLBERIC_OW_PATH))
            return 84;
    } if (rpg->combat->player->stat->class == RPG_CLASS_CLERIC) {
        if (change_texture_class(rpg, OLBERIC_CL_PATH, OLBERIC_OW_CL_PATH))
            return 84;
    } if (rpg->combat->player->stat->class == RPG_CLASS_PEASANT) {
        if (change_texture_class(rpg, OLBERIC_PE_PATH, OLBERIC_OW_PE_PATH))
            return 84;
    }
    return 0;
}

static int init_all_secondary(rpg_t *rpg)
{
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
    if (init_end(rpg))
        return error_message("Problem in the initialization of the end\n");
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
    if (init_all_secondary(rpg))
        return 84;
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
    init_cinematic(rpg);
    if (!read_save(rpg)) {
        rpg->menu->no_class = true;
    } else {
        assign_class_valid_save(rpg);
        rpg->scene = OVERWORLD;
    } rpg->texture = do_init_struct_texture("assets/environement/pr.png", rpg);
    if (!rpg->texture)
        return 84;
    if (play_music(rpg) == 84)
        return error_message("Problem in the initialization of the music\n");
    rpg->end_toggle = false;
    return 0;
}
