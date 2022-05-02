/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** transition
*/

#include "my_rpg.h"
#include "my.h"

void do_transition_cmb(rpg_t *rpg, transt_t *e)
{
    sfColor color = sfRectangleShape_getFillColor(e->rect);

    if (get_time(e->clock) < 0.002f)
        return;
    if (rpg->scene == COMBAT && color.a < 255) {
        color.a += 5;
    } else if (rpg->scene == COMBAT && color.a == 255) {
        rpg->scene = OVERWORLD;
        rpg->cam.r = 2;
    } if (rpg->scene == OVERWORLD && color.a > 0) {
        color.a -= 5;
    } else if (rpg->scene == OVERWORLD && color.a == 0)
        rpg->combat->transition_cmb = false;
    sfRectangleShape_setFillColor(e->rect, color);
    sfRenderWindow_drawRectangleShape(rpg->window, e->rect, NULL);
    sfClock_restart(e->clock);
}

void do_transition_ow(rpg_t *rpg, transt_t *e)
{
    sfColor color = sfRectangleShape_getFillColor(e->rect);

    if (get_time(e->clock) < 0.002f)
        return;
    if (rpg->scene == OVERWORLD && color.a < 255) {
        color.a += 5;
    } else if (rpg->scene == OVERWORLD && color.a == 255) {
        rpg->scene = COMBAT;
        rpg->cam.r = 0;
    } if (rpg->scene == COMBAT && color.a > 0) {
        color.a -= 5;
    } else if (rpg->scene == COMBAT && color.a == 0)
        rpg->combat->transition_ow = false;
    sfRectangleShape_setFillColor(e->rect, color);
    sfRenderWindow_drawRectangleShape(rpg->window, e->rect, NULL);
    sfClock_restart(e->clock);
}
