/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_sprite
*/

#include "my_rpg.h"

sfSprite *sprite_create(char *path)
{
    sfSprite *sprite = NULL;
    sfTexture *texture = NULL;

    sprite = sfSprite_create();
    if (!sprite)
        return NULL;
    texture = sfTexture_createFromFile(path, NULL);
    if (!texture)
        return NULL;
    sfSprite_setTexture(sprite, texture, NULL);
    return sprite;
}
