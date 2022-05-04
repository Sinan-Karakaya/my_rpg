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
    int fd = open(filepath, O_RDONLY);
    int sizebuffer = get_file_size(filepath);
    int re = 0;
    char *buffer;

    if (fd == -1)
        return (NULL);
    if (sizebuffer == -1)
        return NULL;
    buffer = malloc(sizeof(char) + (sizebuffer + 1));
    re = read(fd, buffer, sizebuffer);
    if (re == 0)
        return (NULL);
    buffer[sizebuffer] = '\0';
    return (buffer);
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
