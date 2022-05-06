/*
** EPITECH PROJECT, 2022
** lib
** File description:
** strsep
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void assign(char **saveptr, char *str, int i, bool test)
{
    if (saveptr && test)
        *saveptr = &str[i + 1];
    if (saveptr && !test)
        *saveptr = NULL;
}

static char *look_for_it(char *str, int i, const char *delim, char **saveptr)
{
    for (int j = 0; delim[j]; j++) {
        if (str[i] == delim[j]) {
            str[i] = '\0';
            assign(saveptr, str, i, true);
            return str;
        } else if (str[i + 1] == '\0') {
            assign(saveptr, str, i, false);
            return str;
        }
    }
    return NULL;
}

char *my_strsep(char *str, const char *delim, char **saveptr)
{
    for (int i = 0; str[i]; i++)
        if (look_for_it(str, i, delim, saveptr) != NULL)
            return str;
    return NULL;
}
