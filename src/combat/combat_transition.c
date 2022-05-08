/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** transition
*/

#include "my_rpg.h"
#include "my.h"

void do_transition_death(rpg_t *rpg, transt_t *e)
{
    sfColor color = sfRectangleShape_getFillColor(e->rect);

    if (get_time(e->clock) < 0.002f)
        return;
    if (rpg->scene == COMBAT && color.a < 255) {
        color.a += 5;
    } else if (rpg->scene == COMBAT && color.a == 255) {
        rpg->scene = DEATH;
        rpg->combat->transition_cmb = false;
    }
    sfRectangleShape_setFillColor(e->rect, color);
    sfClock_restart(e->clock);
}

static void change_music(rpg_t *rpg, char *path)
{
    if (sfMusic_getStatus(rpg->sounds->music) != sfPlaying)
        return;
    sfMusic_stop(rpg->sounds->music);
    sfMusic_destroy(rpg->sounds->music);
    rpg->sounds->music = sfMusic_createFromFile(path);
    if (rpg->sounds->music == NULL) {
        ERROR(path);
        return;
    }
    sfMusic_play(rpg->sounds->music);
    sfMusic_setLoop(rpg->sounds->music, sfTrue);
    sfMusic_setVolume(rpg->sounds->music, rpg->sounds->sound_music);
}

void do_transition_cmb(rpg_t *rpg, transt_t *e)
{
    sfColor color = sfRectangleShape_getFillColor(e->rect);

    if (get_time(e->clock) < 0.00002f)
        return;
    if (rpg->scene == COMBAT && color.a < 255) {
        color.a += 5;
    } else if (rpg->scene == COMBAT && color.a == 255) {
        rpg->scene = OVERWORLD;
        rpg->cam.r = 2;
        change_music(rpg, OVERWORLD_MUSIC);
    } if (rpg->scene == OVERWORLD && color.a > 0) {
        color.a -= 5;
    } else if (rpg->scene == OVERWORLD && color.a == 0) {
        rpg->combat->transition_cmb = false;
        rpg->combat->curr_ennemy->life = rpg->combat->curr_ennemy->max_life;
    }
    rpg->combat->state = RPG_COMBAT_PENDING;
    sfRectangleShape_setFillColor(e->rect, color);
    sfClock_restart(e->clock);
}

void do_transition_cine(rpg_t *rpg, transt_t *e)
{
    sfColor color = sfRectangleShape_getFillColor(e->rect);

    if (get_time(e->clock) < 0.002f)
        return;
    if (rpg->scene == CINEMATIC && color.a == 0)
        color.a = 255;
    if (rpg->scene == CINEMATIC && color.a == 255) {
        rpg->scene = OVERWORLD;
        rpg->cam.r = 2;
    } if (rpg->scene == OVERWORLD && color.a > 0) {
        color.a -= 5;
    } else if (rpg->scene == OVERWORLD && color.a == 0)
        rpg->cine->transition = false;
    sfRectangleShape_setFillColor(e->rect, color);
    sfClock_restart(e->clock);
}

void do_transition_ow(rpg_t *rpg, transt_t *e)
{
    sfColor color = sfRectangleShape_getFillColor(e->rect);

    if (get_time(e->clock) < 0.00002f)
        return;
    if (rpg->scene == OVERWORLD && color.a < 255) {
        color.a += 5;
    } else if (rpg->scene == OVERWORLD && color.a == 255) {
        rpg->scene = COMBAT;
        rpg->cam.r = 0;
        change_music(rpg, BATTLE_MUSIC);
    } if (rpg->scene == COMBAT && color.a > 0) {
        color.a -= 5;
    } else if (rpg->scene == COMBAT && color.a == 0)
        rpg->combat->transition_ow = false;
    sfRectangleShape_setFillColor(e->rect, color);
    sfClock_restart(e->clock);
}
