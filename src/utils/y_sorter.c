/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** y sorter
*/

#include <stdlib.h>

#include "my_rpg.h"

void check_y(rpg_t *rpg, sfSprite *sp, float p_y)
{
    sfVector2f pos = sfSprite_getPosition(sp);
    sfIntRect rect = sfSprite_getTextureRect(sp);

    pos.y += rect.height * 0.8;
    if (pos.y > 315)
        sfRenderWindow_drawSprite(rpg->window, sp, NULL);
}

static void y_sorter_bis(rpg_t *rpg, float p_y, sfSprite *sp, int i)
{
    sfVector2i offset = {0, 0};
    sfVector3f point_3d;
    sfVector2f *point = rpg->cam.render->point;

    for (int j = MAP_Y - 1; j > 0; j--) {
        if (rpg->world->object_map[i][j] == 0)
            continue;
        offset = get_object_pos(i, j, rpg);
        point_3d = (sfVector3f){i, rpg->world->height_map[i][j], j};
        point[0] = to2d(point_3d, rpg);
        point_3d = (sfVector3f){(i + 4), rpg->world->height_map[i][j], j};
        point[1] = to2d(point_3d, rpg);
        sfSprite_setTextureRect(sp, (sfIntRect){offset.x - 300, offset.y +
        300, 300, -300});
        sfSprite_setPosition(sp, point[0]);
        sfSprite_setScale(sp, (sfVector2f){(point[1].x - point[0].x) /
        150, -(point[1].x - point[0].x) / 150});
        check_y(rpg, sp, p_y);
    }
}

void y_sorter(rpg_t *rpg, float player_y)
{
    sfRectangleShape *bat = sfRectangleShape_create();
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, rpg->world->texture_o->texture, sfTrue);
    for (int i = 1; i < MAP_X - 1; i++) {
        y_sorter_bis(rpg, player_y, sprite, i);
    }
    sfRectangleShape_destroy(bat);
    sfSprite_destroy(sprite);
}
