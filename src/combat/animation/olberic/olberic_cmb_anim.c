/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** olberic fight anim
*/

#include "my_rpg.h"

void olberic_do_attack(entity_t *player, combat_t *combat)
{
    if (player->rect_left_i < 10) {
        player->rect_left_i++;
        player->rect_left_w++;
        player->rect.left = olberic_rect_left[player->rect_left_i];
        player->rect.width = olberic_rect_w[player->rect_left_w];
    } else {
        player->rect_left_i = 19;
        player->rect_left_w = 19;
        player->cmb_state = RPG_COMBAT_PLAYER_IDLE;
        combat->state = RPG_COMBAT_PENDING;
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfClock_restart(player->clock);
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
