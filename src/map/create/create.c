/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create map
*/

#include <stdlib.h>

#include "my_rpg.h"

int **create_map(int heigth, int width)
{
    int **map = malloc(sizeof(int *) * (heigth + 1));

    for (int i = 0; i < heigth; i++) {
        map[i] = malloc(sizeof(int) * (width + 1));
        for (int j = 0; j < width; j++)
            map[i][j] = 0;
        map[i][width] = '\0';
    }
    map[heigth] = NULL;
    return map;
}