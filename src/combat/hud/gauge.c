/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** gauge
*/

#include <stdlib.h>

#include "my_rpg.h"

static void init_second_gauge(entity_t *entity)
{
    entity->bar->rect_grey = sfRectangleShape_create();
    entity->bar->grey_color = sfColor_fromRGB(175, 164, 162);
    sfRectangleShape_setFillColor(entity->bar->rect_grey,
    entity->bar->grey_color);
    sfRectangleShape_setPosition(entity->bar->rect,
    (sfVector2f){entity->bar->pos.x + entity->bar->size.x,
    entity->bar->pos.y + entity->rect.height});
    if (!entity->is_npc) {
        sfRectangleShape_setSize(entity->bar->rect_grey,
        (sfVector2f){OLBERIC_HEALTH - entity->life, 10});
    } else {
        sfRectangleShape_setSize(entity->bar->rect_grey,
        (sfVector2f){(BOSS_HEALTH - entity->life) / 10, 10});
    }
}

int init_gauge_bar(entity_t *entity)
{
    if (!(entity->bar = malloc(sizeof(gauge_bar_t))))
        return 1;
    entity->bar->rect = sfRectangleShape_create();
    entity->bar->color = sfColor_fromRGB(0, 255, 0);
    entity->bar->pos = (sfVector2f){entity->pos.x - 25, entity->pos.y +
    entity->rect.height + 90};
    if (!entity->is_npc)
        entity->bar->size = (sfVector2f){entity->life, 10};
    else
        entity->bar->size = (sfVector2f){entity->life / 10, 10};
    sfRectangleShape_setFillColor(entity->bar->rect, entity->bar->color);
    sfRectangleShape_setPosition(entity->bar->rect, entity->bar->pos);
    sfRectangleShape_setSize(entity->bar->rect, entity->bar->size);
    init_second_gauge(entity);
    return 0;
}

static void update_gauge(entity_t *player, entity_t *ennemy)
{
    if (player->life > 100)
        player->life = 100;
    player->bar->size = (sfVector2f){player->life, 10};
    ennemy->bar->size = (sfVector2f){ennemy->life / 10, 10};
    sfRectangleShape_setSize(player->bar->rect, player->bar->size);
    sfRectangleShape_setSize(player->bar->rect_grey,
    (sfVector2f){OLBERIC_HEALTH - player->life, 10});
    sfRectangleShape_setSize(ennemy->bar->rect, ennemy->bar->size);
    sfRectangleShape_setSize(ennemy->bar->rect_grey,
    (sfVector2f){(BOSS_HEALTH - ennemy->life) / 10, 10});
}

void draw_hud(rpg_t *rpg, entity_t *player, entity_t *ennemy)
{
    update_gauge(player, ennemy);
    sfRenderWindow_drawSprite(rpg->window, rpg->combat->hud->sprite, NULL);
    sfRenderWindow_drawRectangleShape(rpg->window, player->bar->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->window, player->bar->rect_grey,
    NULL);
    sfRenderWindow_drawRectangleShape(rpg->window, ennemy->bar->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->window, ennemy->bar->rect_grey,
    NULL);
}
