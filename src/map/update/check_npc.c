/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update npc
*/

#include "my_rpg.h"
#include <math.h>

const char *catch_line[] = {"Test", "Test2", "Bonjour. VA AU VILLAGE !!!", "Test4", "Test5"};

void check_quest(rpg_t *rpg)
{
    sfVector2f pos;
    float distance;
    int **height = rpg->world->height_map ;
    sfVector2i p;
    for (int j = 0; j < NB_NPC - 1; j++) {
        p = rpg->world->npc_list[j].pos;
        pos = to2d((sfVector3f){p.x, height[p.x][p.y], p.y}, rpg);
        distance = sqrt(pow(960 - pos.x, 2) + pow(540 - pos.y, 2));
        if (distance < 150) {
            sfRenderWindow_drawSprite(rpg->window, rpg->world->gui.chatbox_sprite,
            NULL);
            sfText_setString(rpg->world->gui.text, catch_line[rpg->world->npc_list[j].type]);
            sfRenderWindow_drawText(rpg->window, rpg->world->gui.text, NULL);
        }
    }
}