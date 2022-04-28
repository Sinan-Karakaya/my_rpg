/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load map
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"

char *csv_reader(char *string)
{
    FILE *file = fopen(string, "r");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL)
        return NULL;
    code = malloc(sizeof(char) * (MAP_X * MAP_Y) * 4);
    if (!code)
        return NULL;
    while ((c = fgetc(file)) != EOF)
        code[n++] = (char) c;
    code[n] = '\0';
    return code;
}

int **str_to_int_tab(char *string)
{
    int **map = create_map(MAP_X, MAP_Y);
    char *code;
    int i = 0;
    int j = 0;
    int k = 0;
    int actual_number = 0;

    if ((code = csv_reader(string)) == NULL)
        return map;
    while (code[k] != '\0') {
        if (code[k] == '\n') {
            map[i][j] = 17;
            actual_number = 0;
            k++;
            i++;
            j = 0;
        } if (code[k] == ',') {
            map[i][j] = actual_number;
            actual_number = 0;
            j++;
            k++;
        } actual_number *= 10;
        actual_number += code[k] - '0';
        k++;
    }
    return map;
}

int **str_to_int_tab_bis(char *string)
{
    int **map = create_map(MAP_X, MAP_Y);
    char *code;
    int i = 0;
    int j = 0;
    int k = 0;
    int actual_number = 0;

    if ((code = csv_reader(string)) == NULL)
        return map;
    while (code[k] != '\0') {
        if (code[k] == '\n') {
            map[i][j] = 0;
            actual_number = 0;
            k++;
            i++;
            j = 0;
        } if (code[k] == ',') {
            map[i][j] = -actual_number;
            actual_number = 0;
            j++;
            k++;
        } actual_number *= 10;
        actual_number += code[k] - '0';
        k++;
    }
    return map;
}
