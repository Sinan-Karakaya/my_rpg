/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** weather file
*/

#include "my_rpg.h"

void create_weather(rpg_t *rpg)
{
    rpg->world->drop = malloc(sizeof(sfRectangleShape) * NB_DROP + 1);

    if (rpg->world->drop == NULL)
        return;
    for (int i = 0; i < NB_DROP; i++) {
        rpg->world->drop[i] = sfRectangleShape_create()
        rpg->world->drop[i].size.x = DROP_SIZE;
        rpg->world->drop[i].size.y = DROP_SIZE;
        rpg->world->drop[i].position.x = rand() % (WINDOW_WIDTH - DROP_SIZE);
        rpg->world->drop[i].position.y = rand() % (WINDOW_HEIGHT - DROP_SIZE);
        rpg->world->drop[i].fill_color = sfColor_fromRGBA(255, 255, 255, 255);
        rpg->world->drop[i].outline_color = sfColor_fromRGBA(0, 0, 0, 255);
        rpg->world->drop[i].outline_thickness = 1;
    }
}

void draw_weather(rpg_t *rpg)
{
    for (int i = 0; i < NB_DROP; i++) {
        sfRectangleShape_setPosition(rpg->world->drop[i],
        sfRectangleShape_getPosition(rpg->world->drop[i]));
        sfRenderWindow_drawRectangleShape(rpg->window,
        rpg->world->drop[i], NULL);
    }
}
