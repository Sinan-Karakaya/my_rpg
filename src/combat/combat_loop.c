/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** combat loop
*/

#include "my_rpg.h"

static void check_player_state(entity_t *player, combat_t *combat, rpg_t *rpg)
{
    if (player->cmb_state == RPG_COMBAT_PLAYER_DEATH) {
        olberic_death(player);
        combat->state = RPG_COMBAT_DEATH;
        return;
    } if (player->cmb_state == RPG_COMBAT_PLAYER_IDLE)
        olberic_do_idle(player);
    if (player->cmb_state == RPG_COMBAT_PLAYER_ATTACK)
        olberic_do_attack(player, combat, rpg);
    if (player->cmb_state == RPG_COMBAT_PLAYER_PROTECT)
        olberic_protect(player, combat);
}

static void get_input(entity_t *player, combat_t *combat, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
    player->cmb_state == RPG_COMBAT_PLAYER_IDLE) {
        player->cmb_state = RPG_COMBAT_PLAYER_ATTACK;
        combat->state = RPG_COMBAT_ATTACKING;
        player->rect_left_i = 6;
        player->rect_left_w = 6;
    } if (sfKeyboard_isKeyPressed(sfKeyP) &&
    player->cmb_state == RPG_COMBAT_PLAYER_IDLE) {
        player->cmb_state = RPG_COMBAT_PLAYER_PROTECT;
        combat->state = RPG_COMBAT_ENNEMY;
    }
    check_player_state(combat->player, combat, rpg);
}

void combat_loop(rpg_t *rpg, combat_t *combat)
{
    sfRenderWindow_drawSprite(rpg->window, combat->ennemy->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, combat->player->sprite, NULL);
    draw_hud(rpg, combat->player, combat->ennemy);
    if (combat->slash->is_active)
        do_slash(combat, rpg->window);
    if (combat->player->cmb_state == RPG_COMBAT_PLAYER_IDLE)
        move_hud_in(combat->hud);
    else
        move_hud_out(combat->hud);
    if (get_time(combat->ennemy->clock) > 0.15f)
        animate_boss(combat->ennemy, combat);
    if (get_time(combat->player->clock) > 0.12f &&
    combat->state != RPG_COMBAT_ENNEMY)
        get_input(combat->player, combat, rpg);
}
