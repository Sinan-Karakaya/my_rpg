/*
** EPITECH PROJECT, 2021
** string n copy
** File description:
** copy n char on string
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    unsigned int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > my_strlen(src))
        dest[i] = '\0';
    return dest;
}
