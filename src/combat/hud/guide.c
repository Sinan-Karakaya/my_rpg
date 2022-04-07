/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** guide hud
*/

#include <stdlib.h>
#include "my_rpg.h"

int create_hud(combat_t *combat)
{
    combat->hud = malloc(sizeof(hud_t));
    if (!combat->hud)
        return 1;
    combat->hud->texture = sfTexture_createFromFile(HUD_PATH, NULL);
    if (!combat->hud->texture)
        return 1;
    combat->hud->sprite = sfSprite_create();
    sfSprite_setTexture(combat->hud->sprite, combat->hud->texture, sfTrue);
    combat->hud->pos = (sfVector2f){RES_X, RES_Y / 2 + 50};
    sfSprite_setPosition(combat->hud->sprite, combat->hud->pos);
    combat->hud->clock = sfClock_create();
    return 0;
}

void move_hud_in(hud_t *hud)
{
    float time = get_time(hud->clock);

    if (time > 0.0000001f && hud->pos.x > RES_X / 1.4) {
        hud->pos.x -= 50;
        sfSprite_setPosition(hud->sprite, hud->pos);
        sfClock_restart(hud->clock);
    }
}

void move_hud_out(hud_t *hud)
{
    float time = get_time(hud->clock);

    if (time > 0.0000001f && hud->pos.x < RES_X + 200) {
        hud->pos.x += 50;
        sfSprite_setPosition(hud->sprite, hud->pos);
        sfClock_restart(hud->clock);
    }
}