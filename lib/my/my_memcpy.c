/*
** EPITECH PROJECT, 2022
** lib
** File description:
** memcpy
*/

#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t len)
{
    char *d = dest;
    const char *s = src;

    while (--len > 0)
        *d++ = *s++;
    return dest;
}
