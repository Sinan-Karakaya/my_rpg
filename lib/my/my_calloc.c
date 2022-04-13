/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_calloc
*/

#include <stdlib.h>

#include "my.h"

void *my_calloc(size_t nmemb, size_t size)
{
    void *ret = malloc(nmemb * size);

    if (ret)
        ret = my_memset(ret, 0, size);
    return ret;
}
