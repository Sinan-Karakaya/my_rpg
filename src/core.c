/*
** EPITECH PROJECT, 2022
** my_rph
** File description:
** main file
*/

#include <stdlib.h>
#include "my_rpg.h"

int event(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtClosed)
        return 1;
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code == sfKeyDown)
            rpg->cam.y += 1000 * rpg->dt;
        if (rpg->event.key.code == sfKeyUp)
            rpg->cam.y -= 1000 * rpg->dt;
        if (rpg->event.key.code == sfKeyRight)
            rpg->cam.x += 1000 * rpg->dt;
        if (rpg->event.key.code == sfKeyLeft)
            rpg->cam.x -= 1000 * rpg->dt;
    }
    return 0;
}

static int gameloop(rpg_t *rpg, combat_t *combat)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        get_dt(rpg->game_clock);
        sfRenderWindow_clear(rpg->window, sfBlack);
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            if (event(rpg) == 1)
                return 1;
        }
        draw_map(rpg);
        rpg->cam.x += 0.8;
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
    init_cam(rpg);
    init_world(rpg);
    rpg->texture = init_struct_texture("assets/environement/pr.png");
    rpg->world->height_map[25][8] = -4;
    rpg->sounds = malloc(sizeof(music_t));
    rpg->sounds->music = sfMusic_createFromFile("assets/music/vista.ogg");
    play_music(rpg);
    if (gameloop(rpg, rpg->combat)) {
        free_rpg(rpg);
        return 0;
    }
    return 0;
}
