/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** light for map
*/

#include <math.h>
#include <stdlib.h>
#include "my_rpg.h"

int light(rpg_t *rpg ,int i, int j, int n)
{
    int **height = rpg->world->height_map;
    sfVector3f point_3d;
    sfTime time = sfClock_getElapsedTime(rpg->world->world_clock);
    float milli_time = sfTime_asMilliseconds(time) / 50;
    float cos_a = cos((float){milli_time} / 100);

    point_3d = (sfVector3f){i, height[i][j], j};
    sfShader_setVec3Uniform(rpg->texture->shader, "point1", point_3d);
    if (n == 1)
        point_3d = (sfVector3f){i + 1, height[i + 1][j], j};
    else
        point_3d = (sfVector3f){i, height[i][j + 1], j + 1};
    sfShader_setVec3Uniform(rpg->texture->shader, "point2", point_3d);
    point_3d = (sfVector3f){i + 1, height[i + 1][j + 1], j + 1};
    sfShader_setVec3Uniform(rpg->texture->shader, "point3", point_3d);
    sfShader_setVec3Uniform(rpg->texture->shader, "light_dir",
     (sfVector3f){-1,1,cos_a});
}