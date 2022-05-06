/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** combat main file
*/

#include <stdlib.h>

#include "my_rpg.h"

static int create_transt(transt_t *e)
{
    e->rect = sfRectangleShape_create();
    if (!e->rect)
        return 84;
    sfRectangleShape_setSize(e->rect, (sfVector2f){RES_X, RES_Y});
    sfRectangleShape_setFillColor(e->rect, sfColor_fromRGBA(0, 0, 0, 0));
    e->pos = (sfVector2f){0, 0};
    sfRectangleShape_setPosition(e->rect, e->pos);
    e->clock = sfClock_create();
    return 0;
}

static int call_func(rpg_t *rpg)
{
    if (create_player(rpg->combat)
    || create_ennemy(rpg->combat->ennemy[0], "boss", BOSS_PATH, 0)
    || create_ennemy(rpg->combat->ennemy[1], "bear", BEAR_PATH, 1)
    || create_ennemy(rpg->combat->ennemy[2], "wolf", WOLF_PATH, 2))
        return 84;
    if (create_hud(rpg->combat) || create_transt(rpg->combat->transt)
    || init_font(rpg))
        return 84;
    rpg->combat->transition_ow = false;
    rpg->combat->transition_cmb = false;
    rpg->combat->delay_clock = sfClock_create();
    return 0;
}

int init_combat(rpg_t *rpg)
{
    rpg->combat = malloc(sizeof(combat_t));
    if (!rpg->combat)
        return 84;
    rpg->combat->ennemy = malloc(sizeof(entity_t *) * 3);
    if (!rpg->combat->ennemy)
        return 84;
    rpg->combat->ennemy[0] = malloc(sizeof(entity_t));
    rpg->combat->ennemy[1] = malloc(sizeof(entity_t));
    rpg->combat->ennemy[2] = malloc(sizeof(entity_t));
    rpg->combat->player = malloc(sizeof(entity_t));
    rpg->combat->transt = malloc(sizeof(transt_t));
    rpg->combat->curr_ennemy = malloc(sizeof(entity_t));
    if (!rpg->combat->ennemy || !rpg->combat->ennemy[0] ||
    !rpg->combat->ennemy[1] || !rpg->combat->ennemy[2] ||
    !rpg->combat->curr_ennemy || !rpg->combat->player || !rpg->combat->transt)
        return 84;
    if (call_func(rpg))
        return 84;
    rpg->combat->ennemy_killed = 0;
    return 0;
}
