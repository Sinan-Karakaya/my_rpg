/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw map
*/

#include <math.h>
#include <stdlib.h>

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

static void draw_triangle(sfVector2f *points, rpg_t *game,
sfVector2i tex_pos, int i)
{
    float coordx = tex_pos.y +abs(16 * (i - 1));

    if (is_in_screen(points) == 0)
        return;
    sfVertex *vertex = sfVertexArray_getVertex(game->cam.render->triangle, 0);
    sfVertexArray *tri = game->cam.render->triangle;
    vertex[0].position = points[0];
    vertex[0].texCoords = (sfVector2f){tex_pos.x, tex_pos.y};
    vertex[0].color = sfWhite;
    vertex[1].position = points[1];
    vertex[1].color = sfWhite;
    vertex[1].texCoords = (sfVector2f){tex_pos.x + abs(16 * (i - 2)), coordx};
    vertex[2].position = points[2];
    vertex[2].color = sfWhite;
    vertex[2].texCoords = (sfVector2f){tex_pos.x + 16, tex_pos.y + 16};
    sfVertexArray_setPrimitiveType(tri, sfTriangleStrip);
    sfRenderWindow_drawVertexArray(game->window, tri, game->texture);
}

sfVector2i get_texture_pos(int x, int y, rpg_t *rpg)
{
    int nbr = rpg->world->texture_map[x][y];
    int size = sfTexture_getSize(rpg->texture->texture).x;
    int x_pos = 16 * (nbr % (size / 16));
    int y_pos = 16 * (nbr / (size / 16));
    sfVector2i quad_offset = {x_pos, y_pos};

    return quad_offset;
}

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

void draw_water(rpg_t *rpg)
{
    sfVector2f *point = rpg->cam.render->point;
    sfTime time = sfClock_getElapsedTime(rpg->world->water_clock);
    int milli_time = sfTime_asMilliseconds(time) / 70;
    int **height = rpg->world->height_map;
    sfVector3f point_3d;
    sfVector2i quad_offset = {48, 48};
    for (int i = 0; i < MAP_X + 100; i++) {
        for (int j = MAP_Y - 1; j > 0; j--) {
            if (i > 55 && i < MAP_X + 40)
                continue;;
            point_3d = (sfVector3f){i - 50,perlin(i + milli_time, j, 10) * 2, j};
            point[0] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i - 49), perlin(i + 1 + milli_time, j, 10) * 2, j};
            point[1] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i  - 49), perlin(i + 1 + milli_time, j + 1, 10) * 2, j + 1};
            point[2] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, quad_offset, 1);
            point_3d = (sfVector3f){(i - 50), perlin(i + milli_time, j + 1, 10) * 2, j + 1};
            point[1] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, quad_offset, 2);
        }
    }
}