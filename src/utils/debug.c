/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** print_debug
*/

#include <stdlib.h>

#include "my.h"
#include "my_rpg.h"

char *convert_to_str(float fl)
{
    char *result;
    int num = fl;
    int temp;
    int origin = num;
    int count = 1;
    int i = 0;

    while (origin > 9) {
        count++;
        origin /= 10;
    }
    result = malloc(sizeof(int) * count);
    for (; i != count; i++) {
        temp = num % 10;
        num /= 10;
        result[i] = temp + 48;
    }
    result[i] = '\0';
    return my_revstr(result);
}
/*
static void print_hitboxes(rpg_t *rpg)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f player_scale = sfSprite_getScale(rpg->combat->player->sprite);

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfRed);
    sfRectangleShape_setOutlineThickness(rect, 1);

    sfRectangleShape_setPosition(rect, rpg->combat->player->pos);
    sfRectangleShape_setSize(rect, (sfVector2f){
    rpg->combat->player->rect.width * player_scale.x,
    rpg->combat->player->rect.height * player_scale.y});

    sfRenderWindow_drawRectangleShape(rpg->window, rect, NULL);
}
*/

void print_debug(rpg_t *rpg)
{
    if (!rpg->debug_toggle)
        return;
    sfText_setString(rpg->debug->text, my_strcat("FPS: ",
    convert_to_str(rpg->dt * 1000)));
    sfRenderWindow_drawText(rpg->window, rpg->debug->text, NULL);
}
