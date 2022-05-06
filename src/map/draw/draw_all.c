/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_all_map
*/

#include "my_rpg.h"

static void chose_scene(rpg_t *rpg)
{
    if (rpg->scene == OVERWORLD)
        overworld_loop(rpg);
    if (rpg->scene == COMBAT)
        combat_loop(rpg, rpg->combat);
    if (rpg->combat->transition_ow)
        do_transition_ow(rpg, rpg->combat->transt);
    else if (rpg->combat->transition_cmb)
        do_transition_cmb(rpg, rpg->combat->transt);
    if (rpg->combat->player->cmb_state == RPG_COMBAT_PLAYER_DEATH)
        do_transition_death(rpg, rpg->combat->transt);
    if (rpg->scene == DEATH)
        draw_game_over(rpg);
}

int draw_all(rpg_t *rpg)
{
    draw_water(rpg);
    draw_map(rpg);
    draw_object(rpg);
    chose_scene(rpg);
    draw_npc(rpg);
    chose_scene(rpg);
    check_quest(rpg);
}