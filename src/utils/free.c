/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free
*/

#include <stdlib.h>
#include "my_rpg.h"

void free_rpg(rpg_t *rpg)
{
    sfRenderWindow_destroy(rpg->window);
    free(rpg);
}
