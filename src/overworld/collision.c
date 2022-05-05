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
    , (sfVector2i){20, 280}, (sfVector2i){20, 280}, (sfVector2i){20, 280},
     (sfVector2i){20, 280}, (sfVector2i){20, 280}, (sfVector2i){20, 280}
    , (sfVector2i){20, 280}, (sfVector2i){20, 280}, (sfVector2i){20, 280},};


static bool check_aabb(rpg_t *rpg, sfRectangleShape *sp)
{
    if (do_aabb_sprites_rectangle(rpg->overworld->spr, sp)) {
        rpg->ow_can_move = false;
        return true;
    }
    else {
        rpg->ow_can_move = true;
        return false;
    }
}

sfVector2f to_2d(sfVector3f p, rpg_t *game, sfVector2f off)
{
    sfVector2i pos = game->world->olberick_pos;
    float x = p.x * 40;
    float y = (p.y - 4 * fabs(game->cam.r - 2)) * 30 + 300;
    float z = p.z * 20;
    float y_divide;
    sfVector2f point_2d = {0, 0};

    y = y - game->world->height_map[pos.x][pos.y] * 30;
    y_divide = ((y - (z -  game->cam.y) * game->cam.r) / (z - game->cam.y));
    point_2d.x = 300 * ((x - game->cam.x) / (z- game->cam.y)) + 960;
    point_2d.y = 300 * y_divide + 540;
    if ((z - game->cam.y) < 0 && point_2d.y > 0) {
        point_2d.x = 0;
        point_2d.y = 0;
    }
    point_2d.x += off.x;
    point_2d.y += off.y;
    return point_2d;
}


static int ow_aabb_bis(rpg_t *rpg, int i, sfVector2f set)
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
        point[0] = to_2d(point_3d, rpg, set);
        point_3d = (sfVector3f){(i + 4), height[i][j], j};
        point[1] = to_2d(point_3d, rpg, set);
        sfRectangleShape_setSize(collide, CALCUL_1(x, y, i, j);
        sfRectangleShape_setPosition(collide, CALCUL_2(x, y, i, j);
        if (rpg->debug_toggle)
            sfRenderWindow_drawRectangleShape(rpg->window, collide, NULL);
        if (check_aabb(rpg, collide)) {
            sfRectangleShape_destroy(collide);
            return 1;
        }
    }
    sfRectangleShape_destroy(collide);
    return 0;
}

int ow_aabb(rpg_t *rpg, sfVector2f offset)
{
    for (int i = 1; i < MAP_X - 1; i++) {
        if (ow_aabb_bis(rpg, i, offset) == 1)
            return 1;
    }
    return 0;
}