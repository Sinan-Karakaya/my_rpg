/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw map
*/

#include "my_rpg.h"

static int is_in_screen(sfVector2f *point)
{
    for (int i = 0; i < 2; i++) {
        if (point[i].x < -400 || point[i].x > 2400 || point[i].y < -200 ||
        point[i].y > 1580)
            return 0;
    }
    return 1;
}

void draw_object(rpg_t *rpg)
{
    sfVector2f *point = rpg->cam.render->point;
    int **height = rpg->world->height_map;
    sfVector3f point_3d;

    for (int i = 1; i < MAP_X - 1; i++) {
        for (int j = MAP_Y - 1; j > 0; j--) {
            point_3d = (sfVector3f){i, height[i][j], j};
            point[0] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i + 1), height[i + 1][j], j};
            point[1] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i  + 1), height[i + 1][j + 1], j + 1};
            point[2] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i), height[i][j + 1], j + 1};
            point[1] = to2d(point_3d, rpg);
        }
    }
}