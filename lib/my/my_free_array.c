/*
** EPITECH PROJECT, 2022
** lib
** File description:
** free array
*/

#include <stdlib.h>

void my_free_array(void **arr)
{
    if (!arr)
        return;
    for (unsigned int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}
