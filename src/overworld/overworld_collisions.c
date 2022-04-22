/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** overworld collisions
*/

#include "my_rpg.h"

static void check_collision_with_map(rpg_t *rpg, world_t *w, int i, int j)
{
    if (w->object_map[i][j] > 0 &&
    do_aabb_sprites(rpg->overworld->spr, w->object_map[i][j])) {
        if (OW->state == RPG_OW_WALK_R) {
            rpg->cam.x -= 200 * rpg->dt;
            check_collision_with_map(rpg, w, i, j);
        } else if (OW->state == RPG_OW_WALK_L) {
            rpg->cam.x += 200 * rpg->dt;
            check_collision_with_map(rpg, w, i, j);
        }
    }
}

void ow_collisions(rpg_t *rpg, world_t *world)
{
    for (int i = 0; i < world->object_map; i++) {
        for (int j = 0; j < world->object_map[i]; j++) {
            check_collision_with_map(rpg, world, i, j);
        }
    }
}
