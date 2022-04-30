/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** light for map
*/

#include <math.h>
#include <stdlib.h>
#include "my_rpg.h"

static sfVector3f GetNormal(sfVector3f p1, sfVector3f p2, sfVector3f p3)
{
    sfVector3f normal;
    normal.x = (p2.y - p1.y) * (p3.z - p1.z) - (p2.z - p1.z) * (p3.y - p1.y);
    normal.y = (p2.z - p1.z) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.z - p1.z);
    normal.z = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    normal.y = fabs(normal.y);
    return normal;
}

int light(rpg_t *rpg , int i, int j, int n)
{
    if (IS_SHADER == 0)
        return 0;
    sfVector3f point_3d1;
    sfVector3f point_3d2;
    sfVector3f point_3d3;
    sfVector3f normal;
    sfTime time = sfClock_getElapsedTime(rpg->world->world_clock);
    float milli_time = sfTime_asMilliseconds(time) / 50;
    float cos_a = cos((float){milli_time} / 100);

    point_3d1 = (sfVector3f){i, HEIGHT[i][j], j};
    if (n == 1)
        point_3d2 = (sfVector3f){i + 1, HEIGHT[i + 1][j], j};
    else
        point_3d2 = (sfVector3f){i, HEIGHT[i][j + 1], j + 1};
    point_3d3 = (sfVector3f){i + 1, HEIGHT[i + 1][j + 1], j + 1};
    normal = GetNormal(point_3d1, point_3d2, point_3d3);
    sfShader_setVec3Uniform(rpg->texture->shader, "normal", normal);
    sfShader_setVec3Uniform(rpg->texture->shader, "light_dir"
    , (sfVector3f){-1, 1, cos_a});
}
