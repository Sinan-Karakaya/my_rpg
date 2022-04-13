/*
** EPITECH PROJECT, 2021
** my_compute_power_rec.c
** File description:
** compute power recursively
*/

static int does_calcul(int nb, int p, int base)
{
    if (p > 1) {
        nb *= base;
        p--;
        return (does_calcul(nb, p, base));
    }
}

int my_compute_power_rec(int nb, int p)
{
    const int base = nb;
    long long int check;

    if (p < 0)
        return 0;
    else if (nb == 0 || p == 0)
        return 1;

    check = (does_calcul(nb, p, base));

    if (check < -2147483647 || check > 2147483647)
        return 0;

    return check;
}
