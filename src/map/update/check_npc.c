/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update npc
*/

#include "my_rpg.h"
#include <math.h>

const char *catch_line[] = {""
, "Welcome Hero, if we summoned you in those trying times, it's because we need\
your help.\nThe village was attacked by a Valkyrie.\n\
We need you to end her reign of terror!\n \
Go see the damages at the village by yourself, at the North-East."
, "Welcome Hero, as you can see our village is quite in a sorry state.\n\
The monsters are preventing us from getting wood to repair our village.\n \
Do you think you could take care of it ?\nYou'll find them in the forest \
at the West from the village."
, "Test4"
, "Test5"};

static void chech_quest_bis(rpg_t *rpg, int type)
{
    if (type == rpg->world->gui.actual_quest + 1)
        rpg->world->gui.actual_quest = type;
    sfRenderWindow_drawSprite(rpg->window, rpg->world->gui.chatbox_sprite,
    NULL);
    sfText_setString(rpg->world->gui.text, catch_line[type]);
    sfRenderWindow_drawText(rpg->window, rpg->world->gui.text, NULL);
}

void check_quest(rpg_t *rpg)
{
    sfVector2f pos;
    float distance;
    int **height = rpg->world->height_map ;
    int type;
    sfVector2i p;

    for (int j = 0; j < NB_NPC - 1; j++) {
        p = rpg->world->npc_list[j].pos;
        type = rpg->world->npc_list[j].type;
        pos = to2d((sfVector3f){p.x, height[p.x][p.y], p.y}, rpg);
        distance = sqrt(pow(960 - pos.x, 2) + pow(540 - pos.y, 2));
        if (distance < 150) {
            chech_quest_bis(rpg, type);
        }
    }
}
