/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** cinematic
*/

#include <stdlib.h>

#include "my_rpg.h"

static void animate_cine(rpg_t *rpg)
{
    if (get_time(rpg->cine->clock) < 0.1f) {
        sfRenderWindow_drawSprite(rpg->window, CINE_PLAYER->sprite, NULL);
        return;
    } if (CINE_PLAYER->rect_left_i >= 5) {
        CINE_PLAYER->rect_left_i = 0;
        CINE_PLAYER->rect_left_w = 0;
    } else {
        CINE_PLAYER->rect_left_i++;
        CINE_PLAYER->rect_left_w++;
    } CINE_PLAYER->rect.left = player_ow_rect_l_r[CINE_PLAYER->rect_left_i];
    CINE_PLAYER->rect.width = player_ow_rect_w_r[CINE_PLAYER->rect_left_w];
    sfSprite_setTextureRect(CINE_PLAYER->sprite, CINE_PLAYER->rect);
    CINE_PLAYER->pos.x += 20;
    sfSprite_setPosition(CINE_PLAYER->sprite, CINE_PLAYER->pos);
    sfRenderWindow_drawSprite(rpg->window, CINE_PLAYER->sprite, NULL);
    sfClock_restart(rpg->cine->clock);
}

void animate_car(rpg_t *rpg)
{
    if (get_time(rpg->cine->clock) < 0.0001f) {
        sfRenderWindow_drawSprite(rpg->window, rpg->cine->car->sprite, NULL);
        return;
    } if (sfSprite_getPosition(CINE_PLAYER->sprite).x > RES_X / 2) {
        rpg->cine->car->pos.x += 20;
        sfSprite_setPosition(rpg->cine->car->sprite, rpg->cine->car->pos);
        if (sfSprite_getPosition(rpg->cine->car->sprite).x >=
        sfSprite_getPosition(CINE_PLAYER->sprite).x) {
            sfSound_play(rpg->cine->sfx->sound);
            rpg->scene = OVERWORLD;
        }
    }
    sfRenderWindow_drawSprite(rpg->window, rpg->cine->car->sprite, NULL);
}

void cinematic(rpg_t *rpg)
{
    sfVector2f car_pos = sfSprite_getPosition(rpg->cine->car->sprite);
    sfVector2f player_pos = sfSprite_getPosition(CINE_PLAYER->sprite);

    if (car_pos.x < player_pos.x) {
        sfRenderWindow_drawSprite(rpg->window, rpg->cine->sprite, NULL);
        animate_car(rpg);
        animate_cine(rpg);
    }
}
