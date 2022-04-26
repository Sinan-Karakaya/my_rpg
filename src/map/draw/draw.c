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
        if (point[i].x < -1550 || point[i].x > 2850 || point[i].y < -200 ||
        point[i].y > 1780)
            return 0;
    }
    return 1;
}

void draw_triangle(sfVector2f *points, rpg_t *game,
sfVector2i tex_pos, int i)
{
    float coordx = tex_pos.y +abs(16 * (i - 2));

    if (is_in_screen(points) == 0)
        return;
    sfVertex *vertex = sfVertexArray_getVertex(game->cam.render->triangle, 0);
    sfVertexArray *tri = game->cam.render->triangle;
    vertex[0].position = points[0];
    vertex[0].texCoords = (sfVector2f){tex_pos.x, tex_pos.y};
    vertex[0].color = sfWhite;
    vertex[1].position = points[1];
    vertex[1].color = sfWhite;
    vertex[1].texCoords = (sfVector2f){tex_pos.x + abs(16 * (i - 1)), coordx};
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

static void draw_water_bis(rpg_t *rpg, int mt, int i, sfVector3f pnt_3d)
{
    sfVector2f *point = rpg->cam.render->point;
    int x_pos = 16 * (22 % (sfTexture_getSize(rpg->texture->texture).x / 16));
    int y_pos = 16 * (22 / (sfTexture_getSize(rpg->texture->texture).x / 16));
    sfVector2i quad_offset = {x_pos, y_pos};

    for (int j = MAP_Y - 1; j > 0; j--) {
        if (i > 55 && i < MAP_X + 40)
            continue;
        pnt_3d = (sfVector3f){i - 50,perlin(i + mt, j, 10) * 2, j};
        point[0] = to2d(pnt_3d, rpg);
        pnt_3d = (sfVector3f){(i - 49), perlin(i + 1 + mt, j, 10) * 2, j};
        point[1] = to2d(pnt_3d, rpg);
        pnt_3d = (sfVector3f){(i  - 49), perlin(i + 1 + mt, j + 1, 10) * 2, j
        + 1};
        point[2] = to2d(pnt_3d, rpg);
        draw_triangle(point, rpg, quad_offset, 1);
        pnt_3d = (sfVector3f){(i - 50), perlin(i + mt, j + 1, 10) * 2, j + 1};
        point[1] = to2d(pnt_3d, rpg);
        draw_triangle(point, rpg, quad_offset, 2);
    }
}

void draw_water(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->world->world_clock);
    int milli_time = sfTime_asMilliseconds(time) / 70;
    sfVector3f pnt_3d = (sfVector3f){0, 0, 0};
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->main->far_g_sprite,
    NULL);
    for (int i = 0; i < MAP_X + 100; i++) {
        draw_water_bis(rpg, milli_time, i, pnt_3d);
    }
}
