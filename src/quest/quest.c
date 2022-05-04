/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** loop file
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"

const char *quest_line[] = {""
, "Trouver la village."
, "Trouver la foret"
, "Test4"
, "Test5"};

static sfText *init_npc_quest(rpg_t *rpg)
{
    sfFont *font = sfFont_createFromFile("assets/pnj/alagard.ttf");
    sfText *text = sfText_create();
    sfVector2f origin = {0};
    sfFloatRect rect = {0};
    sfVector2f pos = {1700, 10};

    sfText_setPosition(text, pos);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 4.);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);

    sfText_setPosition(text, pos);
    return text;
}
static sfText *init_npc_side_quest(rpg_t *rpg)
{
    sfFont *font = sfFont_createFromFile("assets/pnj/alagard.ttf");
    sfText *text = sfText_create();
    sfVector2f origin = {0};
    sfFloatRect rect = {0};
    sfVector2f pos = {1650, 80};

    sfText_setPosition(text, pos);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 4.);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);

    sfText_setPosition(text, pos);
    return text;
}

void draw_quest_list(rpg_t *rpg)
{
    sfText *text = sfText_create();
    text = init_npc_quest(rpg);
    sfText_setString(text, "Quest");
    sfText *side_text = sfText_create();
    side_text = init_npc_side_quest(rpg);
    sfText_setString(side_text, quest_line[rpg->world->gui.actual_quest]);
    sfRenderWindow_drawText(rpg->window, text, NULL);
    sfRenderWindow_drawText(rpg->window, side_text, NULL);
    sfFont_destroy(sfText_getFont(text));
    sfFont_destroy(sfText_getFont(side_text));
    sfText_destroy(side_text);
    sfText_destroy(text);

}