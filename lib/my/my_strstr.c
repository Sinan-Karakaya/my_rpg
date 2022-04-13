/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** func
*/

#include "my.h"

static int compare_substring(char *str, char *to_find, int i)
{
    int j = 0;
    int temp = 0;

    for (; str[i + j]; j++) {
        if (str[i + j] == to_find[j])
            temp++;
        else
            break;
    }
    if (temp == j)
        return 1;
    return 0;
}

bool my_strstr(char *str, char *to_find)
{
    int ret = -1;

    if (my_strlen(str) == 0 || my_strlen(to_find) == 0)
        return NULL;
    for (int i = 0; str[i]; i++) {
        if (str[i] == to_find[0])
            ret = compare_substring(str, to_find, i);
        if (ret == 1)
            return true;
    }
    return false;
}
