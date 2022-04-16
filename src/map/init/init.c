/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init map
*/

#include <stdlib.h>
#include "my_rpg.h"

/*
* Possible de donner un shader très sympa au world avec cette ligne notamment:
* tex->shader = rpg->shader->get
* Ca nous permettrait de donner un effet de neige
* ou de pluie au sol par exemple
*/
sfRenderStates *init_struct_texture(char *path, rpg_t *rpg)
{
    sfRenderStates *tex = malloc(sizeof(sfRenderStates));

    tex = malloc(sizeof(sfRenderStates));
    tex->blendMode = sfBlendAlpha;
    tex->transform = sfTransform_Identity;
    tex->texture = sfTexture_createFromFile(path, NULL);
    tex->shader = NULL;
    return tex;
}

void init_world(rpg_t *game)
{
    game->world = malloc(sizeof(world_t));
    game->world->height_map = create_map(MAP_X, MAP_Y);
    game->world->object_map = create_map(MAP_X, MAP_Y);
    game->world->water_clock = sfClock_create();
    game->world->texture_map =  str_to_int_tab();
}

void destroy_world(rpg_t *game)
{
    for (int i = 0; i < MAP_X; i++) {
        free(game->world->height_map[i]);
        free(game->world->object_map[i]);
        free(game->world->texture_map[i]);
    }
    free(game->world->height_map);
    free(game->world->object_map);
    free(game->world->texture_map);
    free(game->world->water_clock);
}

void init_cam(rpg_t *game)
{
    game->cam.x = 1600;
    game->cam.y = 400;
    game->cam.r = 2;
    game->cam.render = malloc(sizeof(render_t));
    game->cam.render->point = malloc(sizeof(sfVector2f) * 3);
    game->cam.render->triangle = sfVertexArray_create();
    sfVertexArray_resize(game->cam.render->triangle, 3);
}