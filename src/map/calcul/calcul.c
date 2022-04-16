/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** calcul map
*/

#include "my_rpg.h"

sfVector2f to2d(sfVector3f p, rpg_t *game)
{
    float x = p.x * 40;
    float y = p.y * 30 + 300;
    float z = p.z * 20;
    float y_divide;
    sfVector2f point_2d = {0,0};

    y_divide = ((y - (z -  game->cam.y) * game->cam.r) / (z - game->cam.y));
    point_2d.x = 300 * ((x - game->cam.x)/(z- game->cam.y))+960;
    point_2d.y = 300 * y_divide + 540;
    return point_2d;
}
