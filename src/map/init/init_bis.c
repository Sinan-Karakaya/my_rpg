/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init map
*/

#include <stdlib.h>
#include "my_rpg.h"

int init_cam(rpg_t *game)
{
    game->cam.x = 370;
    game->cam.y = 200;
    game->cam.r = 2;
    game->cam.render = malloc(sizeof(render_t));
    if (!game->cam.render)
        return (84);
    game->cam.render->point = malloc(sizeof(sfVector2f) * 3);
    game->cam.render->triangle = sfVertexArray_create();
    if (!game->cam.render->point || !game->cam.render->triangle)
        return 84;
    sfVertexArray_resize(game->cam.render->triangle, 3);
    return 0;
}
