/*
** EPITECH PROJECT, 2022
** .c
** File description:
** test click on each buttons
*/

#include "my_rpg.h"

static void do_button_main(rpg_t *rpg, int i)
{
    if (i == 0 && rpg->menu->no_class) {
        rpg->menu->is_class = true;
        rpg->menu->is_main = false;
    } else if (i == 0 && !rpg->menu->no_class) {
        rpg->menu->is_main = false;
    } if (i == 1) {
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
        rpg->menu->is_music = true, rpg->menu->is_option = false;
    } if (i == 4) {
        if (rpg->debug_toggle)
            rpg->debug_toggle = false;
        else
            rpg->debug_toggle = true;
    } if (i == 5)
        rpg->menu->is_main = true, rpg->menu->is_option = false;
    if (i == 6) {
        rpg->menu->is_main = false, rpg->menu->is_keybind = true;
        rpg->menu->is_option = false;
    }
}

static void do_button_keybinding_menu(rpg_t *rpg, int i)
{
    if (i >= 9 && i < 17) {
        replace_text(rpg, i);
    }
    if (i == 17) {
        rpg->menu->is_option = true;
        rpg->menu->is_keybind = false;
    }
}

static void do_button_music_menu(rpg_t *rpg, bt_list_t *bt_list, sfEvent event)
{
    int button = -1;

    button = detect_click_on_bt(bt_list, event, 4, 5);
    if (button == -1)
        button = detect_click_on_bt_2(bt_list, event, 5, 6);
    if (button == -1)
        button = detect_click_on_bt(bt_list, event, 6, 7);
    if (button == -1)
        button = detect_click_on_bt_2(bt_list, event, 7, 8);
    if (button == -1)
        button = detect_click_on_bt(bt_list, event, 8, 9);
    do_button_music_menu_interact(rpg, button);
}

void buttons_controls_menu(rpg_t *rpg, bt_list_t *bt_list, sfEvent event)
{
    int button = -1;

    if (rpg->menu->is_main == true && !rpg->menu->is_option &&
    !rpg->menu->is_keybind) {
        button = detect_click_on_bt(bt_list, event, 0, 3);
        do_button_main(rpg, button);
    }
    if (rpg->menu->is_option == true) {
        button = detect_click_on_bt(bt_list, event, 3, 7);
        do_button_option(rpg, button);
    }
    if (rpg->menu->is_keybind == true) {
        button = detect_click_on_bt_2(BUTTONSO, event, 9, 17);
        if (button == -1)
            button = detect_click_on_bt(BUTTONSO, event, 17, 18);
        do_button_keybinding_menu(rpg, button);
    }
    if (rpg->menu->is_music == true)
        do_button_music_menu(rpg, BUTTONSO, event);
}
