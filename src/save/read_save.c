/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** read save file
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "my_rpg.h"
#include "my.h"

static void assign_stat(rpg_t *rpg, char *type, char *value)
{
    if (my_strcmp(type, "level") == 0)
        rpg->combat->player->stat->level = my_getnbr(value);
    if (my_strcmp(type, "health") == 0)
        rpg->combat->player->life = my_getnbr(value);
    if (my_strcmp(type, "class") == 0 && my_getnbr(value) >= 0 &&
    my_getnbr(value) < 3)
        rpg->combat->player->stat->class = my_getnbr(value);
}

static void parse_save(rpg_t *rpg, char *buffer)
{
    char **arr = my_str_to_word_array(buffer);
    char *saveptr = NULL;

    if (!arr)
        return;
    for (size_t i = 0; arr[i]; i++) {
        my_strsep(arr[i], ":", &saveptr);
        assign_stat(rpg, arr[i], saveptr);
    }
}

bool read_save(rpg_t *rpg)
{
    int fd = open(".save", O_RDONLY);
    char *buffer = NULL;

    if (fd == -1)
        return (false);
    buffer = my_calloc(1024, sizeof(char));
    if ((read(fd, buffer, 1024)) == -1)
        return (false);
    close(fd);

    parse_save(rpg, buffer);
    return true;
}
