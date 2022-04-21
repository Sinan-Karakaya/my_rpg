/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init player for overworld
*/

#include <stdlib.h>
#include <stdio.h>

#include "my_rpg.h"
#include "defines.h"

static void player_ow_dir(rpg_t *rpg)
{
    if (OW->state == RPG_OW_WALK_R) {
        if (OW->rect_left_i >= 5) {
            OW->rect_left_i = 0;
            OW->rect_left_w = 0;
        }
        OW->rect_left_i++;
        OW->rect_left_w++;
        OW->rect.left = player_ow_rect_l_l[OW->rect_left_i];
        OW->rect.width = player_ow_rect_w_l[OW->rect_left_w];
    } else if (OW->state == RPG_OW_WALK_L) {
        if (OW->rect_left_i >= 5) {
            OW->rect_left_i = 0;
            OW->rect_left_w = 0;
        }
        OW->rect_left_i++;
        OW->rect_left_w++;
        OW->rect.left = player_ow_rect_l_r[OW->rect_left_i];
        OW->rect.width = player_ow_rect_w_r[OW->rect_left_w];
    }
}

void animate_player_overworld(rpg_t *rpg)
{
    if (get_time(OW->clock) < 0.1f)
        return;
    if (OW->state == RPG_OW_IDLE && OW->was_looking_right) {
        OW->rect.left = 0;
        OW->rect.width = PLAYER_OW_IDLE_W;
    } else if (OW->state == RPG_OW_IDLE && !OW->was_looking_right) {
        OW->rect.left = 22;
        OW->rect.width = PLAYER_OW_IDLE_W;
    } else
        player_ow_dir(rpg);
    sfSprite_setTextureRect(OW->spr, OW->rect);
    sfRenderWindow_drawSprite(rpg->window, OW->spr, NULL);
    sfClock_restart(OW->clock);
}

int init_player_overworld(rpg_t *rpg)
{
    if (!(OW = malloc(sizeof(overworld_t))) ||
    !(OW->texture = sfTexture_createFromFile(OLBERIC_OW_PATH, NULL)))
        return 1;
    OW->spr = sfSprite_create();
    sfSprite_setTexture(OW->spr, OW->texture, sfTrue);
    sfSprite_setPosition(OW->spr, (sfVector2f){RES_X / 2, RES_Y / 2});
    sfSprite_setScale(OW->spr, (sfVector2f){2, 2});
    sfSprite_setOrigin(OW->spr,
    (sfVector2f){PLAYER_OW_IDLE_W / 2, PLAYER_OW_HEIGHT / 2});
    OW->clock = sfClock_create();
    OW->state = RPG_OW_IDLE;
    OW->was_looking_right = true;
    OW->rect_left_i = 0;
    OW->rect_left_w = 0;
    OW->rect.height = 35;
    OW->rect.top = 0;
    return 0;
}
