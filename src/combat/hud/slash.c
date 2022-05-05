/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** slash file
*/

#include <stdlib.h>
#include "my_rpg.h"

int init_slash(combat_t *combat)
{
    combat->slash = malloc(sizeof(hud_t));
    if (!combat->slash)
        return 84;
    combat->slash->texture = sfTexture_createFromFile(SLASH_PATH, NULL);
    if (!combat->slash->texture)
        return 84;
    combat->slash->sprite = sfSprite_create();
    sfSprite_setTexture(combat->slash->sprite, combat->slash->texture, sfTrue);
    combat->slash->pos = combat->player->pos;
    combat->slash->pos.x -= 20, combat->slash->pos.y -= 20;
    sfSprite_setPosition(combat->slash->sprite, combat->slash->pos);
    combat->slash->rect = (sfIntRect){0, 0, SLASH_WIDTH, SLASH_HEIGHT};
    sfSprite_setTextureRect(combat->slash->sprite, combat->slash->rect);
    combat->slash->clock = sfClock_create();
    combat->slash->is_active = false;
    return 0;
}

void do_slash(combat_t *combat, sfRenderWindow *window)
{
    int type = 0;

    if (combat->slash->rect.left == 0) {
        type = rand() % 5;
        combat->slash->rect.top = type * SLASH_HEIGHT;
        sfSound_play(combat->sfx->sound);
    }
    if (get_time(combat->slash->clock) > 0.04) {
        combat->slash->rect.left += SLASH_WIDTH;
        if (combat->slash->rect.left >= SLASH_WIDTH * 6) {
            combat->slash->rect.left = 0;
            combat->slash->is_active = false;
            combat->state = RPG_COMBAT_PENDING;
        } sfSprite_setTextureRect(combat->slash->sprite, combat->slash->rect);
        sfClock_restart(combat->slash->clock);
    }
    sfRenderWindow_drawSprite(window, combat->slash->sprite, NULL);
}
