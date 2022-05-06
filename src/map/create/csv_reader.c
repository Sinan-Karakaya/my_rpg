/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load map
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my.h"

int get_file_size(char const *filepath)
{
    struct stat stats;

    if (stat(filepath, &stats) == -1)
        return (-1);
    return (stats.st_size);
}

static char *csv_reader(char const *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL)
        return NULL;
    code = my_calloc(sizeof(char), (MAP_X * MAP_Y) * 4);
    if (!code)
        return NULL;
    while ((c = fgetc(file)) != EOF)
        code[n++] = (char) c;
    code[n] = '\0';
    return code;
}

int **str_to_int_tab(char *string, int n, int case_)
{
    int **map = create_map(MAP_X, MAP_Y);
    char *code = csv_reader(string);
    int i = 0, j = 0, k = 0, actual_number = 0;

    if (code == NULL)
        return map;
    while (code[k] != '\0') {
        if (code[k] == '\n') {
            map[i][j] = case_;
            actual_number = 0, j = 0;
            k++, i++;
        } if (code[k] == ',') {
            map[i][j] = actual_number * n;
            actual_number = 0;
            j++, k++;
        }
        actual_number = actual_number * 10 + code[k] - '0';
        k++;
    }
    return map;
}
