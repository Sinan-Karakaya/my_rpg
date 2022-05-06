/*
** EPITECH PROJECT, 2022
** my_rph
** File description:
** main file
*/

#include "my_rpg.h"

static void fill_forest(rpg_t *rpg)
{
    rpg->world->object_map[4][74] = 5;
    rpg->world->object_map[13][74] = 7;
    rpg->world->object_map[47][15] = 7;
    rpg->world->object_map[18][52] = 7;
    rpg->world->object_map[12][51] = 5;
    rpg->world->object_map[13][67] = 5;
    rpg->world->object_map[20][66] = 5;
    rpg->world->object_map[28][70] = 5;
    rpg->world->object_map[29][56] = 5;
    rpg->world->object_map[39][54] = 5;
    rpg->world->object_map[38][70] = 7;
    rpg->world->object_map[31][43] = 5;
}

static void fill_spawn(rpg_t *rpg)
{
    rpg->world->object_map[47][15] = 8;
    rpg->world->object_map[31][28] = 8;
    rpg->world->object_map[36][28] = 8;
}

void fill_map(rpg_t *rpg)
{
    fill_forest(rpg);
    fill_spawn(rpg);
    rpg->world->object_map[112][74] = 3;
    rpg->world->object_map[123][76] = 4;
    rpg->world->object_map[134][75] = 2;
    rpg->world->object_map[65][26] = 6;
    rpg->world->object_map[70][35] = 6;
    rpg->world->object_map[73][55] = 6;
}
