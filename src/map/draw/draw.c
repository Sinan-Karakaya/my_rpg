#include "../../../include/my_rpg.h"

void draw_triangle(sfVector2f *points, rpg_t *game, sfColor color)
{
    sfVertex vertex1;
    sfVertex vertex2;
    sfVertex vertex3;
    sfVertexArray *triangle = sfVertexArray_create();
    vertex1 = (sfVertex){.position = points[0], .color = sfWhite};
    vertex2 = (sfVertex){.position = points[1], .color = sfWhite};
    vertex3 = (sfVertex){.position = points[2], .color = sfWhite};
    sfVertexArray_append(triangle, vertex1);
    sfVertexArray_append(triangle, vertex2);
    sfVertexArray_append(triangle, vertex3);
    sfVertexArray_setPrimitiveType(triangle, sfTriangles);
    sfRenderWindow_drawVertexArray(game->window, triangle, NULL);
    sfVertexArray_destroy(triangle);
}
void draw_map(rpg_t *rpg)
{
    sfVector2f *point = rpg->cam.render->point;
    sfVector3f point_3d;

    for (int i = 1; i < MAP_X - 1; i++) {
        for (int j = 1; j < MAP_Y - 1; j++) {
            point_3d = (sfVector3f){i, rpg->world->height_map[i][j], j};
            point[0] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i + 1), rpg->world->height_map[i + 1][j], j};
            point[1] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i + 1), rpg->world->height_map[i + 1][j + 1], j + 1};
            point[2] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, sfWhite);
            point_3d = (sfVector3f){(i), rpg->world->height_map[i][j + 1], j + 1};
            point[1] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, sfWhite);
        }
    }
}