/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** bis
*/

#include "my_rpg.h"
#include "my.h"

void make_inventory(rpg_t *rpg, char *value)
{
    int index = 0;

    if (my_strlen(value) != 34)
        return;
    for (int i = 0; i < 34; i++) {
        if (value[i] >= '0' && value[i] <= '8') {
            INVENTORY->slots[i]->item_id = value[i] - '0';
            index++;
        } else {
            break;
        }
    }
}
