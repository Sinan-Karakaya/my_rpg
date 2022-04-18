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
    if (!(rpg->menu = malloc(sizeof(menu_t))) ||
    !(rpg->menu->main = malloc(sizeof(menu_main_t))) ||
    !(rpg->menu->option = malloc(sizeof(menu_option_t))))
        return 84;
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
    return 0;
}
