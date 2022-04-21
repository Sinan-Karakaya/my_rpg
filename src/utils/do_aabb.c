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
    sfVector2f pos = sfSprite_getPosition(sp);
    sfIntRect r1 = sfSprite_getTextureRect(sp);

    if (pos.x + r1.width <= mouse.x && pos.x >= mouse.x + r1.width &&
        pos.y + r1.height <= mouse.y && pos.y >= mouse.y + r1.height) {
        return true;
    }
    return false;
}

bool do_aabb_sprites(sfSprite *sp1, sfSprite *sp2)
{
    sfVector2f pos1 = sfSprite_getPosition(sp1);
    sfVector2f pos2 = sfSprite_getPosition(sp2);
    sfIntRect r1 = sfSprite_getTextureRect(sp1);
    sfIntRect r2 = sfSprite_getTextureRect(sp2);

    if (pos1.x + r1.width <= pos2.x && pos1.x >= pos2.x + r2.width &&
        pos1.y + r1.height <= pos2.y && pos1.y >= pos2.y + r2.height)
        return true;
    return false;
}
