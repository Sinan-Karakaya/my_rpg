/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** game over
*/

#include <stdlib.h>

#include "my_rpg.h"

int init_font(rpg_t *rpg)
{
    rpg->combat->game_over = malloc(sizeof(game_over_t));
    if (!rpg->combat->game_over)
        return 84;
    rpg->combat->game_over->text = sfText_create();
    if (!rpg->combat->game_over->text)
        return 84;
    rpg->combat->game_over->font =
    sfFont_createFromFile("assets/font/itc-souvenir/Souvenir-Bold.otf");
    if (!rpg->combat->game_over->font)
        return 84;
    sfText_setFont(rpg->combat->game_over->text, rpg->combat->game_over->font);
    sfText_setCharacterSize(rpg->combat->game_over->text, 50);
    sfText_setString(rpg->combat->game_over->text, "GAME OVER");
    sfText_setColor(rpg->combat->game_over->text, sfWhite);
    sfText_setPosition(rpg->combat->game_over->text, (sfVector2f){800, 400});
    return 0;
}

void draw_game_over(rpg_t *rpg)
{
    sfRenderWindow_drawText(rpg->window, rpg->combat->game_over->text, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->combat->player->sprite, NULL);
}
