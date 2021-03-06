/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** combat loop
*/

#include "my_rpg.h"
#include "my.h"

static void check_player_state(entity_t *player, combat_t *combat, rpg_t *rpg)
{
    if (player->cmb_state == RPG_COMBAT_PLAYER_DEATH) {
        olberic_death(player);
        combat->state = RPG_COMBAT_DEATH;
        return;
    } if (player->cmb_state == RPG_COMBAT_PLAYER_IDLE)
        olberic_do_idle(player);
    if (player->cmb_state == RPG_COMBAT_PLAYER_ATTACK)
        olberic_do_attack(player, combat);
    if (player->cmb_state == RPG_COMBAT_PLAYER_PROTECT)
        olberic_protect(player, combat);
    if (player->cmb_state == RPG_COMBAT_PLAYER_HEAL)
        heal_player(rpg);
    sfClock_restart(rpg->combat->delay_clock);
}

static void get_input(entity_t *player, combat_t *combat, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(KEYATK) &&
    player->cmb_state == RPG_COMBAT_PLAYER_IDLE) {
        player->cmb_state = RPG_COMBAT_PLAYER_ATTACK;
        combat->state = RPG_COMBAT_ATTACKING;
        player->rect_left_i = 6;
        player->rect_left_w = 6;
    } if (sfKeyboard_isKeyPressed(KEYPROTECT) &&
    player->cmb_state == RPG_COMBAT_PLAYER_IDLE) {
        player->cmb_state = RPG_COMBAT_PLAYER_PROTECT;
        combat->state = RPG_COMBAT_ENNEMY;
    } if (sfKeyboard_isKeyPressed(KEYRUN) &&
    player->cmb_state == RPG_COMBAT_PLAYER_IDLE) {
        combat->transition_cmb = true;
    } if (sfKeyboard_isKeyPressed(sfKeyH) &&
    player->cmb_state == RPG_COMBAT_PLAYER_IDLE) {
        player->cmb_state = RPG_COMBAT_PLAYER_HEAL;
    }
    check_player_state(combat->player, combat, rpg);
}

static void animate(rpg_t *rpg, entity_t *ennemy)
{
    if (my_strcmp(ennemy->name, "boss") == 0)
        animate_boss(rpg->combat->curr_ennemy, rpg->combat);
    if (my_strcmp(ennemy->name, "bear") == 0)
        animate_bear(rpg->combat->curr_ennemy, rpg->combat);
    if (my_strcmp(ennemy->name, "wolf") == 0)
        animate_wolf(rpg->combat->curr_ennemy, rpg->combat);
}

static void combat_loop_bis(rpg_t *rpg, combat_t *combat)
{
    if (get_time(combat->curr_ennemy->clock) > 0.15f)
        animate(rpg, combat->curr_ennemy);
    if (combat->state == RPG_COMBAT_WIN &&
    my_strcmp(combat->curr_ennemy->name, "boss") != 0) {
        combat->transition_cmb = true;
        combat->player->stat->xp += 8 + get_rand_small_range();
        check_stat(rpg);
        add_to_inventory(rpg);
        combat->ennemy_killed++;
        sfRenderWindow_drawSprite(rpg->window, combat->curr_ennemy->sprite,
        NULL);
        sfRenderWindow_drawSprite(rpg->window, combat->player->sprite, NULL);
        return;
    } if (combat->state == RPG_COMBAT_WIN &&
    my_strcmp(combat->curr_ennemy->name, "boss") == 0)
        rpg->end_toggle = true;
    sfRenderWindow_drawSprite(rpg->window, combat->curr_ennemy->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, combat->player->sprite, NULL);
}

void combat_loop(rpg_t *rpg, combat_t *combat)
{
    draw_hud(rpg, combat->player, combat->curr_ennemy);
    if (combat->slash->is_active)
        do_slash(combat, rpg->window);
    if (combat->state == RPG_COMBAT_PENDING)
        move_hud_in(combat->hud);
    else
        move_hud_out(combat->hud);
    if (get_time(combat->player->clock) > 0.12f &&
    combat->state != RPG_COMBAT_ENNEMY && rpg->combat->transition_ow == false)
        get_input(combat->player, combat, rpg);
    combat_loop_bis(rpg, combat);
}
