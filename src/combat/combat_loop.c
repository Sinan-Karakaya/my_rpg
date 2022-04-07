/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** combat loop
*/

#include "my_rpg.h"

static void animate_boss(entity_t *boss)
{
    if (boss->rect.left + boss->rect.width <= 1785)
        boss->rect.left += BOSS_WIDTH + 65;
    else
        boss->rect.left = 0;
    sfSprite_setTextureRect(boss->sprite, boss->rect);
    sfClock_restart(boss->clock);
}

static void get_input(entity_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
    player->cmb_state == RPG_COMBAT_PLAYER_IDLE) {
        player->cmb_state = RPG_COMBAT_PLAYER_ATTACK;
        player->rect_left_i = 0;
        player->rect_left_w = 0;
    }
    if (player->cmb_state == RPG_COMBAT_PLAYER_IDLE) {
        olberic_do_idle(player);
    } else if (player->cmb_state == RPG_COMBAT_PLAYER_ATTACK) {
        olberic_do_attack(player);
    }
}

void combat_loop(rpg_t *rpg, combat_t *combat)
{
    sfRenderWindow_drawSprite(rpg->window, combat->ennemy->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, combat->player->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->combat->hud->sprite, NULL);
    if (get_time(combat->ennemy->clock) > 0.15f)
        animate_boss(combat->ennemy);
    if (get_time(combat->player->clock) > 0.1f)
        get_input(combat->player);
}
