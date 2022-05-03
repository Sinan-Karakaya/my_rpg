/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** utils_bis
*/

static int gen_base_nbr(int nb)
{
    int result = 1;

    for (int i = 1; i <= nb; i++) {
        result *= 10;
    }
    return (result);
}

static void update_bignum(int *n, int big_num)
{
    if (big_num == 60)
        *n += 1;
}

void clearstrnbr(char *str, int len)
{
    for (int i = 0; i < len; i++)
        str[i] = '\0';
}

void loop_int_to_str(int data[], int *big_num, int *pos, char *str)
{
    int gen;
    int n;

    for (int i = data[0]; i >= 0; i--) {
        gen = gen_base_nbr(i);
        n = data[1] / gen;

        data[1] -= n * gen;
        update_bignum(&n, *big_num);
        *big_num += 1;
        if (n == 10) {
            str[*pos] = (char) 49;
            *pos += 1;
            str[*pos] = (char) 48;
        }else
            str[*pos] = (char) 48 + n;
        *pos += 1;
    }
}
