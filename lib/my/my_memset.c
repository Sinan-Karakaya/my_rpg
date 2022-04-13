/*
** EPITECH PROJECT, 2022
** lib
** File description:
** memset
*/

#include <stddef.h>

void *my_memset(void *dest, int value, size_t len)
{
    unsigned char *ptr = dest;

    while (len-- > 0)
        *ptr++ = value;
    return dest;
}
