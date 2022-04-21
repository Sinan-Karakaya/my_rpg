/*
** EPITECH PROJECT, 2022
** button_controls.c
** File description:
** test click on each buttons
*/

#include "my_rpg.h"

static void do_button_main(rpg_t *rpg, int i)
{
    if (i == 0) {
        rpg->menu->is_main = false;
    }
    if (i == 1) {
        rpg->menu->is_option = true;
        rpg->menu->is_main = false;
    }
    if (i == 2) {
        rpg->menu->is_closed = true;
        rpg->menu->is_main = false;
        sfRenderWindow_close(rpg->window);
    }
}

static void do_button_option(rpg_t *rpg, int i)
{
    if (i == 3) {
        if (rpg->sounds->is_played== true) {
            sfMusic_pause(rpg->sounds->music);
            rpg->sounds->is_played = false;
        } else {
            sfMusic_play(rpg->sounds->music);
            rpg->sounds->is_played = true;
        }
    }
    if (i == 4) {
        if (rpg->debug_toggle == true)
            rpg->debug_toggle = false;
        else
            rpg->debug_toggle = true;
    }
    if (i == 5) {
        rpg->menu->is_main = true;
        rpg->menu->is_option = false;
    }
}

void buttons_controls_menu(rpg_t *rpg, bt_list_t *bt_list, sfEvent event)
{
    int button;

    if (rpg->menu->is_main == true) {
        button = detect_click_on_bt(bt_list, event, 0, 3);
        do_button_main(rpg, button);
    }
    if (rpg->menu->is_option == true) {
        button = detect_click_on_bt(bt_list, event, 3, 6);
        do_button_option(rpg, button);
    }
}
