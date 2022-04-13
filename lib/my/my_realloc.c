/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_realloc
*/

#include <stdlib.h>

#include "my.h"

void *my_realloc(void *ptr, size_t size, size_t old_size)
{
    void *ret;

    if (!ptr)
        return NULL;
    if (size == 0) {
        my_free(ptr);
        return NULL;
    } if (!(ret = my_calloc(1, size)))
        return NULL;
    ret = my_memcpy(ret, ptr, old_size);
    return ret;
}
