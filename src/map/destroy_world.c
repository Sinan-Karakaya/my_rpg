/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy world
*/

#include <stdlib.h>

#include "my_rpg.h"


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
    sfClock_destroy(game->world->world_clock);
}
