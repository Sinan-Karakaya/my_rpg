/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** aabb collision
*/

#include <stdlib.h>
#include "my_rpg.h"

bool do_aabb_mouse(sfMouseButtonEvent mouse, sfSprite *sp)
{
    sfIntRect r = sfSprite_getTextureRect(sp);

    return (bool)sfIntRect_contains(&r, mouse.x, mouse.y);
}

bool do_aabb_sprites(sfSprite *sp1, sfSprite *sp2)
{
    sfIntRect r1 = sfSprite_getTextureRect(sp1);
    sfIntRect r2 = sfSprite_getTextureRect(sp2);

    return (bool)sfIntRect_intersects(&r1, &r2, NULL);
}
