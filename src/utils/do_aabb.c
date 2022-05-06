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

bool do_aabb_mouse_rect(sfMouseButtonEvent mouse, sfIntRect rect)
{
    return (bool)sfIntRect_contains(&rect, mouse.x, mouse.y);
}

bool do_aabb_sprites(sfSprite *sp1, sfSprite *sp2)
{
    sfVector2f pos1 = sfSprite_getPosition(sp1);
    sfVector2f pos2 = sfSprite_getPosition(sp2);
    sfIntRect r1 = sfSprite_getTextureRect(sp1);
    sfIntRect r2 = sfSprite_getTextureRect(sp2);

    if (r2.height < 0)
        r2.height *= -1;

    if (pos1.x < pos2.x + r2.width &&
    pos1.x + r1.width > pos2.x &&
    pos1.y < pos2.y + r2.height &&
    pos1.y + r1.height > pos2.y)
        return true;
    return false;
}

bool do_aabb_sprites_rectangle(sfSprite *sp1, sfRectangleShape *sp2)
{
    sfVector2f pos1 = sfSprite_getPosition(sp1);
    sfVector2f pos2 = sfRectangleShape_getPosition(sp2);
    sfIntRect r1 = sfSprite_getTextureRect(sp1);
    sfVector2f r2 = sfRectangleShape_getSize(sp2);

    if (r2.y < (float)0)
        r2.y *= (float)-1;
    if (pos1.x < pos2.x + (float)r2.x &&
    pos1.x + r1.width > pos2.x &&
    pos1.y < pos2.y + (float)r2.y &&
    pos1.y + r1.height > pos2.y) {
        return true;
    }
    return false;
}
