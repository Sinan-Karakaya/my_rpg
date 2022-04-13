/*
** EPITECH PROJECT, 2021
** get nbr
** File description:
** func
*/

static int is_num(char const *str, int pos)
{
    if (str[pos] <= '9' && str[pos] >= '0')
        return 1;
    else
        return 0;
}

int my_getnbr(char const *str)
{
    int result = 0;
    int start = 0;
    int dash_nb = 0;

    for (int i = 0; str[i]; i++) {
        if (is_num(str, i) == 1) {
            start = i;
            result = str[i] - 48 +  result * 10;
        } else if (str[i] == '-')
            dash_nb++;
    }
    if (dash_nb % 2 != 0)
        return result * (-1);
    else
        return result;
}
