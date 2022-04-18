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
    sfRenderWindow_display(rpg->window);
    sfRenderWindow_pollEvent(rpg->window, &rpg->event);
}

static void manage_controls(rpg_t *rpg)
{
    sfEvent event = {0};

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        if (event.type == sfEvtClosed) {
            rpg->menu->is_closed = true;
            rpg->menu->is_main = false;
            sfRenderWindow_close(rpg->window);
        }
        buttons_controls(rpg, BUTTONS, event);
    }
}

int menuloop(rpg_t *rpg)
{
    while (rpg->menu->is_main == true && rpg->menu->is_closed == false) {
        manage_controls(rpg);
        detect_click_on_bt(rpg->menu->main->buttons, rpg->event);
        if (rpg->menu->is_main == true) {
            print_menu(rpg);
            display_buttons(rpg);
            sfRenderWindow_display(rpg->window);
            sfRenderWindow_pollEvent(rpg->window, &rpg->event);
        }
        if (rpg->menu->is_option == true) {
            print_option(rpg);
        }
    }
    return 0;
}