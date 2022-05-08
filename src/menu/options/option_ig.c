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
    if (i == 1) {
        rpg->menu->option->keybinds = true;
        rpg->menu->option->is_main = false;
    }
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

static void do_button_music_bis_ig(rpg_t *rpg, int i)
{
    if (i == 6) {
        if (rpg->sounds->is_sound_effect == true) {
            rpg->sounds->is_sound_effect = false;
        } else {
            sfMusic_play(rpg->sounds->music);
            rpg->sounds->is_sound_effect = true;
        }
    }
    if (i == 7) {
        if (rpg->event.mouseButton.x > 930 && rpg->sounds->sound_effect < 100)
            rpg->sounds->sound_effect += 5;
        else if (rpg->event.mouseButton.x < 930 && rpg->sounds->sound_effect >
        0)
            rpg->sounds->sound_effect -= 5;
    }
    if (i == 8) {
        rpg->menu->option->is_main = true;
        rpg->menu->option->music = false;
    }
}

void do_button_music_ig(rpg_t *rpg, int i)
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
    if (i == 5) {
        if (rpg->event.mouseButton.x > 960 && rpg->sounds->sound_music < 100)
            rpg->sounds->sound_music += 5;
        else if (rpg->event.mouseButton.x < 960 && rpg->sounds->sound_music >
        0)
            rpg->sounds->sound_music -= 5;
        sfMusic_setVolume(rpg->sounds->music, rpg->sounds->sound_music);
    }
    do_button_music_bis_ig(rpg, i);
}

static void do_button_keybinding_ig(rpg_t *rpg, int i)
{
    if (i >= 9 && i < 17) {
        replace_text(rpg, i);
    }
    if (i == 17) {
        rpg->menu->option->is_main = true;
        rpg->menu->option->keybinds = false;
    }
}

void buttons_controls_option_ig(rpg_t *rpg, bt_list_t *bt_list, sfEvent event)
{
    int button;
    if (rpg->menu->option->is_active && rpg->menu->option->is_main) {
        button = detect_click_on_bt(bt_list, event, 0, 4);
        do_button_option_ig(rpg, button);
    } if (rpg->menu->option->music && rpg->menu->option->is_active) {
        option_ig_bis(rpg, button, event, bt_list);
    } if (rpg->menu->option->keybinds && rpg->menu->option->is_active) {
        button = detect_click_on_bt_2(bt_list, event, 9, 17);
        if (button == -1)
            button = detect_click_on_bt(bt_list, event, 17, 18);
        do_button_keybinding_ig(rpg, button);
    }
}
