/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** option_ig
*/

#include "my_rpg.h"
#include "my.h"

static void do_button_option_ig(rpg_t *rpg, int i)
{
    if (i == 0) {
        rpg->menu->option->music = true;
        rpg->menu->option->is_main = false;
    }
    if (i == 1)
        my_printf("Ici ce sera le KeyBindings\n");
    if (i == 2) {
        rpg->menu->is_main = true;
        rpg->menu->option->is_active = false;
        rpg->menu->option->is_main = false;
    }
    if (i == 3) {
        rpg->menu->option->is_active = false;
        rpg->menu->option->is_main = false;
    }
}

static void do_button_music_ig(rpg_t *rpg, int i)
{
    if (i == 4) {
        if (rpg->sounds->is_played == true) {
            sfMusic_pause(rpg->sounds->music);
            rpg->sounds->is_played = false;
        } else {
            sfMusic_play(rpg->sounds->music);
            rpg->sounds->is_played = true;
        }
    }
    if (i == 5)
        my_printf("Music Bar\n");
    if (i == 6) {
        my_printf("Sound Button\n");
    }
    if (i == 7)
        my_printf("Sound Effect bar\n");
    if (i == 8) {
        rpg->menu->option->is_main = true;
        rpg->menu->option->music = false;
    }
}

void buttons_controls_option_ig(rpg_t *rpg, bt_list_t *bt_list, sfEvent event)
{
    int button;

    if (rpg->menu->option->is_active == true && rpg->menu->option->is_main == true) {
        button = detect_click_on_bt(bt_list, event, 0, 4);
        do_button_option_ig(rpg, button);
    }
    if (rpg->menu->option->music == true && rpg->menu->option->is_active == true) {
        button = detect_click_on_bt(bt_list, event, 4, 9);
        do_button_music_ig(rpg, button);
    }
}
