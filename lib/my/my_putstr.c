/*
** EPITECH PROJECT, 2021
** putstr
** File description:
** display string
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
