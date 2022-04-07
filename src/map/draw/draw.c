#include "../../../include/my_rpg.h"

void draw_triangle(sfVector2f *points, rpg_t *game, sfColor color)
{
    sfVertex *vertex = sfVertexArray_getVertex(game->cam.render->triangle, 0);

    vertex[0].position = points[0];
    vertex[0].color = color;
    vertex[1].position = points[1];
    vertex[1].color = color;
    vertex[2].position = points[2];
    vertex[2].color = color;
    sfVertexArray_setPrimitiveType(game->cam.render->triangle, sfTriangles);
    sfRenderWindow_drawVertexArray(game->window, game->cam.render->triangle, NULL);
}

void draw_map(rpg_t *rpg)
{
    sfVector2f *point = rpg->cam.render->point;
    sfVector3f point_3d;

    for (int i = 1; i < MAP_X - 1; i++) {
        for (int j = 1; j < MAP_Y - 1; j++) {
            point_3d = (sfVector3f){i, rpg->world->height_map[i][j], j};
            rpg->cam.render->point[0] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i + 1), rpg->world->height_map[i + 1][j], j};
            rpg->cam.render->point[1] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i + 1), rpg->world->height_map[i + 1][j + 1], j + 1};
            rpg->cam.render->point[2] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, sfWhite);
            point_3d = (sfVector3f){(i), rpg->world->height_map[i][j + 1], j + 1};
            rpg->cam.render->point[1] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, sfWhite);
        }
    }
}