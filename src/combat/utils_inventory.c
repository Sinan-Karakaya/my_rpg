/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add to inventory
*/

#include <stdlib.h>

#include "my_rpg.h"

static int random_item(void)
{
    int rand_num = rand() % 100;

    if (rand_num < 30)
        return rand() % 7 + 1;
    return 0;
}

void add_to_inventory(rpg_t *rpg)
{
    for (size_t i = 0; i < 34; i++) {
        if (INVENTORY->slots[i]->item_id == 0) {
            INVENTORY->slots[i]->item_id = random_item();
            break;
        }
    }
}
