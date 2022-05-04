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

static void make_inventory(rpg_t *rpg, char *value)
{
    int index = 0;

    if (my_strlen(value) != 34)
        return;
    for (int i = 0; i < 34; i++) {
        if (value[i] >= '1' && value[i] <= '8') {
            INVENTORY->slots[i]->item_id = value[i] - '0';
            index++;
        } else {
            break;
        }
    }
}

static void set_pos(rpg_t *rpg, char *value)
{
    char *saveptr = NULL;

    my_strsep(value, ",", &saveptr);
    rpg->cam.x = my_getnbr(value);
    rpg->cam.y = my_getnbr(saveptr);
}

static int assign_stat(rpg_t *rpg, char *type, char *value)
{
    if (my_strcmp(type, "level") == 0)
        STAT->level = my_getnbr(value);
    if (my_strcmp(type, "health") == 0)
        rpg->combat->player->life = my_getnbr(value);
    if (my_strcmp(type, "class") == 0 && my_getnbr(value) >= 0 &&
    my_getnbr(value) < 3)
        STAT->class = my_getnbr(value);
    if (my_strcmp(type, "inventory") == 0) {
        make_inventory(rpg, value);
        return 1;
    } if (my_strcmp(type, "pos") == 0)
        set_pos(rpg, value);
    if (my_strcmp(type, "max_health") == 0)
        rpg->combat->player->max_life = my_getnbr(value);
    if (my_strcmp(type, "attack") == 0)
        STAT->attack = my_getnbr(value);
    if (my_strcmp(type, "defense") == 0)
        STAT->defense = my_getnbr(value);
    return 0;
}

static void parse_save(rpg_t *rpg, char *buffer)
{
    char **arr = my_str_to_word_array(buffer);
    char *saveptr = NULL;

    if (!arr)
        return;
    for (size_t i = 0; arr[i]; i++) {
        my_strsep(arr[i], ":", &saveptr);
        if (assign_stat(rpg, arr[i], saveptr))
            break;
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
