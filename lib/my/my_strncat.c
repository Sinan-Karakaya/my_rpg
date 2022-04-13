/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** func
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int size_dest = my_strlen(dest);
    int i = 0;

    for (i = 0; i < nb && src[i] != '\0'; i++)
        dest[size_dest + i] = src[i];
    dest[size_dest + i] = '\0';
    return dest;
}
