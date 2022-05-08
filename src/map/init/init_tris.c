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
    game->world->texture_n = do_init_struct_texture(ENV_PR, game);
    game->world->texture_p = do_init_struct_texture(ENV_PP, game);
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
