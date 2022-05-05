/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** anim ennemies
*/

#include "my_rpg.h"

static void ennemy_attack(entity_t *boss, entity_t *player, combat_t *combat)
{
    if (player->cmb_state == RPG_COMBAT_PLAYER_PROTECT) {
        player->life -= (boss->stat->attack - (player->stat->defense / 2) +
        get_rand_small_range()) / 2;
    } else {
        player->life -= boss->stat->attack - (player->stat->defense / 2) +
        get_rand_small_range();
    }
    player->cmb_state = RPG_COMBAT_PLAYER_IDLE;
    combat->slash->is_active = true;
    combat->state = RPG_COMBAT_PENDING;
    sfClock_restart(combat->delay_clock);
}

void animate_bear(entity_t *bear, combat_t *combat)
{
    if (bear->rect.left + bear->rect.width < (BEAR_FRAMES - 1) * BEAR_WIDTH)
        bear->rect.left += BEAR_WIDTH;
    else
        bear->rect.left = 0;
    if (bear->rect.left == 87)
        bear->rect.width = 88;
    if (bear->rect.left == 175)
        bear->rect.width = 89;
    else
        bear->rect.width = 86;
    sfSprite_setTextureRect(bear->sprite, bear->rect);
    sfClock_restart(bear->clock);
    if (combat->state == RPG_COMBAT_ENNEMY && get_time(combat->delay_clock) >
    1.0f)
        ennemy_attack(bear, combat->player, combat);
}

void animate_wolf(entity_t *wolf, combat_t *combat)
{
    if (wolf->rect.left + wolf->rect.width <= (WOLF_FRAMES - 1) * WOLF_WIDTH)
        wolf->rect.left += wolf->rect.width;
    else
        wolf->rect.left = 0;
    if (wolf->rect.left == 193 || wolf->rect.left == 385 || wolf->rect.left == 577)
        wolf->rect.width = 95;
    else if (wolf->rect.left == 288 || wolf->rect.left == 480)
        wolf->rect.width = 97;
    else
        wolf->rect.width = 96;
    sfSprite_setTextureRect(wolf->sprite, wolf->rect);
    sfClock_restart(wolf->clock);
    if (combat->state == RPG_COMBAT_ENNEMY && get_time(combat->delay_clock) >
    1.0f)
        ennemy_attack(wolf, combat->player, combat);
}
