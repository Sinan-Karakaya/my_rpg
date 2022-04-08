#include "../../../include/my_rpg.h"
#include <math.h>

void draw_triangle(sfVector2f *points, rpg_t *game, sfColor color, int i)
{
    sfVertex *vertex = sfVertexArray_getVertex(game->cam.render->triangle, 0);
    sfVertexArray *tri = game->cam.render->triangle;
    vertex[0].position = points[0];
    vertex[0].texCoords = (sfVector2f){0, 0};
    vertex[0].color = color;
    vertex[1].position = points[1];
    vertex[1].color = color;
    vertex[1].texCoords = (sfVector2f){abs(16 * (i - 2)), abs(16 * (i - 1))};
    vertex[2].position = points[2];
    vertex[2].color = color;
    vertex[2].texCoords = (sfVector2f){16, 16};
    sfVertexArray_setPrimitiveType(tri, sfTriangleStrip);
    sfRenderWindow_drawVertexArray(game->window, tri, game->texture->state);
}

void draw_map(rpg_t *rpg)
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
            point_3d = (sfVector3f){(i + 1), height[i + 1][j + 1], j + 1};
            point[2] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, sfWhite, 1);
            point_3d = (sfVector3f){(i), height[i][j + 1], j + 1};
            point[1] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, sfWhite, 2);
        }
    }
}