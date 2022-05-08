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
, "Find the village."
, "Kill monsters in the forest."
, "Test4"
, "Test5"};

static sfText *init_npc_quest(void)
{
    sfText *text = sfText_create();
    sfVector2f pos = {1700, 10};

    if (!text)
        return NULL;
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 4.);
    sfText_setCharacterSize(text, 40);

    sfText_setPosition(text, pos);
    return text;
}
static sfText *init_npc_side_quest(void)
{
    sfText *text = sfText_create();
    sfVector2f pos = {1650, 80};

    if (!text)
        return NULL;
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 4.);
    sfText_setCharacterSize(text, 20);

    sfText_setPosition(text, pos);
    return text;
}

void draw_quest_list(rpg_t *rpg)
{
    sfText *text = sfText_create();
    sfText *side_text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/pnj/alagard.ttf");

    if (!text || !side_text || !font)
        return;
    text = init_npc_quest();
    sfText_setFont(text, font);
    sfText_setString(text, "Quest");
    side_text = init_npc_side_quest();
    sfText_setFont(side_text, font);
    sfText_setString(side_text, quest_line[rpg->world->gui.actual_quest]);
    sfRenderWindow_drawText(rpg->window, text, NULL);
    sfRenderWindow_drawText(rpg->window, side_text, NULL);
    sfFont_destroy(font);
    sfText_destroy(side_text);
    sfText_destroy(text);
}
