/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** transition
*/

#include "my_rpg.h"
#include "my.h"

void do_transition(rpg_t *rpg, transt_t *e)
{
    if (get_time(e->clock) < 0.2f)
        return;
    if (e->pos.x < 0)
        e->pos.x += 10;
    else if (e->pos.x == 0 ) {
        rpg->scene = COMBAT;
        e->pos.x += 10;
    } if (e->pos.x > 0 && e->pos.x <= RES_X + 10)
        e->pos.x += 10;
    if (e->pos.x > RES_X + 10)
        e->pos.x = RES_X * -1;
    sfRectangleShape_setPosition(e->rect, e->pos);
    if (e->pos.x > RES_X * -1)
        sfRenderWindow_drawRectangleShape(rpg->window, e->rect, NULL);
    sfClock_restart(e->clock);
}
