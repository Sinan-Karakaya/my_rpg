/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw bis
*/

#include "my_rpg.h"

void draw_map(rpg_t *rpg)
{
    sfVector2f *point = rpg->cam.render->point;
    int **height = rpg->world->height_map;
    sfVector3f point_3d;
    sfVector2i quad_offset = {0, 0};

    for (int i = 1; i < MAP_X - 1; i++) {
        for (int j = MAP_Y - 1; j > 0; j--) {
            quad_offset = get_texture_pos(i, j, rpg);
            point_3d = (sfVector3f){i, height[i][j], j};
            point[0] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i + 1), height[i + 1][j], j};
            point[1] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i  + 1), height[i + 1][j + 1], j + 1};
            point[2] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, quad_offset, 1);
            point_3d = (sfVector3f){(i), height[i][j + 1], j + 1};
            point[1] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, quad_offset, 2);
        }
    }
}
