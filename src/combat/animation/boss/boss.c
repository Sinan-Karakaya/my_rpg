/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** boss animation
*/

#include "my_rpg.h"

static void boss_attack(entity_t *boss, entity_t *player, combat_t *combat)
{
    int dmg = 0;

    if (player->cmb_state == RPG_COMBAT_PLAYER_PROTECT) {
        dmg = (boss->stat->attack - ((player->stat->defense +
        player->stat->stuff->defense)) + get_rand_small_range()) / 2;
        if (dmg > 0)
            player->life -= dmg;
    } else {
        dmg = boss->stat->attack - ((player->stat->defense +
        player->stat->stuff->defense) / 2) + get_rand_small_range();
        if (dmg > 0)
            player->life -= dmg;
    }
    player->cmb_state = RPG_COMBAT_PLAYER_IDLE;
    combat->slash->is_active = true;
    combat->state = RPG_COMBAT_PENDING;
    sfClock_restart(combat->delay_clock);
}

void animate_boss(entity_t *boss, combat_t *combat)
{
    if (boss->rect.left + boss->rect.width <= 1785)
        boss->rect.left += BOSS_WIDTH + 65;
    else
        boss->rect.left = 0;
    sfSprite_setTextureRect(boss->sprite, boss->rect);
    sfClock_restart(boss->clock);
    if (combat->state == RPG_COMBAT_ENNEMY && get_time(combat->delay_clock) > 1.0f)
        boss_attack(boss, combat->player, combat);
}
