#include "../../../include/my_rpg.h"

sfVector2f to2d(sfVector3f p, rpg_t *game)
{
    float x = p.x * 80;
    float y = p.y * 20 + 300;
    float z = p.z * 20;
    float y_divide_by_z;
    sfVector2f point_2d = {0,0};

    y_divide_by_z = ((y - (z -  game->cam.y) * 1.5) / (z - game->cam.y));
    point_2d.x = 300*((x - game->cam.x)/(z- game->cam.y))+960;
    point_2d.y = 300 * y_divide_by_z + 540;
    return point_2d;
}