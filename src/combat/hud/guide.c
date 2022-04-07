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
    combat->hud->pos = (sfVector2f){RES_X / 1.4, RES_Y / 2 + 50};
    sfSprite_setPosition(combat->hud->sprite, combat->hud->pos);
    return 0;
}
