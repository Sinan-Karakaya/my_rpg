/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init map
*/

#include <stdlib.h>
#include "my_rpg.h"

int init_tris(rpg_t *game)
{
    game->world->texture_n = init_struct_texture("assets/environement/pr.png",
    game);
    game->world->texture_p = init_struct_texture("assets/environement/pp.png",
    game);
    if (!game->world->texture_map || !game->world->height_map)
        return 84;
    game->world->rendered_spr = malloc(sizeof(sfSprite*));
    if (!game->world->rendered_spr)
        return 84;
    game->world->rendered_spr[0] = NULL;
    game->world->olberick_pos = (sfVector2i){0, 0};
    if (sfShader_isAvailable())
        game->world->shader = NULL;
    return 0;
}
