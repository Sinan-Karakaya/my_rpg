/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** slots_controls
*/

#include "my_rpg.h"

int slots_controls(rpg_t *rpg, sfEvent event)
{
    int button = -1;

    if (rpg->menu->is_inventory == true) {
        button = detect_click_on_inv(rpg->menu->inventory->buttons,
        event, 0, 34);
        manage_inv(rpg, button);
    }
    return 0;
}
