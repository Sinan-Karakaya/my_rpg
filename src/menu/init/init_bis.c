/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_bis
*/

#include "my_rpg.h"

static sfSprite *init_sprite(sfVector2f pos, char *filename)
{
    sfTexture *texture = sfTexture_createFromFile(
    filename, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scaling = {2, 2};

    sfSprite_setScale(sprite, scaling);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void init_inventory(rpg_t *rpg)
{
    INVENTORY->sprite =
    init_sprite((sfVector2f){300, 100}, "assets/menu/inventory.png");
}