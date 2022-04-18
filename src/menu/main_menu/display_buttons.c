/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_buttons
*/

#include "my_rpg.h"

static void parralax(rpg_t *rpg, sfVector2f actual_pos, int i)
{
    sfVector2f pos = {actual_pos.x, actual_pos.y};
    sfSprite_setPosition(BUTTONS->lst_bt[i]->sprite, actual_pos);
    pos.x += (83);
    pos.y += 38;
    sfText_setPosition(BUTTONS->lst_bt[i]->text, pos);
}

void display_buttons(rpg_t *rpg)
{
    sfVector2f mouse_pos;
    sfVector2f actual_pos;

    mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x/ 5
    , sfMouse_getPositionRenderWindow(rpg->window).y / 5};
    actual_pos = (sfVector2f){mouse_pos.x + 656, mouse_pos.y + 285};
    parralax(rpg, actual_pos, 0);
    actual_pos.y = mouse_pos.y + 445;
    parralax(rpg, actual_pos, 1);
    actual_pos.y = mouse_pos.y + 600;
    parralax(rpg, actual_pos, 2);

    for (size_t i = 0; i < rpg->menu->main->buttons->nbr_bt; i++) {
        sfRenderWindow_drawSprite(rpg->window, BUTTONS->lst_bt[i]->sprite, NULL);
        sfRenderWindow_drawText(rpg->window, BUTTONS->lst_bt[i]->text, NULL);
    }
}
