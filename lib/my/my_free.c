/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_free
*/

#include <stdlib.h>

void my_free(void *element)
{
    if (element == NULL)
        return;
    else
        free(element);
}
