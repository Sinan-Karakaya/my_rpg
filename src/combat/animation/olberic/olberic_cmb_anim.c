/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** olberic fight anim
*/

#include "my_rpg.h"

void olberic_do_attack(entity_t *player, combat_t *combat, rpg_t *rpg)
{
    int dmg = 0;

    if (get_time(player->clock) > 0.5f)
        olberic_do_attack(player, combat, rpg);
    else
        sfClock_restart(player->clock);
    if (player->rect_left_i < 10) {
        player->rect_left_i++, player->rect_left_w++;
        player->rect.left = olberic_rect_left[player->rect_left_i];
        player->rect.width = olberic_rect_w[player->rect_left_w];
    } else {
        player->rect_left_i = 19, player->rect_left_w = 19;
        dmg = (player->stat->attack + player->stat->stuff->attack)
        - (combat->curr_ennemy->stat->defense) + get_rand_small_range();
        if (dmg > 0)
            combat->curr_ennemy->life -= dmg;
        player->cmb_state = RPG_COMBAT_PLAYER_IDLE;
        combat->state = RPG_COMBAT_ENNEMY;
    } sfSprite_setTextureRect(player->sprite, player->rect);
    sfRenderWindow_drawSprite(rpg->window, player->sprite, NULL);
    sfClock_restart(player->clock), sfSound_play(combat->sfx->sound);
}

void olberic_do_idle(entity_t *player)
{
    player->rect_left_i = 19;
    player->rect_left_w = 19;
    player->rect.left = olberic_rect_left[player->rect_left_i];
    player->rect.width = olberic_rect_w[player->rect_left_w];
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfClock_restart(player->clock);
}

void olberic_protect(entity_t *player, combat_t *combat)
{
    player->rect_left_i = 20;
    player->rect_left_w = 20;
    player->rect.left = olberic_rect_left[player->rect_left_i];
    player->rect.width = olberic_rect_w[player->rect_left_w];
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfClock_restart(player->clock);
    combat->state = RPG_COMBAT_ENNEMY;
}

void olberic_death(entity_t *player)
{
    if (player->rect_left_i < 23) {
        player->rect_left_i = 23;
        player->rect_left_w = 23;
    }
    if (player->rect_left_i < 25) {
        player->rect_left_i++;
        player->rect_left_w++;
        player->rect.left = olberic_rect_left[player->rect_left_i];
        player->rect.width = olberic_rect_w[player->rect_left_w];
    } else {
        player->rect_left_i = 25;
        player->rect_left_w = 25;
        player->rect.left = olberic_rect_left[player->rect_left_i];
        player->rect.width = olberic_rect_w[player->rect_left_w];
        player->cmb_state = RPG_COMBAT_PLAYER_DEATH;
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfClock_restart(player->clock);
}
