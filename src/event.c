/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event
*/

#include "my_rpg.h"

void player_movement(rpg_t *rpg)
{
    if (rpg->event.key.code == KEYDOWN && IN_OVERWORLD) {
        if (rpg->ow_can_move)
        rpg->cam.y -= 600 * rpg->dt;
        else
            rpg->cam.y += 600 * rpg->dt;
    } if (rpg->event.key.code == KEYUP && IN_OVERWORLD) {
        if (rpg->ow_can_move)
            rpg->cam.y += 600 * rpg->dt;
        else
            rpg->cam.y -= 600 * rpg->dt;
    } if (rpg->event.key.code == KEYRIGHT && IN_OVERWORLD) {
        if (rpg->ow_can_move)
            rpg->cam.x += 2000 * rpg->dt;
        else
            rpg->cam.x -= 2000 * rpg->dt;
    } if (rpg->event.key.code == KEYLEFT && IN_OVERWORLD) {
        if (rpg->ow_can_move)
            rpg->cam.x -= 2000 * rpg->dt;
        else
            rpg->cam.x += 2000 * rpg->dt;
    }
}

void key_pressed(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyEscape) {
        rpg->menu->option->is_active = true;
        rpg->menu->option->is_main = true;
    }
    if (rpg->event.key.code == KEYINV) {
        rpg->menu->option->is_active = true;
        rpg->menu->is_inventory = true;
    }
    player_movement(rpg);
    // ------------------ DEBUG ------------------------
    if (rpg->event.key.code == sfKeyC) {
        if (IN_OVERWORLD) {
            rpg->scene = COMBAT;
            rpg->cam.r = 0;
        } else if (rpg->scene == COMBAT) {
            rpg->scene = OVERWORLD;
            rpg->cam.r = 2;
        }
    }
}

int event(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtClosed) {
        sfRenderWindow_close(rpg->window);
        return 1;
    }
    if (rpg->event.type == sfEvtMouseButtonPressed)
        buttons_controls_option_ig(rpg, BUTTONSO, rpg->event);
    if (rpg->event.type == sfEvtKeyPressed)
        key_pressed(rpg);
    if (IN_OVERWORLD)
        get_dir(rpg);
    return 0;
}