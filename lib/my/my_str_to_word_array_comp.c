/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** complementary file
*/

#include "my.h"

void my_show_word_array(char * const *tab)
{
    for (unsigned int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
