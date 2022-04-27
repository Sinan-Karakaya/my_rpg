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
        if (rpg->event.key.code == sfKeyEscape ) {
            rpg->menu->option->is_active = true;
            rpg->menu->option->is_main = true;
        }
        if (rpg->event.key.code == sfKeyI) {
            rpg->menu->option->is_active = true;
            rpg->menu->is_inventory = true;
        }
    } if (rpg->event.type == sfEvtMouseButtonPressed)
        buttons_controls_option_ig(rpg, BUTTONSO, rpg->event);
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code == KEYDOWN && IN_OVERWORLD)
            rpg->cam.y -= 60 * rpg->dt;
        if (rpg->event.key.code == KEYUP && IN_OVERWORLD)
            rpg->cam.y += 60 * rpg->dt;
        if (rpg->event.key.code == KEYRIGHT && IN_OVERWORLD)
            rpg->cam.x += 2000 * rpg->dt;
        if (rpg->event.key.code == KEYLEFT && IN_OVERWORLD)
            rpg->cam.x -= 2000 * rpg->dt;
        // ------------------ DEBUG ------------------------
        if (rpg->event.key.code == sfKeyC)
            if (IN_OVERWORLD) {
                rpg->scene = COMBAT;
                rpg->cam.r = 0;
            }
            else if (rpg->scene == COMBAT) {
                rpg->scene = OVERWORLD;
                rpg->cam.r = 2;
            }
        // -------------------------------------------------
    } get_dir(rpg);
    return 0;
}

static void chose_scene(rpg_t *rpg)
{
    if (rpg->scene == OVERWORLD)
        overworld_loop(rpg);
    else if (rpg->scene == COMBAT)
        combat_loop(rpg, rpg->combat);
}

static int gameloop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window) && rpg->menu->is_closed != true
    && rpg->menu->is_main != true) {
        sfRenderWindow_clear(rpg->window, sfBlack);
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            if (event(rpg) == 1)
                return 1;
        if (rpg->menu->option->is_active == true) {
            display_options_ig(rpg);
        } else {
            draw_water(rpg);
            draw_map(rpg);
            draw_object(rpg);
            chose_scene(rpg);
            draw_npc(rpg);
        }
        rpg->dt = get_dt(rpg->game_clock);
        print_debug(rpg);
        sfRenderWindow_display(rpg->window);
    }
    return 0;
}

static void do_loop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        menuloop(rpg);
        gameloop(rpg);
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
    rpg->world->object_map[20][20]= 1;
    rpg->world->object_map[10][2]= 2;
    rpg->world->object_map[18][2]= 3;
    rpg->world->npc_list[0] = (npc_t){"npc1", (sfVector2i){18, 2},2 ,50 , 20 , 20 , 20};
    do_loop(rpg);
    free_rpg(rpg);
    return 0;
}
