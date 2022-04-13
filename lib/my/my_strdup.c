/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** my_strdup_file
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *str = my_calloc(1, sizeof(char) * my_strlen(src) + 1);

    if (str == NULL)
        return NULL;
    for (int i = 0; src[i]; i++)
        str[i] = src[i];
    return str;
}
