/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init
*/

#include "my_rpg.h"

int init_menu(rpg_t *rpg)
{
    rpg->menu = malloc(sizeof(menu_t));
    rpg->menu->far_g_sprite = sfSprite_create();
    rpg->menu->far_g_texture = sfTexture_createFromFile("assets/menu/background.png", NULL);
    if (!rpg->menu->far_g_texture || !rpg->menu->far_g_sprite)
        return 84;
    sfSprite_setTexture(rpg->menu->far_g_sprite, rpg->menu->far_g_texture, sfTrue);
    sfSprite_setScale(rpg->menu->far_g_sprite, (sfVector2f){6, 6});

    rpg->menu->back_g_sprite = sfSprite_create();
    rpg->menu->back_g_texture = sfTexture_createFromFile("assets/menu/farground.png", NULL);
    if (!rpg->menu->back_g_texture || !rpg->menu->back_g_sprite)
        return 84;
    sfSprite_setTexture(rpg->menu->back_g_sprite, rpg->menu->back_g_texture, sfTrue);
    sfSprite_setScale(rpg->menu->back_g_sprite, (sfVector2f){1.5, 1.5});

    rpg->menu->mid_g_sprite = sfSprite_create();
    rpg->menu->mid_g_texture = sfTexture_createFromFile("assets/menu/midground.png", NULL);
    if (!rpg->menu->mid_g_texture || !rpg->menu->mid_g_sprite)
        return 84;
    sfSprite_setTexture(rpg->menu->mid_g_sprite, rpg->menu->mid_g_texture, sfTrue);
    sfSprite_setScale(rpg->menu->mid_g_sprite, (sfVector2f){1.5, 1.5});
}