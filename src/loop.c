/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** loop file
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"

static void chose_scene(rpg_t *rpg)
{
    if (rpg->end_toggle) {
        end_game(rpg);
        return;
    } if (rpg->scene == OVERWORLD)
        overworld_loop(rpg);
    if (rpg->scene == COMBAT)
        combat_loop(rpg, rpg->combat);
    if (rpg->combat->transition_ow)
        do_transition_ow(rpg, rpg->combat->transt);
    else if (rpg->combat->transition_cmb)
        do_transition_cmb(rpg, rpg->combat->transt);
    if (rpg->combat->player->cmb_state == RPG_COMBAT_PLAYER_DEATH)
        do_transition_death(rpg, rpg->combat->transt);
}

static void do_cinematic(rpg_t *rpg)
{
    cinematic(rpg);
    if (rpg->cine->transition)
        do_transition_cine(rpg, rpg->combat->transt);
}

static void gameloop_bis(rpg_t *rpg)
{
    if (rpg->menu->option->is_active == true) {
        display_options_ig(rpg);
    } else if (rpg->scene == CINEMATIC || rpg->cine->transition) {
        do_cinematic(rpg);
    } else {
        chose_scene(rpg);
        draw_all(rpg);
    }
    rpg->dt = get_dt(rpg->game_clock);
    print_debug(rpg);
    sfRenderWindow_drawRectangleShape(rpg->window,
    rpg->combat->transt->rect, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->end->text, NULL);
    if (rpg->scene == DEATH)
        draw_game_over(rpg);
    if (!cmb_is_in_bounds(rpg->cam) && rpg->combat->player->life <
    rpg->combat->player->max_life)
        rpg->combat->player->life = rpg->combat->player->max_life;
}

static int gameloop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window) && rpg->menu->is_closed != true
    && rpg->menu->is_main != true) {
        sfRenderWindow_clear(rpg->window, sfBlack);
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
        event(rpg);
        gameloop_bis(rpg);
        sfRenderWindow_display(rpg->window);
    }
    return 0;
}

void do_loop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        menuloop(rpg);
        gameloop(rpg);
    }
}
