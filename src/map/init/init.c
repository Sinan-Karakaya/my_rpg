/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init map
*/

#include <stdlib.h>

#include "my_rpg.h"

texture_t *init_struct_texture(char *path)
{
    texture_t *tex = malloc(sizeof(texture_t));

    tex->state = malloc(sizeof(sfRenderStates));
    tex->state->blendMode = sfBlendAlpha;
    tex->state->transform = sfTransform_Identity;
    tex->state->texture = sfTexture_createFromFile(path, NULL);
    tex->state->shader = NULL;
    return tex;
}

void init_world(rpg_t *game)
{
    game->world->height_map = create_map(MAP_X, MAP_Y);
    game->world->object_map = create_map(MAP_X, MAP_Y);
    game->world->texture_map = create_map(MAP_X, MAP_Y);
    game->world->water_map = create_map(MAP_X, MAP_Y);
}

void init_cam(rpg_t *game)
{
    game->cam.x = 1600;
    game->cam.y = 0;
    game->cam.render = malloc(sizeof(render_t));
    game->cam.render->point = malloc(sizeof(sfVector2f) * 3);
    game->cam.render->triangle = sfVertexArray_create();
    sfVertexArray_resize(game->cam.render->triangle, 3);
}