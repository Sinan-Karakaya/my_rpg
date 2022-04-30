/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw npc
*/

#include "my_rpg.h"

sfVector2i get_npc_offset(int i, rpg_t *rpg)
{
    int nbr = rpg->world->npc_list[i].type;
    int size = sfTexture_getSize(rpg->world->texture_o->texture).x;
    int x_pos = 100 * (nbr % (size / 100));
    int y_pos = 100 * (nbr / (size / 100));
    sfVector2i quad_offset = {x_pos, y_pos};

    return quad_offset;
}

void draw_npc(rpg_t *rpg)
{
    sfSprite *sp = sfSprite_create();
    sfSprite_setTexture(sp, rpg->texture->texture, sfTrue);
    sfVector2i offset = {0, 0};
    sfVector2i p;
    sfVector2f *point = rpg->cam.render->point;

    for (int j = 0; j < NB_NPC - 1; j++) {
        if (rpg->world->npc_list[j].type == 0)
            continue;
        p = rpg->world->npc_list[j].pos;
        offset = get_npc_offset(j, rpg);
        point[0] = to2d((sfVector3f){p.x, HEIGHT[p.x][p.y], p.y}, rpg);
        point[1] = to2d((sfVector3f){p.x + 2, HEIGHT[p.x][p.y], p.y}, rpg);
        sfSprite_setTextureRect(sp, (sfIntRect){offset.x - 100, offset.y +
        100, 100, -100});
        sfSprite_setPosition(sp, point[0]);
        sfSprite_setScale(sp, SCALE_PNJ_X, SCALE_PNJ_Y);
        sfRenderWindow_drawSprite(rpg->window, sp, NULL);
    }
    sfSprite_destroy(sp);
}