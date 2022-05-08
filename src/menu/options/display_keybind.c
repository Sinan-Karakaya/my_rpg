/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_keybind
*/

#include "my_rpg.h"

static void parralax(rpg_t *rpg, sfVector2f actual_pos, int i)
{
    sfVector2f pos = {actual_pos.x, actual_pos.y};
    sfSprite_setPosition(BUTTONSO->lst_bt[i]->sprite, actual_pos);
    pos.x += (88);
    pos.y += 38;
    sfText_setPosition(BUTTONSO->lst_bt[i]->text, pos);
}

static void do_parralax_bis(rpg_t *rpg)
{
    sfVector2f mouse_pos;
    sfVector2f actual_pos;

    mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x
    / 5, sfMouse_getPositionRenderWindow(rpg->window).y / 5};
    actual_pos = (sfVector2f){mouse_pos.x + 960, mouse_pos.y + 100};
    parralax(rpg, actual_pos, 10);
    actual_pos.y = mouse_pos.y + 250;
    parralax(rpg, actual_pos, 12);
    actual_pos.y = mouse_pos.y + 400;
    parralax(rpg, actual_pos, 14);
    actual_pos.y = mouse_pos.y + 550;
    parralax(rpg, actual_pos, 16);
    actual_pos = (sfVector2f){mouse_pos.x + 656, mouse_pos.y + 700};
    parralax(rpg, actual_pos, 17);
    actual_pos = (sfVector2f){mouse_pos.x + 656, mouse_pos.y + 340};
    parralax(rpg, actual_pos, 18);
}

void do_parralax_keybind(rpg_t *rpg)
{
    sfVector2f mouse_pos;
    sfVector2f actual_pos;

    mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x
    / 5, sfMouse_getPositionRenderWindow(rpg->window).y / 5};
    actual_pos = (sfVector2f){mouse_pos.x + 200, mouse_pos.y + 100};
    parralax(rpg, actual_pos, 9);
    actual_pos.y = mouse_pos.y + 250;
    parralax(rpg, actual_pos, 11);
    actual_pos.y = mouse_pos.y + 400;
    parralax(rpg, actual_pos, 13);
    actual_pos.y = mouse_pos.y + 550;
    parralax(rpg, actual_pos, 15);
    do_parralax_bis(rpg);
}

void do_parralax_keyinput(rpg_t *rpg)
{
    sfVector2f mouse_pos;
    sfVector2f actual_pos;

    mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x
    / 5, sfMouse_getPositionRenderWindow(rpg->window).y / 5};
    actual_pos = (sfVector2f){mouse_pos.x + 656, mouse_pos.y + 340};
    parralax(rpg, actual_pos, 18);
}
