/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** cam bounds
*/

#include "my_rpg.h"

bool cam_is_in_bounds(float x, float y)
{
    if (x < 5920 && x > 85 && y > -100 && y < 1450)
        return true;
    return false;
}

bool cmb_is_in_bounds(camera_t cam)
{
    if (cam.x < 5920 && cam.x > 4115 && cam.y > 1224 && cam.y < 1450)
        return false;
    return true;
}
