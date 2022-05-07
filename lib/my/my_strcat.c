/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** func
*/

#include <stdlib.h>

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *ret = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 2);

    if (!ret)
        return (NULL);
    my_memset(ret, 0, my_strlen(dest) + my_strlen(src) + 2);
    for (; dest[i]; i++)
        ret[i] = dest[i];
    for (; src[j]; i++ && j++)
        ret[i] = src[j];
    ret[i + 1] = '\0';
    return ret;
}
