/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu
*/

#include "my_rpg.h"

static void print_menu(rpg_t *rpg)
{
    sfVector2f mouse_pos;

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
}

static void print_option(rpg_t *rpg)
{
    sfVector2f mouse_pos;

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
}

static int manage_controls(rpg_t *rpg)
{
    sfEvent event = {0};

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        if (event.type == sfEvtClosed) {
            rpg->menu->is_closed = true;
            rpg->menu->is_main = false;
            rpg->menu->is_option = false;
            sfRenderWindow_close(rpg->window);
            return 1;
        }
        if (event.type == sfEvtMouseButtonPressed) {
            buttons_controls_menu(rpg, BUTTONS, event);
        }
    }
}

int menuloop(rpg_t *rpg)
{
    while ((rpg->menu->is_main == true  && sfRenderWindow_isOpen(rpg->window)
    || (rpg->menu->is_option == true) && sfRenderWindow_isOpen(rpg->window))) {
        if (manage_controls(rpg) == 1)
            return 1;
        if (rpg->menu->is_main == true && rpg->menu->is_option == false) {
            print_menu(rpg);
            display_buttons_main(rpg);
            sfRenderWindow_display(rpg->window);
        }
        if (rpg->menu->is_option == true && rpg->menu->is_main == false) {
            print_option(rpg);
            display_buttons_option(rpg);
            sfRenderWindow_display(rpg->window);
        }
    }
    return 0;
}
