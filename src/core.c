/*
** EPITECH PROJECT, 2022
** my_rph
** File description:
** main file
*/

#include <stdlib.h>
#include "my_rpg.h"

static int gameloop(rpg_t *rpg, combat_t *combat)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, sfBlack);
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            if (rpg->event.type == sfEvtClosed)
                return 1;
        draw_map(rpg);
        combat_loop(rpg, combat);
        sfRenderWindow_display(rpg->window);
    }
    return 0;
}

int main(int ac, char **av)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (init_sfml(rpg))
        return 84;
    rpg->combat = init_combat();
    rpg->world = malloc(sizeof(world_t));
    rpg->cam.x = 1600;
    rpg->cam.y = 0;
    rpg->cam.render = malloc(sizeof(render_t));
    rpg->cam.render->point = malloc(sizeof(sfVector2f) * 3);
    rpg->cam.render->triangle = sfVertexArray_create();

    sfVertexArray_resize(rpg->cam.render->triangle, 3);
    rpg->world->height_map = create_map(MAP_X, MAP_Y);
    if (gameloop(rpg, rpg->combat)) {
        free_rpg(rpg);
        return 84;
    }
    return 0;
}