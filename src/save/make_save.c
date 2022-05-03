/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** make save
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "my_rpg.h"
#include "my.h"

static void write_save(const int fd, rpg_t *rpg)
{
    char *level = int_to_str(rpg->combat->player->stat->level);
    char *xp = int_to_str(rpg->combat->player->stat->xp);
    char *health = int_to_str(rpg->combat->player->life);
    char *class = int_to_str(rpg->combat->player->stat->class);

    level = my_strcat("lvl:", level);
    xp = my_strcat("xp:", xp);
    health = my_strcat("health:", health);
    class = my_strcat("class:", class);
    write(fd, level, my_strlen(level));
    write(fd, "\n", 1);
    write(fd, xp, my_strlen(xp));
    write(fd, "\n", 1);
    write(fd, health, my_strlen(health));
    write(fd, "\n", 1);
    write(fd, class, my_strlen(class));
}

void save_game(rpg_t *rpg)
{
    int fd = open(".save", O_CREAT | O_WRONLY);

    if (fd == -1) {
        ERROR(".save");
        return;
    }
    write_save(fd, rpg);
    close(fd);
    return;
}
