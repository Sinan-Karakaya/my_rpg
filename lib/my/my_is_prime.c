/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** check if number is prime
*/

int my_is_prime(int nb)
{
    if (nb <= 2)
        return 0;

    for (int i = 2; i != 9; i++) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
