/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** behave like func
*/

#include "my.h"
#include <stdlib.h>

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] || s2[i]) {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
        i++;
    }
    return 0;
}
