/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** keybindings bis
*/

#include <stdlib.h>

#include "my_rpg.h"

int replace_keys(rpg_t *rpg, int button, int key)
{
    if (check_all_keys(rpg, key) == 84)
        return 84;
    if (button == 9)
        rpg->keybinds->key_up = key;
    if (button == 10)
        rpg->keybinds->key_down = key;
    if (button == 11)
        rpg->keybinds->key_left = key;
    if (button == 12)
        rpg->keybinds->key_right = key;
    if (button == 13)
        rpg->keybinds->key_inventory = key;
    if (button == 14)
        rpg->keybinds->key_attack = key;
    if (button == 15)
        rpg->keybinds->key_protect = key;
    if (button == 16)
        rpg->keybinds->key_run = key;
    return 0;
}
