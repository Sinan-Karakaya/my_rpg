/*
** EPITECH PROJECT, 2022
** lib
** File description:
** strsep
*/

#include <stdlib.h>
#include <stdio.h>

static char *look_for(char *str, int i, const char *delim, char **saveptr)
{
    for (int j = 0; delim[j]; j++) {
        if (str[i] == delim[j]) {
            str[i] = '\0';
            if (saveptr)
                *saveptr = &str[i + 1];
            return str;
        } else if (str[i + 1] == '\0') {
            if (saveptr)
                *saveptr = NULL;
            return str;
        }
    }
    return NULL;
}

char *my_strsep(char *str, const char *delim, char **saveptr)
{
    for (int i = 0; str[i]; i++)
        if (look_for(str, i, delim, saveptr) != NULL)
            return str;
    return NULL;
}
