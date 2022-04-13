/*
** EPITECH PROJECT, 2021
** my_strnupcase
** File description:
** func
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return str;
}
