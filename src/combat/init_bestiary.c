/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "my.h"

int create_bear(combat_t *com)
{
    com->ennemy[1] = malloc(sizeof(entity_t));
    com->ennemy[1]->sprite = sfSprite_create();
    com->ennemy[1]->texture = sfTexture_createFromFile(BEAR_PATH, NULL);
    sfSprite_setTexture(com->ennemy[1]->sprite, com->ennemy[1]->texture,
    sfTrue);
    com->ennemy[1]->pos = (sfVector2f){RES_X / 5, RES_Y / 2 + 20};
    sfSprite_setPosition(com->ennemy[1]->sprite, com->ennemy[1]->pos);
    com->ennemy[1]->rect = (sfIntRect){0, 0, BEAR_WIDTH, BEAR_HEIGHT};
    sfSprite_setTextureRect(com->ennemy[1]->sprite, com->ennemy[1]->rect);
    sfSprite_setScale(com->ennemy[1]->sprite, (sfVector2f){2, 2});
    com->ennemy[1]->clock = sfClock_create();
    com->ennemy[1]->life = 230;
    com->ennemy[1]->max_life = 230;
    com->ennemy[1]->is_npc = true;
    com->ennemy[1]->stat = malloc(sizeof(stats_t));
    com->ennemy[1]->stat->attack = 12;
    com->ennemy[1]->stat->defense = 8;
    com->ennemy[1]->name = my_calloc(sizeof(char), 5);
    com->ennemy[1]->name = "bear";
    init_gauge_bar(com->ennemy[1]);
    return 0;
}

int create_wolf(combat_t *com)
{
    com->ennemy[2] = malloc(sizeof(entity_t));
    com->ennemy[2]->sprite = sfSprite_create();
    com->ennemy[2]->texture = sfTexture_createFromFile(WOLF_PATH, NULL);
    sfSprite_setTexture(com->ennemy[2]->sprite, com->ennemy[2]->texture,
    sfTrue);
    com->ennemy[2]->pos = (sfVector2f){RES_X / 5 + 20, RES_Y / 2 + 100};
    sfSprite_setPosition(com->ennemy[2]->sprite, com->ennemy[2]->pos);
    com->ennemy[2]->rect = (sfIntRect){0, 0, WOLF_WIDTH, WOLF_HEIGHT};
    sfSprite_setTextureRect(com->ennemy[2]->sprite, com->ennemy[2]->rect);
    sfSprite_setScale(com->ennemy[2]->sprite, (sfVector2f){2, 2});
    com->ennemy[2]->clock = sfClock_create();
    com->ennemy[2]->life = 160;
    com->ennemy[2]->max_life = 160;
    com->ennemy[2]->is_npc = true;
    com->ennemy[2]->stat = malloc(sizeof(stats_t));
    com->ennemy[2]->stat->attack = 8;
    com->ennemy[2]->stat->defense = 6;
    com->ennemy[2]->name = my_calloc(sizeof(char), 5);
    com->ennemy[2]->name = "wolf";
    init_gauge_bar(com->ennemy[2]);
    return 0;
}

void spawn_ennemy(rpg_t *rpg)
{
    if (!cmb_is_in_bounds(rpg->cam))
        return;
    if (IN_OVERWORLD && (rand() % 1000000) < 3) {
        rpg->combat->transition_ow = true;
        rpg->combat->curr_ennemy = rpg->combat->ennemy[rand() % 2 + 1];
    } else if (rpg->scene == COMBAT) {
        rpg->combat->transition_cmb = true;
    }
}
