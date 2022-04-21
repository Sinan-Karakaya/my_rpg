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
    if (rpg->event.type == sfEvtClosed) {
        sfRenderWindow_close(rpg->window);
        return 1;
    } if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code == sfKeyEscape) {
            rpg->menu->option->is_active = true;
        }
    } if (rpg->event.type == sfEvtMouseButtonPressed)
        buttons_controls_option_ig(rpg, BUTTONSO, rpg->event);
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code == sfKeyDown)
            rpg->cam.y -= 60 * rpg->dt;
        if (rpg->event.key.code == sfKeyUp)
            rpg->cam.y += 60 * rpg->dt;
        if (rpg->event.key.code == sfKeyRight)
            rpg->cam.x += 200 * rpg->dt;
        if (rpg->event.key.code == sfKeyLeft)
            rpg->cam.x -= 200 * rpg->dt;
    }
    return 0;
}

static int gameloop(rpg_t *rpg, combat_t *combat)
{
    while (sfRenderWindow_isOpen(rpg->window) && rpg->menu->is_closed != true
    && rpg->menu->is_main != true) {
        rpg->dt = get_dt(rpg->game_clock);
        sfRenderWindow_clear(rpg->window, sfBlack);
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            if (event(rpg) == 1)
                return 1;
        if (rpg->menu->option->is_active == true) {
            print_option_ig(rpg);
            display_buttons_option_ig(rpg);
        } else {
            draw_water(rpg);
            draw_map(rpg);
            // draw_object(rpg);
            // combat_loop(rpg, combat);
            overworld_loop(rpg);
            // update_shaders(rpg->shader, rpg->dt);
            print_debug(rpg);
        }
        sfRenderWindow_display(rpg->window);
    }
    return 0;
}

static void do_loop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        menuloop(rpg);
        gameloop(rpg, rpg->combat);
    }
}

int main(int ac, char **av)
{
    int debug_mode = handle_args(ac, av);
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (debug_mode == -1)
        return 0;
    if (!rpg || init_sfml(rpg, debug_mode))
        return 84;
    init_all(rpg);
    do_loop(rpg);
    free_rpg(rpg);
    return 0;
}
