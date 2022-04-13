/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** display string length
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (i; str[i]; i++);
    return i;
}
