/*
** EPITECH PROJECT, 2022
** my
** File description:
** destroy combat
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "my.h"

void free_entity(entity_t *e)
{
    sfTexture_destroy(e->texture);
    sfSprite_destroy(e->sprite);
    sfClock_destroy(e->clock);
    if (my_strcmp(e->name, "cine") != 0 && my_strcmp(e->name, "car") != 0) {
        sfRectangleShape_destroy(e->bar->rect);
        sfRectangleShape_destroy(e->bar->rect_grey);
    }
    free(e);
}

void combat_destroy(rpg_t *rpg)
{
    sfTexture_destroy(rpg->combat->hud->texture);
    sfSprite_destroy(rpg->combat->hud->sprite);
    sfClock_destroy(rpg->combat->hud->clock);
    free(rpg->combat->hud);
    sfTexture_destroy(rpg->combat->slash->texture);
    sfSprite_destroy(rpg->combat->slash->sprite);
    sfClock_destroy(rpg->combat->slash->clock);
    free(rpg->combat->slash);
    for (size_t i = 0; i < 3; i++)
        free_entity(rpg->combat->ennemy[i]);
    free_entity(rpg->combat->player);
    sfRectangleShape_destroy(rpg->combat->transt->rect);
    sfClock_destroy(rpg->combat->transt->clock);
    sfClock_destroy(rpg->combat->delay_clock);
    sfFont_destroy(rpg->combat->game_over->font);
    sfText_destroy(rpg->combat->game_over->text);
    sfSoundBuffer_destroy(rpg->combat->sfx->buffer);
    sfSound_destroy(rpg->combat->sfx->sound);
    free(rpg->combat->sfx);
    free(rpg->combat);
}
