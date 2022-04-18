/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init
*/

#include "my_rpg.h"
#include <stdlib.h>

int init_menu(rpg_t *rpg)
{
    rpg->menu = malloc(sizeof(menu_t));
    rpg->menu->main = malloc(sizeof(menu_main_t));
    rpg->menu->option = malloc(sizeof(menu_option_t));
    rpg->menu->main->far_g_sprite = sfSprite_create();
    rpg->menu->main->far_g_texture = sfTexture_createFromFile("assets/menu/background.png", NULL);
    if (!rpg->menu->main->far_g_texture || !rpg->menu->main->far_g_sprite)
        return 84;
    sfSprite_setTexture(rpg->menu->main->far_g_sprite, rpg->menu->main->far_g_texture, sfTrue);
    sfSprite_setScale(rpg->menu->main->far_g_sprite, (sfVector2f){6, 6});
    rpg->menu->main->back_g_sprite = sfSprite_create();
    rpg->menu->main->back_g_texture = sfTexture_createFromFile("assets/menu/farground.png", NULL);
    if (!rpg->menu->main->back_g_texture || !rpg->menu->main->back_g_sprite)
        return 84;
    sfSprite_setTexture(rpg->menu->main->back_g_sprite, rpg->menu->main->back_g_texture, sfTrue);
    sfSprite_setScale(rpg->menu->main->back_g_sprite, (sfVector2f){1.5, 1.5});
    rpg->menu->main->mid_g_sprite = sfSprite_create();
    rpg->menu->main->mid_g_texture = sfTexture_createFromFile("assets/menu/midground.png", NULL);
    if (!rpg->menu->main->mid_g_texture || !rpg->menu->main->mid_g_sprite)
        return 84;
    sfSprite_setTexture(rpg->menu->main->mid_g_sprite, rpg->menu->main->mid_g_texture, sfTrue);
    sfSprite_setScale(rpg->menu->main->mid_g_sprite, (sfVector2f){1.5, 1.5});
    rpg->menu->is_main = true;
    rpg->menu->is_option = false;
    rpg->menu->is_closed = false;
}

static int init_sound(rpg_t *rpg)
{
    rpg->sounds = malloc(sizeof(music_t));
    if (!rpg->sounds)
        return 84;
    rpg->sounds->music = sfMusic_createFromFile("assets/music/vista.ogg");
    return 0;
}

static int init_buttons(rpg_t *rpg)
{
    size_t nbr_buttons = 3;

    rpg->menu->main->buttons = malloc(sizeof(bt_list_t));
    if (!rpg->menu->main->buttons)
        return 84;
    rpg->menu->main->buttons->nbr_bt = nbr_buttons;
    rpg->menu->main->buttons->lst_bt = malloc(sizeof(button_t *) * nbr_buttons);
    if (!rpg->menu->main->buttons->lst_bt)
        return 84;
    init_all_buttons(rpg);
}

int init_all(rpg_t *rpg)
{
    rpg->combat = init_combat();
    init_cam(rpg);
    init_world(rpg);
    init_shaders(rpg);
    init_sound(rpg);
    init_menu(rpg);
    init_buttons(rpg);
    rpg->texture = init_struct_texture("assets/environement/pr.png", rpg);
    play_music(rpg);
}