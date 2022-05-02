/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** game over
*/

#include <stdlib.h>

#include "my_rpg.h"

static void draw_text(rpg_t *rpg)
{
    sfText *text = sfText_create();
    sfFont *font =
    sfFont_createFromFile("assets/font/itc-souvenir/Souvenir-Bold.otf");

    if (!font)
        return;
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setString(text, "GAME OVER");
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){800, 400});
    sfRenderWindow_drawText(rpg->window, text, NULL);
}

void draw_game_over(rpg_t *rpg)
{
    draw_text(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->combat->player->sprite, NULL);
}
