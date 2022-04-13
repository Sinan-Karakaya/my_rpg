/*
** EPITECH PROJECT, 2021
** my_concat_params
** File description:
** my_concat_params
*/

#include <stdlib.h>

#include "my.h"

char *concat_params(int argc, char **argv)
{
    char *str;
    int max_size = 0;

    for (int j = 0; j < argc; j++)
        max_size += my_strlen(argv[j]);

    str = malloc(sizeof(char) * (max_size + 1));

    for (int count = 0; count < argc; count++) {
        my_strcat(str, argv[count]);
        my_strcat(str, "\n");
    }
    return str;
}
