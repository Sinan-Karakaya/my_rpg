/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu
*/

#include "my_rpg.h"

int menuloop(rpg_t *rpg)
{
    init_menu(rpg);
    sfVector2f mouse_pos;

    while (sfRenderWindow_isOpen(rpg->window)) {
        mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x / 60 - 340
        , sfMouse_getPositionRenderWindow(rpg->window).y / 60 - 200};
        sfSprite_setPosition(rpg->menu->main->far_g_sprite, mouse_pos);
        sfRenderWindow_clear(rpg->window, sfBlack);
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->main->far_g_sprite, NULL);
         mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x / 30 - 340
        , sfMouse_getPositionRenderWindow(rpg->window).y / 30 - 400};
        sfSprite_setPosition(rpg->menu->main->back_g_sprite, mouse_pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->main->back_g_sprite, NULL);
         mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x / 12 - 600
        , sfMouse_getPositionRenderWindow(rpg->window).y / 12 - 400};
        sfSprite_setPosition(rpg->menu->main->mid_g_sprite, mouse_pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->main->mid_g_sprite, NULL);
        sfRenderWindow_display(rpg->window);
        sfRenderWindow_pollEvent(rpg->window, &rpg->event);
    }
    return 0;
}