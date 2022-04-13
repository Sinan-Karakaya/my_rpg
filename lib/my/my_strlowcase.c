/*
** EPITECH PROJECT, 2021
** my_strlowcase
** File description:
** func
*/

char *my_strlowcase(char *s1, char *t1)
{
    for (int i = 0; s1[i]; i++) {
        if (s1[i] >= 65 && s1[i] <= 90)
            t1[i] = s1[i] + 32;
        else
            t1[i] = s1[i];
    }
    return t1;
}
