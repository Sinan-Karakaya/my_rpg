/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverse string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int length = 0;
    char c;

    while (str[length] != '\0')
        length++;
    for (; i < length; i++) {
        length--;
        c = str[i];
        str[i] = str[length];
        str[length] = c;
    }
    return str;
}
