/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** print_inventory
*/

#include "my_rpg.h"

void print_inventory(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, INVENTORY->sprite, NULL);
    for (size_t nbline; nbline < 5; nbline++) {
        for (size_t nbcol; nbcol < 6; nbcol++) {
            if (rpg->menu->inventory);
        }
    }
}