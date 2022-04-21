/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** command line arg
*/

#include <stdlib.h>

#include "my.h"
#include "my_rpg.h"

static void print_help(void)
{
    my_printf("Welcome to our RPG!\n");
}

int handle_args(int ac, char **av)
{
    if (ac <= 1)
        return 0;
    for (int j = 1; j < ac; j++) {
        if (my_strcmp(av[j], "-h") == 0 || my_strcmp(av[j], "--help") == 0) {
            print_help();
            return -1;
        } if (my_strcmp(av[j], "--debug") == 0 ||
        my_strcmp(av[j], "-d") == 0) {
            my_putstr("Debug mode activated\n");
            return 1;
        }
    }
    return 0;
}
