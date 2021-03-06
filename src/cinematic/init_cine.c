/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** cine
*/

#include "my_rpg.h"

#include <stdlib.h>

static int init_player_cine(rpg_t *rpg)
{
    rpg->cine->player->sprite = sfSprite_create();
    rpg->cine->player->texture = sfSprite_getTexture(rpg->overworld->spr);
    if (!rpg->cine->player->sprite || !rpg->cine->player->texture)
        return 84;
    sfSprite_setTexture(rpg->cine->player->sprite, rpg->cine->player->texture,
    sfFalse);
    rpg->cine->player->rect = rpg->overworld->rect;
    rpg->cine->player->pos = (sfVector2f){200, 800};
    sfSprite_setPosition(rpg->cine->player->sprite, rpg->cine->player->pos);
    sfSprite_setScale(rpg->cine->player->sprite, (sfVector2f){3, 3});
    rpg->cine->player->rect_left_i = 0;
    rpg->cine->player->rect_left_w = 0;
    rpg->cine->player->name = "cine";
    rpg->cine->player->stat = malloc(sizeof(stats_t));
    if (!rpg->cine->player->stat)
        return 84;
    rpg->cine->player->clock = sfClock_create();
    return 0;
}

static int init_car(rpg_t *rpg)
{
    rpg->cine->car->sprite = sfSprite_create();
    rpg->cine->car->texture = sfTexture_createFromFile(CAR_PATH, NULL);
    if (!rpg->cine->car->sprite || !rpg->cine->car->texture)
        return 84;
    sfSprite_setTexture(rpg->cine->car->sprite, rpg->cine->car->texture,
    sfFalse);
    rpg->cine->car->rect = rpg->overworld->rect;
    rpg->cine->car->pos = (sfVector2f){-220, 800};
    sfSprite_setPosition(rpg->cine->car->sprite, rpg->cine->car->pos);
    sfSprite_setScale(rpg->cine->car->sprite, (sfVector2f){3, 3});
    rpg->cine->car->name = "car";
    rpg->cine->car->stat = malloc(sizeof(stats_t));
    if (!rpg->cine->car->stat)
        return 84;
    rpg->cine->car->clock = sfClock_create();
    return 0;
}

static int init_bis(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->cine->sprite, rpg->cine->background, sfTrue);
    rpg->cine->clock = sfClock_create();
    sfSprite_setPosition(rpg->cine->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(rpg->cine->sprite, (sfVector2f){0.9, 0.95});
    rpg->cine->sfx = malloc(sizeof(sfx_t));
    if (rpg->cine->sfx == NULL)
        return 84;
    rpg->cine->sfx->sound = sfSound_create();
    if (rpg->cine->sfx->sound == NULL)
        return 84;
    rpg->cine->sfx->buffer = sfSoundBuffer_createFromFile(CAR_SFX);
    if (rpg->cine->sfx->buffer == NULL)
        return 84;
    sfSound_setBuffer(rpg->cine->sfx->sound, rpg->cine->sfx->buffer);
    sfSound_setVolume(rpg->cine->sfx->sound, 40);
    init_player_cine(rpg);
    init_car(rpg);
    return 0;
}

int init_cinematic(rpg_t *rpg)
{
    rpg->cine = malloc(sizeof(cine_t));
    if (rpg->cine == NULL)
        return 84;
    rpg->cine->player = malloc(sizeof(entity_t));
    rpg->cine->car = malloc(sizeof(entity_t));
    if (rpg->cine->player == NULL || rpg->cine->car == NULL)
        return 84;
    rpg->cine->sprite = sfSprite_create();
    rpg->cine->background = sfTexture_createFromFile(
    "assets/cinematic/road.png", NULL);
    if (rpg->cine->background == NULL || rpg->cine->sprite == NULL)
        return 84;
    if (init_bis(rpg))
        return 84;
    rpg->cine->transition = false;
    return 0;
}
