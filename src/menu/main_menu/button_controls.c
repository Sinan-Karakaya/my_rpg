/*
** EPITECH PROJECT, 2022
** button_controls.c
** File description:
** test click on each buttons
*/

#include "my_rpg.h"

static void do_with_button(rpg_t *rpg, int i)
{
    if (i == 0)
        rpg->menu->is_main = false;
    if (i == 1)
        rpg->menu->is_option = true;
    if (i == 2) {
        rpg->menu->is_closed = true;
        rpg->menu->is_main = false;
        sfRenderWindow_close(rpg->window);
    }
}

void buttons_controls(rpg_t *rpg, bt_list_t *bt_list, sfEvent event)
{
    int button = detect_click_on_bt(bt_list, event);

    if (button != -1) {
        do_with_button(rpg, button);
    }
}
