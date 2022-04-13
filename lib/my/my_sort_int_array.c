/*
** EPITECH PROJECT, 2021
** sort int array
** File description:
** func
*/

#include <stdlib.h>
#include <stdio.h>

static void find_for_swap(int *tab, int temp, unsigned int i, int size)
{
    for (unsigned int j = i + 1; j < size; j++) {
        if (tab[i] > tab[j]) {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
    }
}

void my_sort_int_array(int *tab, int size)
{
    int temp = 0;

    for (unsigned int i = 0; i < size; i++)
        find_for_swap(tab, temp, i, size);
    return;
}
