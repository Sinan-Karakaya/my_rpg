/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** heal
*/

#include "my_rpg.h"

bool heal_player(rpg_t *rpg)
{
    for (size_t i = 0; i < 34; i++) {
        if (INVENTORY->slots[i]->item_id == 2) {
            rpg->combat->player->life += 75;
            INVENTORY->slots[i]->item_id = 0;
            rpg->combat->player->cmb_state = RPG_COMBAT_PLAYER_IDLE;
            rpg->combat->state = RPG_COMBAT_ENNEMY;
            return true;
        }
    }
    rpg->combat->player->cmb_state = RPG_COMBAT_PLAYER_IDLE;
    return false;
}
