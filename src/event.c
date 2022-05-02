/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event
*/

#include "my_rpg.h"

void player_movement(rpg_t *rpg)
{
    int multiplicator = 1;

    if (!rpg->ow_can_move)
        multiplicator = -1;
    if (rpg->debug_toggle)
        multiplicator *= 5;
    if (rpg->event.key.code == KEYDOWN && IN_OVERWORLD) {
        rpg->cam.y -= 60 * rpg->dt * multiplicator;
    } if (rpg->event.key.code == KEYUP && IN_OVERWORLD) {
        rpg->cam.y += 60 * rpg->dt * multiplicator;
    } if (rpg->event.key.code == KEYRIGHT && IN_OVERWORLD) {
        rpg->cam.x += 200 * rpg->dt * multiplicator;
    } if (rpg->event.key.code == KEYLEFT && IN_OVERWORLD) {
        rpg->cam.x -= 200 * rpg->dt * multiplicator;
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
            rpg->combat->transition_ow = true;
        } else if (rpg->scene == COMBAT) {
            rpg->combat->transition_cmb = true;
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