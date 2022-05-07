/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** gauge
*/

#include <stdlib.h>

#include "my_rpg.h"
#include "my.h"

static int init_second_gauge(entity_t *entity)
{
    sfRectangleShape_setFillColor(entity->bar->rect, entity->bar->color);
    sfRectangleShape_setPosition(entity->bar->rect, entity->bar->pos);
    sfRectangleShape_setSize(entity->bar->rect, entity->bar->size);
    entity->bar->rect_grey = sfRectangleShape_create();
    if (!entity->bar->rect_grey)
        return 84;
    entity->bar->grey_color = sfColor_fromRGB(175, 164, 162);
    sfRectangleShape_setFillColor(entity->bar->rect_grey,
    entity->bar->grey_color);
    sfRectangleShape_setPosition(entity->bar->rect_grey,
    (sfVector2f){entity->bar->pos.x + entity->bar->size.x,
    entity->bar->pos.y});
    if (!entity->is_npc || my_strcmp(entity->name, "boss") != 0) {
        sfRectangleShape_setSize(entity->bar->rect_grey,
        (sfVector2f){entity->max_life - entity->life, 10});
    } else{
        sfRectangleShape_setSize(entity->bar->rect_grey,
        (sfVector2f){(entity->max_life - entity->life) / 5, 10});
    }
    return 0;
}

int init_gauge_bar(entity_t *entity)
{
    if (!(entity->bar = malloc(sizeof(gauge_bar_t))))
        return 84;
    entity->bar->rect = sfRectangleShape_create();
    if (!entity->bar->rect)
        return 84;
    entity->bar->color = sfColor_fromRGB(0, 255, 0);
    entity->bar->pos = (sfVector2f){entity->pos.x + (entity->rect.width / 2)
    - 10, entity->pos.y + entity->rect.height + 90};
    if (!entity->is_npc) {
        entity->bar->size = (sfVector2f){entity->max_life, 10};
        entity->bar->pos.x -= 22;
    } else if (my_strcmp(entity->name, "boss") == 0) {
        entity->bar->pos.y += 150, entity->bar->pos.x -= 60;
        entity->bar->size = (sfVector2f){entity->max_life / 5, 10};
    } else {
        entity->bar->pos.x -= 20;
        entity->bar->size = (sfVector2f){entity->max_life, 10};
    }
    if (my_strcmp(entity->name, "bear") == 0)
        entity->bar->pos.x -= 60, entity->bar->pos.y += 20;
    if (init_second_gauge(entity))
        return 84;
    return 0;
}

static void display_update_gauge(entity_t *player, entity_t *ennemy)
{
    player->bar->size = (sfVector2f){player->life, 10};
    (my_strcmp(ennemy->name, "boss") == 0) ?
    (ennemy->bar->size = (sfVector2f){ennemy->life / 5, 10}) :
    (ennemy->bar->size = (sfVector2f){ennemy->life, 10});
    sfRectangleShape_setSize(player->bar->rect, player->bar->size);
    sfRectangleShape_setSize(player->bar->rect_grey,
    (sfVector2f){player->max_life - player->life, 10});
    sfRectangleShape_setSize(ennemy->bar->rect, ennemy->bar->size);
    if (my_strcmp(ennemy->name, "boss") == 0) {
        sfRectangleShape_setSize(ennemy->bar->rect_grey,
        (sfVector2f){(ennemy->max_life - ennemy->life) / 5, 10});
    } else {
        sfRectangleShape_setSize(ennemy->bar->rect_grey,
        (sfVector2f){(ennemy->max_life - ennemy->life), 10});
    } sfRectangleShape_setPosition(player->bar->rect_grey,
    (sfVector2f){player->bar->pos.x + player->bar->size.x,
    player->bar->pos.y});
    sfRectangleShape_setPosition(ennemy->bar->rect_grey,
    (sfVector2f){(ennemy->bar->pos.x + ennemy->bar->size.x),
    ennemy->bar->pos.y});
}

static void update_gauge(entity_t *player, entity_t *ennemy, combat_t *combat)
{
    if (player->life > player->max_life)
        player->life = player->max_life;
    if (player->life < 0) {
        player->life = 0;
        player->cmb_state = RPG_COMBAT_PLAYER_DEATH;
    } if (ennemy->life < 0) {
        ennemy->life = 0;
        combat->state = RPG_COMBAT_WIN;
    } display_update_gauge(player, ennemy);
}

void draw_hud(rpg_t *rpg, entity_t *player, entity_t *ennemy)
{
    update_gauge(player, ennemy, rpg->combat);
    sfRenderWindow_drawSprite(rpg->window, rpg->combat->hud->sprite, NULL);
    sfRenderWindow_drawRectangleShape(rpg->window, player->bar->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->window, player->bar->rect_grey,
    NULL);
    sfRenderWindow_drawRectangleShape(rpg->window, ennemy->bar->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->window, ennemy->bar->rect_grey,
    NULL);
}
