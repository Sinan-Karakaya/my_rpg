/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** combat loop
*/

#include "my_rpg.h"

static void check_player_state(entity_t *player, combat_t *combat)
{
    if (player->cmb_state == RPG_COMBAT_PLAYER_IDLE)
        olberic_do_idle(player);
    if (player->cmb_state == RPG_COMBAT_PLAYER_ATTACK)
        olberic_do_attack(player, combat);
    if (player->cmb_state == RPG_COMBAT_PLAYER_PROTECT)
        olberic_protect(player, combat);
    if (player->cmb_state == RPG_COMBAT_PLAYER_DEATH) {
        olberic_death(player);
    }
}

static void get_input(entity_t *player, combat_t *combat)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
    player->cmb_state == RPG_COMBAT_PLAYER_IDLE) {
        player->cmb_state = RPG_COMBAT_PLAYER_ATTACK;
        combat->state = RPG_COMBAT_ATTACKING;
        player->rect_left_i = 0;
        player->rect_left_w = 0;
    } if (sfKeyboard_isKeyPressed(sfKeyP) &&
    combat->state == RPG_COMBAT_PENDING) {
        player->cmb_state = RPG_COMBAT_PLAYER_PROTECT;
        combat->state = RPG_COMBAT_ENNEMY;
    }
    // DEBUG
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        player->life -= 10;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        player->life += 10;
    // END DEBUG
    check_player_state(player, combat);
}

void combat_loop(rpg_t *rpg, combat_t *combat)
{
    sfRenderWindow_drawSprite(rpg->window, combat->ennemy->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, combat->player->sprite, NULL);
    draw_hud(rpg, combat->player, combat->ennemy);
    if (combat->player->cmb_state == RPG_COMBAT_PLAYER_IDLE)
        move_hud_in(combat->hud);
    else /*if (combat->player->cmb_state == RPG_COMBAT_PLAYER_ATTACK ||
    combat->state == RPG_COMBAT_ENNEMY)*/
        move_hud_out(combat->hud);
    if (get_time(combat->ennemy->clock) > 0.15f)
        animate_boss(combat->ennemy, combat);
    if (get_time(combat->player->clock) > 0.12f &&
    combat->state != RPG_COMBAT_ENNEMY)
        get_input(combat->player, combat);
}
