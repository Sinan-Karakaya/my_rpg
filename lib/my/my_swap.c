/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** swap values of 2 var
*/

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
