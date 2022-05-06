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

static void save_inventory(const int fd, rpg_t *rpg)
{
    write(fd, "inventory:", 10);
    for (int i = 0; i < 34; i++) {
        if (INVENTORY->slots[i]->item_id <= 8)
            write(fd, int_to_str(INVENTORY->slots[i]->item_id), 1);
    }
    write(fd, "\n", 1);
}

static void save_pos(const int fd, rpg_t *rpg)
{
    write(fd, "pos:", 4);
    write(fd, int_to_str((int)rpg->cam.x), my_strlen(int_to_str(
    (int)rpg->cam.x)));
    write(fd, ",", 1);
    write(fd, int_to_str((int)rpg->cam.y), my_strlen(int_to_str(
    (int)rpg->cam.y)));
    write(fd, "\n", 1);
}

static void save_max_health(const int fd, rpg_t *rpg)
{
    write(fd, "max_health:", 11);
    write(fd, int_to_str(rpg->combat->player->max_life),
    my_strlen(int_to_str(rpg->combat->player->max_life)));
    write(fd, "\n", 1);
    write(fd, "attack:", 7);
    write(fd, int_to_str(STAT->attack), my_strlen(int_to_str(STAT->attack)));
    write(fd, "\ndefense:", 9);
    write(fd, int_to_str(STAT->defense), my_strlen(int_to_str(STAT->defense)));
    write(fd, "\n", 1);
}

static void write_save(const int fd, rpg_t *rpg)
{
    char *level = int_to_str(STAT->level);
    char *xp = int_to_str(STAT->xp);
    char *health = int_to_str(rpg->combat->player->life);
    char *class = int_to_str(STAT->class);

    level = my_strcat("level:", level);
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
    write(fd, "\n", 1);
    save_pos(fd, rpg);
    save_max_health(fd, rpg);
    save_inventory(fd, rpg);
}

void save_game(rpg_t *rpg)
{
    int fd = open(".save", O_CREAT | O_WRONLY, 0666);

    if (fd == -1) {
        ERROR(".save");
        return;
    }
    write_save(fd, rpg);
    close(fd);
    return;
}
