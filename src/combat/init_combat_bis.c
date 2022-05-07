/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init bis
*/

#include <stdlib.h>

#include "my_rpg.h"

static int assign_ennemy_stat(entity_t *e, char *name, int id)
{
    e->clock = sfClock_create();
    e->stat = malloc(sizeof(stats_t));
    if (!e->stat)
        return 84;
    if (id == 0) {
        e->life = 1000, e->max_life = 1000;
        e->is_npc = true, e->stat->attack = 20;
        e->stat->defense = 10, e->name = name;
    } if (id == 1) {
        e->life = 230, e->max_life = 230;
        e->is_npc = true, e->stat->attack = 12;
        e->stat->defense = 8, e->name = name;
    } if (id == 2) {
        e->life = 160, e->max_life = 160;
        e->is_npc = true, e->stat->attack = 8;
        e->stat->defense = 6, e->name = name;
    }
    init_gauge_bar(e);
    return 0;
}

static void create_ennemy_bis(entity_t *e, char *name, int id)
{
    if (id == 1) {
        e->pos = (sfVector2f){RES_X / 5, RES_Y / 2 + 20};
        e->rect = (sfIntRect){0, 0, BEAR_WIDTH, BEAR_HEIGHT};
        sfSprite_setTextureRect(e->sprite, e->rect);
    } if (id == 2) {
        e->pos = (sfVector2f){RES_X / 5 + 20, RES_Y / 2 + 100};
        e->rect = (sfIntRect){0, 0, WOLF_WIDTH, WOLF_HEIGHT};
        sfSprite_setTextureRect(e->sprite, e->rect);
    }
}

int create_ennemy(entity_t *e, char *name, char *path, int id)
{
    e->texture = sfTexture_createFromFile(path, NULL);
    if (!(e->sprite = sfSprite_create()) || !e->texture)
        return 84;
    sfSprite_setTexture(e->sprite, e->texture, 1);
    if (id == 0) {
        e->pos = (sfVector2f){RES_X / 5, RES_Y / 3};
        e->rect = (sfIntRect){0, 0, BOSS_WIDTH, BOSS_HEIGHT};
        sfSprite_setTextureRect(e->sprite, e->rect);
    } create_ennemy_bis(e, name, id);
    sfSprite_setPosition(e->sprite, e->pos);
    sfSprite_setScale(e->sprite, (sfVector2f){2, 2});
    if (assign_ennemy_stat(e, name, id))
        return 84;
    return 0;
}

static int create_player_bis(combat_t *com)
{
    com->player->cmb_state = RPG_COMBAT_PLAYER_IDLE;
    com->state = RPG_COMBAT_PENDING;
    com->player->is_npc = false;
    com->player->stat = malloc(sizeof(stats_t));
    if (!com->player->stat)
        return 84;
    com->player->stat->attack = 40, com->player->stat->defense = 20;
    com->player->stat->life = 100, com->player->stat->level = 1;
    com->player->stat->xp = 0, com->player->stat->text_attack = NULL;
    com->player->stat->text_defense = NULL;
    com->player->stat->text_life = NULL;
    com->player->stat->text_level = NULL;
    com->player->stat->class = -1;
    com->player->name = "player";
    com->player->stat->xp_needed = 20;
    return 0;
}

int create_player(combat_t *com)
{
    com->player->sprite = sfSprite_create();
    com->player->texture = sfTexture_createFromFile(OLBERIC_CL_PATH, NULL);
    if (!com->player->sprite || !com->player->texture)
        return 84;
    sfSprite_setTexture(com->player->sprite, com->player->texture, sfTrue);
    com->player->pos = (sfVector2f){RES_X / 1.5, RES_Y / 1.7};
    sfSprite_setPosition(com->player->sprite, com->player->pos);
    com->player->rect = (sfIntRect){687, 0, OLBERIC_WIDTH, OLBERIC_HEIGHT};
    sfSprite_setTextureRect(com->player->sprite, com->player->rect);
    sfSprite_setScale(com->player->sprite, (sfVector2f){2.5, 2.5});
    com->player->clock = sfClock_create();
    com->player->rect_left_i = 0, com->player->rect_left_w = 0;
    com->player->life = 100, com->player->max_life = 100;
    if (create_player_bis(com) || init_gauge_bar(com->player) ||
    init_slash(com))
        return 84;
    return 0;
}
