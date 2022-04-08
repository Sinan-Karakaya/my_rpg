/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** boss animation
*/

#include "my_rpg.h"

static void boss_attack(entity_t *boss, entity_t *player, combat_t *combat)
{
    if (player->cmb_state == RPG_COMBAT_PLAYER_PROTECT) {
        player->life -= (boss->stat->attack - (player->stat->defense / 2) +
        get_rand_small_range()) / 2;
        player->cmb_state = RPG_COMBAT_PLAYER_IDLE;
    } else {
        player->life -= boss->stat->attack - (player->stat->defense / 2) +
        get_rand_small_range();
    }
    combat->state = RPG_COMBAT_PENDING;
}

void animate_boss(entity_t *boss, combat_t *combat)
{
    if (boss->rect.left + boss->rect.width <= 1785)
        boss->rect.left += BOSS_WIDTH + 65;
    else
        boss->rect.left = 0;
    sfSprite_setTextureRect(boss->sprite, boss->rect);
    sfClock_restart(boss->clock);
    if (combat->state == RPG_COMBAT_ENNEMY)
        boss_attack(boss, combat->player, combat);
}
