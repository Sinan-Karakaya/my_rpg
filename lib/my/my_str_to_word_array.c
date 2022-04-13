/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** func
*/

#include <stdlib.h>

#include "my.h"

void my_show_word_array(char * const *tab);

static int is_alphanum(char const *str, int pos)
{
    if (str[pos] != '\n')
        return 1;
    else
        return 0;
}

static int word_count(char const *str)
{
    unsigned int count = 0;

    for (unsigned int i = 0; str[i]; i++)
        if (is_alphanum(str, i) == 0 && is_alphanum(str, i - 1))
            count++;

    return count + 1;
}

static char **assign_letter(char const *str, char **result)
{
    unsigned int i = 0;
    unsigned int j = 0;

    for (unsigned int letter = 0; str[letter]; letter++) {
        if (is_alphanum(str, letter) == 0 &&
        (letter > 0 && is_alphanum(str, letter - 1) != 0)) {
            result[i][j] = '\0';
            i++;
            j = 0;
        } else if (is_alphanum(str, letter)) {
            result[i][j] = str[letter];
            j++;
        }
    }
    result[i + 1] = NULL;
    return result;
}

static int after_loop(char **res, char const *str, int temp, int j)
{
    res[j] = my_calloc(1, sizeof(char) * (temp + 2));
    if (res[j] == NULL)
        return 1;
    res = assign_letter(str, res);
    return 0;
}

char **my_str_to_word_array(char const *str)
{
    unsigned int word_number = word_count(str);
    int temp = 0;
    char **result;
    int j = 0;

    if (!(result = my_calloc(1, sizeof(char *) * (word_number + 1))))
        return NULL;
    for (int i = 0; str[i]; i++){
        if (is_alphanum(str, i) == 1)
            temp++;
        else if (is_alphanum(str, i) == 0
        && (i > 0 && is_alphanum(str, i - 1) != 0)) {
            result[j] = my_calloc(1, sizeof(char) * (temp + 2));
            temp = 0;
            j++;
            i++;
        }
    } if (after_loop(result, str, temp, j))
        return NULL;
    return result;
}
