/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "defines.h"

static int init_menu_bis(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->menu->main->back_g_sprite,
    rpg->menu->main->back_g_texture, sfTrue);
    sfSprite_setScale(rpg->menu->main->back_g_sprite, (sfVector2f){1.5, 1.5});
    rpg->menu->main->mid_g_sprite = sfSprite_create();
    rpg->menu->main->mid_g_texture = sfTexture_createFromFile(MENU_MID, NULL);
    if (!rpg->menu->main->mid_g_texture || !rpg->menu->main->mid_g_sprite)
        return 84;
    sfSprite_setTexture(rpg->menu->main->mid_g_sprite,
    rpg->menu->main->mid_g_texture, sfTrue);
    sfSprite_setScale(rpg->menu->main->mid_g_sprite, (sfVector2f){1.5, 1.5});
    rpg->menu->inventory = malloc(sizeof(menu_inventory_t));
    rpg->menu->is_main = true;
    rpg->menu->is_inventory = false;
    rpg->menu->is_option = false;
    rpg->menu->is_closed = false;
    rpg->menu->option->is_active = false;
    rpg->menu->option->music = false;
    rpg->menu->option->keybinds = false;
    rpg->menu->option->is_main = false;
    return 0;
}

int init_menu(rpg_t *rpg)
{
    if (!(rpg->menu = malloc(sizeof(menu_t))) ||
    !(rpg->menu->main = malloc(sizeof(menu_main_t))) ||
    !(rpg->menu->option = malloc(sizeof(menu_option_t))))
        return 84;
    rpg->menu->main->far_g_sprite = sfSprite_create();
    rpg->menu->main->far_g_texture = sfTexture_createFromFile(MENU_BG, NULL);
    if (!rpg->menu->main->far_g_texture || !rpg->menu->main->far_g_sprite)
        return 84;
    sfSprite_setTexture(rpg->menu->main->far_g_sprite,
    rpg->menu->main->far_g_texture, sfTrue);
    sfSprite_setScale(rpg->menu->main->far_g_sprite, (sfVector2f){6, 6});
    rpg->menu->main->back_g_sprite = sfSprite_create();
    rpg->menu->main->back_g_texture = sfTexture_createFromFile(MENU_FAR, NULL);
    if (!rpg->menu->main->back_g_texture || !rpg->menu->main->back_g_sprite)
        return 84;
    if (init_menu_bis(rpg))
        return 84;
    return 0;
}

static int init_sound(rpg_t *rpg)
{
    rpg->sounds = malloc(sizeof(music_t));
    if (!rpg->sounds)
        return 84;
    rpg->sounds->music = sfMusic_createFromFile("assets/music/vista.ogg");
    rpg->sounds->is_played = true;
    rpg->sounds->sound_music = 15;
    rpg->sounds->sound_effect = 15;
    rpg->sounds->is_sound_effect = true;
    return 0;
}

static int init_buttons(rpg_t *rpg)
{
    size_t nbr_buttons = 6;
    size_t nbr_buttons2 = 19;

    rpg->menu->main->buttons = malloc(sizeof(bt_list_t));
    rpg->menu->option->buttons = malloc(sizeof(bt_list_t));
    if (!rpg->menu->main->buttons)
        return 84;
    rpg->menu->main->buttons->nbr_bt = nbr_buttons;
    rpg->menu->main->buttons->lst_bt = malloc(sizeof(button_t *) *
    nbr_buttons);
    if (!rpg->menu->main->buttons->lst_bt)
        return 84;
    rpg->menu->option->buttons->nbr_bt = nbr_buttons2;
    rpg->menu->option->buttons->lst_bt = malloc(sizeof(button_t *) *
    nbr_buttons2);
    if (!rpg->menu->option->buttons->lst_bt)
        return 84;
    init_all_buttons(rpg);
    return 0;
}

static void init_keybind(rpg_t *rpg)
{
    rpg->keybinds = malloc(sizeof(keybind_t));
    rpg->keybinds->key_up = sfKeyZ;
    rpg->keybinds->key_down = sfKeyS;
    rpg->keybinds->key_left = sfKeyQ;
    rpg->keybinds->key_right = sfKeyD;
    rpg->keybinds->key_inventory = sfKeyI;
    rpg->keybinds->key_attack = sfKeyA;
    rpg->keybinds->key_protect = sfKeyP;
    rpg->keybinds->key_run = sfKeyR;
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
    read_save(rpg);
    rpg->texture = init_struct_texture("assets/environement/pr.png", rpg);
    rpg->scene = OVERWORLD;
    play_music(rpg);
    return 0;
}
