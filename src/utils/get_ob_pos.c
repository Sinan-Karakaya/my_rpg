/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get olberick case
*/

#include "my_rpg.h"
#include "defines.h"

static float sign (sfVector2f p1, sfVector2f p2, sfVector2f p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

static int is_in_screen(sfVector2f *point)
{
    for (int i = 0; i < 2; i++) {
        if (point[i].x < -1550 || point[i].x > 2850 || point[i].y < -200 ||
        point[i].y > 1780 || (point[i].x == 0 && point[i].y == 0))
            return 0;
    }
    return 1;
}

static bool point_triangl (sfVector2f pt, sfVector2f v1, sfVector2f v2,
 sfVector2f v3)
{
    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

static void in_triangle(int i, int j, rpg_t *rpg)
{
    sfVector3f point_3d;
    sfVector2f *point = rpg->cam.render->point;
    int **height = rpg->world->height_map;
    sfVector2f pos = {1040, 565};
    point_3d = (sfVector3f){i, height[i][j], j};
    point[0] = to2d(point_3d, rpg);
    point_3d = (sfVector3f){(i + 1), height[i + 1][j], j};
    point[1] = to2d(point_3d, rpg);
    point_3d = (sfVector3f){(i  + 1), height[i + 1][j + 1], j + 1};
    point[2] = to2d(point_3d, rpg);
    if (point_triangl(pos, point[0], point[1], point[2]) == 1)
        if (is_in_screen(point) == 1)
            rpg->world->olberick_pos = (sfVector2i){i, j};
    point_3d = (sfVector3f){(i), height[i][j + 1], j + 1};
    point[1] = to2d(point_3d, rpg);
    if (point_triangl(pos, point[0], point[1], point[2]) == 1)
        if (is_in_screen(point) == 1)
            rpg->world->olberick_pos = (sfVector2i){i, j};
}

void get_olb_pos(int i, int j, rpg_t *rpg)
{
    in_triangle(i, j, rpg);
}
