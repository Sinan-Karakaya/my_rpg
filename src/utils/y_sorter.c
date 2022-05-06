/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** y sorter
*/

#include <stdlib.h>

#include "my_rpg.h"

static void y_sorter_bis(rpg_t *rpg, sfSprite *sp, int i)
{
    sfVector2i offset = {0, 0};
    sfVector3f point_3d;
    sfVector2f *point = rpg->cam.render->point;
    sfTime time = sfClock_getElapsedTime(rpg->world->world_clock);
    int milli_time = sfTime_asMilliseconds(time) / 500;
    int frame = milli_time %
    (sfTexture_getSize(rpg->world->texture_o->texture).y / 300) + 1;
    for (int j = MAP_Y - 1; j > 0; j--) {
        if (rpg->world->object_map[i][j] == 0)
            continue;
        offset = get_object_pos(i, j, rpg);
        point_3d = (sfVector3f){i, HEIGHT[i][j], j};
        point[0] = to2d(point_3d, rpg);
        point_3d = (sfVector3f){(i + 4), HEIGHT[i][j], j};
        point[1] = to2d(point_3d, rpg);
        sfSprite_setTextureRect(sp, (sfIntRect){offset.x - 300, offset.y +
        300 * frame, 300, -300});
        sfSprite_setPosition(sp, point[0]);
        sfSprite_setScale(sp, (sfVector2f){(point[1].x - point[0].x) /
        150, -(point[1].x - point[0].x) / 150});
        if (point[0].y > 540)
            sfRenderWindow_drawSprite(rpg->window, sp, NULL);
    }
}

void y_sorter(rpg_t *rpg)
{
    sfRectangleShape *bat = sfRectangleShape_create();
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, rpg->world->texture_o->texture, sfTrue);
    for (int i = 1; i < MAP_X - 1; i++) {
        y_sorter_bis(rpg, sprite, i);
    }
    sfRectangleShape_destroy(bat);
    sfSprite_destroy(sprite);
}
