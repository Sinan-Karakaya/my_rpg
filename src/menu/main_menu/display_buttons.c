/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_buttons
*/

#include "my_rpg.h"

void display_buttons(rpg_t *rpg)
{
    for (size_t i = 0; i < rpg->menu->main->buttons->nbr_bt; i++) {
        sfRenderWindow_drawSprite(rpg->window, BUTTONS->lst_bt[i]->sprite, NULL);
        sfRenderWindow_drawText(rpg->window, BUTTONS->lst_bt[i]->text, NULL);
    }
}
