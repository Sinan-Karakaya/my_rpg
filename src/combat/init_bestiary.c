/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "my.h"

void spawn_ennemy(rpg_t *rpg)
{
    if (!cmb_is_in_bounds(rpg->cam))
        return;
    if (IN_OVERWORLD && (rand() % 1000000) < 3) {
        rpg->combat->transition_ow = true;
        rpg->combat->curr_ennemy = rpg->combat->ennemy[rand() % 2 + 1];
    } else if (rpg->scene == COMBAT) {
        rpg->combat->transition_cmb = true;
    }
}
