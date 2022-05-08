/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event
*/

#include <stdio.h>
#include <stdlib.h>

#include "my_rpg.h"

static void player_movement_bis(rpg_t *rpg)
{
    if (rpg->event.key.code == KEYRIGHT && IN_OVERWORLD &&
    cam_is_in_bounds(rpg->cam.x + 40, rpg->cam.y) && ow_aabb(rpg,
    (sfVector2f){-5, -30}) == 0) {
        rpg->cam.x += 800 * rpg->dt;
        spawn_ennemy(rpg);
    } if (rpg->event.key.code == KEYLEFT && IN_OVERWORLD &&
    cam_is_in_bounds(rpg->cam.x - 40, rpg->cam.y) && ow_aabb(rpg,
    (sfVector2f){5, -30}) == 0) {
        rpg->cam.x -= 800 * rpg->dt;
        spawn_ennemy(rpg);
    }
}

static void player_movement(rpg_t *rpg)
{
    if (rpg->event.key.code == KEYDOWN && IN_OVERWORLD &&
    cam_is_in_bounds(rpg->cam.x, rpg->cam.y - 40) && ow_aabb(rpg,
    (sfVector2f){0, -40}) == 0) {
        rpg->cam.y -= 200 * rpg->dt;
        spawn_ennemy(rpg);
    } if (rpg->event.key.code == KEYUP && IN_OVERWORLD &&
    cam_is_in_bounds(rpg->cam.x, rpg->cam.y + 40) && ow_aabb(rpg,
    (sfVector2f){0, -20}) == 0) {
        rpg->cam.y += 200 * rpg->dt;
        spawn_ennemy(rpg);
    } player_movement_bis(rpg);
}

static void debug_key_pressed(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyC) {
        if (IN_OVERWORLD) {
            rpg->combat->transition_ow = true;
            rpg->combat->curr_ennemy = rpg->combat->ennemy[rand() % 2 + 1];
        } else if (rpg->scene == COMBAT) {
            rpg->combat->transition_cmb = true;
        }
    }
    if (rpg->event.key.code == sfKeyV) {
        if (IN_OVERWORLD) {
            rpg->combat->transition_ow = true;
            rpg->combat->curr_ennemy = rpg->combat->ennemy[0];
        } else if (rpg->scene == COMBAT) {
            rpg->combat->transition_cmb = true;
        }
    }
}

static void key_pressed(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyEscape) {
        rpg->menu->option->is_active = true;
        rpg->menu->option->is_main = true;
    } if (rpg->event.key.code == KEYINV) {
        if (rpg->menu->is_inventory == false) {
            rpg->menu->option->is_active = true;
            rpg->menu->is_inventory = true;
            sfSprite_setPosition(OW->spr, (sfVector2f){430, 330});
            sfSprite_setScale(OW->spr, (sfVector2f){6, 6});
            OW->rect.left = 0;
            sfSprite_setTextureRect(OW->spr, OW->rect);
        } else {
            rpg->menu->option->is_active = false;
            rpg->menu->is_inventory = false;
            sfSprite_setPosition(OW->spr, (sfVector2f){RES_X / 2, RES_Y / 2});
            sfSprite_setScale(OW->spr, (sfVector2f){2, 2});
        }
    } if (!rpg->combat->transition_ow)
        player_movement(rpg);
    debug_key_pressed(rpg);
}

int event(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtClosed) {
        sfRenderWindow_close(rpg->window);
        return 1;
    }
    if (rpg->event.type == sfEvtMouseButtonPressed) {
        buttons_controls_option_ig(rpg, BUTTONSO, rpg->event);
        slots_controls(rpg, rpg->event);
    }
    if (rpg->event.type == sfEvtKeyPressed && rpg->scene != CINEMATIC &&
    !rpg->cine->transition)
        key_pressed(rpg);
    if (IN_OVERWORLD)
        get_dir(rpg);
    return 0;
}
