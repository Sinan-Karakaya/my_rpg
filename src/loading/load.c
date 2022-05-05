/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** loop file
*/

#include <stdlib.h>
#include <stdio.h>
#include "unistd.h"
#include "my_rpg.h"

int load_loop(rpg_t *rpg, int actual_load)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    if (!rect) {
        write(2, "Error: loading bar\n", 19);
        return 84;
    }
    sfRectangleShape_setFillColor(rect, sfWhite);
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 520});
    sfRectangleShape_setSize(rect, (sfVector2f){ 0.09 * actual_load * 1920, 40});

        sfRenderWindow_clear(rpg->window, sfBlack);
        sfRenderWindow_drawRectangleShape(rpg->window, rect, NULL);
        sfRenderWindow_display(rpg->window);
    sfRectangleShape_destroy(rect);
    return 0;
}
