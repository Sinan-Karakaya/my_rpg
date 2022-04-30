/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** collision overworld
*/

#include <stdlib.h>

#include "my_rpg.h"

const sfVector2i offset_tab[] =
    {(sfVector2i){130, 170}, (sfVector2i){130, 170}, (sfVector2i){130, 170}
    , (sfVector2i){20, 280}, (sfVector2i){20, 280}};


static void check_aabb(rpg_t *rpg, sfRectangleShape *sp)
{
    if (do_aabb_sprites_rectangle(rpg->overworld->spr, sp))
        rpg->ow_can_move = false;
    else
        rpg->ow_can_move = true;
}

static void ow_aabb_bis(rpg_t *rpg, int i)
{
    sfVector2i offset = {0, 0};
    sfVector3f point_3d;
    sfVector2f *point = rpg->cam.render->point;
    sfRectangleShape *collide = sfRectangleShape_create();
    sfRectangleShape_setFillColor(collide, sfRed);
    int **height = rpg->world->height_map;

    for (int j = MAP_Y - 1; j > 0; j--) {
        if (rpg->world->object_map[i][j] == 0)
            continue;
        offset = get_object_pos(i, j, rpg);
        point_3d = (sfVector3f){i, height[i][j], j};
        point[0] = to2d(point_3d, rpg);
        point_3d = (sfVector3f){(i + 4), height[i][j], j};
        point[1] = to2d(point_3d, rpg);
        sfRectangleShape_setSize(collide, (sfVector2f){((point[1].x - point[0].x) / 150 * (offset_tab[rpg->world->object_map[i][j]].y - offset_tab[rpg->world->object_map[i][j]].x)), -(point[1].x - point[0].x) * 0.1});
        sfRectangleShape_setPosition(collide, (sfVector2f){point[0].x + ((point[1].x - point[0].x) / 150 * offset_tab[rpg->world->object_map[i][j]].x), point[0].y});
        sfRenderWindow_drawRectangleShape(rpg->window, collide, NULL);
        check_aabb(rpg, collide);
    }
    sfRectangleShape_destroy(collide);
}

void ow_aabb(rpg_t *rpg)
{
    for (int i = 1; i < MAP_X - 1; i++) {
        ow_aabb_bis(rpg, i);
    }
}