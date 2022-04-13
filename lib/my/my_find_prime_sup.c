/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** find the superior prime number
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) == 0) {
        nb++;
    }
    return nb;
}
