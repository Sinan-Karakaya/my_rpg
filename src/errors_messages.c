/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** errors_messages
*/

#include "my.h"
#include "unistd.h"

int error_message(char *str)
{
    write(2, str, my_strlen(str));
    return 84;
}