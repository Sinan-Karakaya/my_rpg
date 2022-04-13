/*
** EPITECH PROJECT, 2021
** string copy
** File description:
** copy string
*/

#include <stdlib.h>

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    char *ret = my_memcpy(dest, src, my_strlen(src) + 1);
    ret[my_strlen(src) + 1] = '\0';

    return ret;
}
