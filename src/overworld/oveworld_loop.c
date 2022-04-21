/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** overworld loop
*/

#include "my_rpg.h"

void get_dir(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed) {
        if ((rpg->event.key.code == sfKeyDown ||
        rpg->event.key.code == sfKeyUp) && OW->was_looking_right)
            OW->state = RPG_OW_WALK_R;
        else if ((rpg->event.key.code == sfKeyDown ||
        rpg->event.key.code == sfKeyUp) && OW->was_looking_right)
            OW->state = RPG_OW_WALK_L;
        if (rpg->event.key.code == sfKeyRight) {
            OW->state = RPG_OW_WALK_R;
            OW->was_looking_right = true;
        } if (rpg->event.key.code == sfKeyLeft) {
            OW->state = RPG_OW_WALK_L;
            OW->was_looking_right = false;
        }
    }
}

static void is_any_key_pressed(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed)
        return;
    OW->state = RPG_OW_IDLE;
}

void overworld_loop(rpg_t *rpg)
{
    is_any_key_pressed(rpg);
    animate_player_overworld(rpg);
    sfRenderWindow_drawSprite(rpg->window, OW->spr, NULL);
}
