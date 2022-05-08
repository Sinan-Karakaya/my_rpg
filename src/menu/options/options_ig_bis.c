/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** options ig bis
*/

#include "my_rpg.h"

void option_ig_bis(rpg_t *rpg, int button, sfEvent event, bt_list_t *bt_list)
{
    button = detect_click_on_bt(bt_list, event, 4, 5);
    if (button == -1)
        button = detect_click_on_bt_2(bt_list, event, 5, 6);
    if (button == -1)
        button = detect_click_on_bt(bt_list, event, 6, 7);
    if (button == -1)
        button = detect_click_on_bt_2(bt_list, event, 7, 8);
    if (button == -1)
        button = detect_click_on_bt(bt_list, event, 8, 9);
    do_button_music_ig(rpg, button);
}
