/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** combat main file
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

static int create_ennemy(entity_t *e, char *name, char *path, int id)
{
    e->sprite = sfSprite_create();
    e->texture = sfTexture_createFromFile(path, NULL);
    if (!e->sprite || !e->texture)
        return 84;
    sfSprite_setTexture(e->sprite, e->texture, 1);
    if (id == 0) {
        e->pos = (sfVector2f){RES_X / 5, RES_Y / 3};
        e->rect = (sfIntRect){0, 0, BOSS_WIDTH, BOSS_HEIGHT};
        sfSprite_setTextureRect(e->sprite, e->rect);
    } if (id == 1) {
        e->pos = (sfVector2f){RES_X / 5, RES_Y / 2 + 20};
        e->rect = (sfIntRect){0, 0, BEAR_WIDTH, BEAR_HEIGHT};
        sfSprite_setTextureRect(e->sprite, e->rect);
    } if (id == 2) {
        e->pos = (sfVector2f){RES_X / 5 + 20, RES_Y / 2 + 100};
        e->rect = (sfIntRect){0, 0, WOLF_WIDTH, WOLF_HEIGHT};
        sfSprite_setTextureRect(e->sprite, e->rect);
    } sfSprite_setPosition(e->sprite, e->pos);
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
    com->player->stat->attack = 10, com->player->stat->defense = 10;
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

static int create_player(combat_t *com)
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

int init_combat(rpg_t *rpg)
{
    rpg->combat = malloc(sizeof(combat_t));
    if (!rpg->combat)
        return 84;
    rpg->combat->ennemy = malloc(sizeof(entity_t *));
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
    return 0;
}
