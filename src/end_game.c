/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** end game
*/

#include <stdlib.h>

#include "my_rpg.h"

int init_end(rpg_t *rpg)
{
    rpg->end = malloc(sizeof(end_t));
    if (!rpg->end)
        return 84;
    rpg->end->font = sfFont_createFromFile(FONT_PATH);
    rpg->end->text = sfText_create();
    if (!rpg->end->font || !rpg->end->text)
        return 84;
    sfText_setFont(rpg->end->text, rpg->end->font);
    sfText_setCharacterSize(rpg->end->text, 40);
    sfText_setString(rpg->end->text, "\tCongratulation!\nYou beat the game!");
    sfText_setPosition(rpg->end->text, (sfVector2f){RES_X / 2 - 240,
    RES_Y / 2 - 90});
    sfText_setFillColor(rpg->end->text, sfColor_fromRGBA(255, 255, 255, 0));
    return 0;
}

void end_game(rpg_t *rpg)
{
    sfColor color = sfRectangleShape_getFillColor(rpg->combat->transt->rect);
    sfColor color_bis = sfText_getFillColor(rpg->end->text);

    if (color.a < 255) {
        color.a += 5;
        color_bis.a += 5;
    }
    sfRectangleShape_setFillColor(rpg->combat->transt->rect, color);
    sfText_setFillColor(rpg->end->text, color_bis);
}
