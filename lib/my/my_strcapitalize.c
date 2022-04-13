/*
** EPITECH PROJECT, 2021
** str capitalize
** File description:
** func
*/

#include "my.h"

static int my_char_islower(char const c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

static int my_char_isalpha(const char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    return str;
}
