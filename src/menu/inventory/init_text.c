/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_text
*/

#include "my_rpg.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void create_my_text_bis(sfText *text, sfVector2f pos, const char *stat)
{
    sfText_setPosition(text, pos);
    sfText_setFont(text, sfFont_createFromFile(ARIAL_FONT));
    sfText_setString(text, stat);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 40);
}

static sfText *create_my_text(sfVector2f pos, int value, int stuff_value)
{
    sfText *my_text = sfText_create();
    char *stat_player = int_to_str(value);
    char *stat_stuff = int_to_str(stuff_value);
    char *stat_total = malloc(sizeof(char) * (my_strlen(stat_player)
    + my_strlen(stat_stuff) + 2));
    size_t i = 0;
    size_t j = 0;

    if (!stat_total || !my_text || !stat_player || !stat_stuff)
        return NULL;
    for (i = 0; stat_player[i] != '\0'; i++)
        stat_total[i] = stat_player[i];
    stat_total[i] = '+';
    for (j = i + 1, i = 0; stat_stuff[i] != '\0'; j++, i++)
        stat_total[j] = stat_stuff[i];
    stat_total[j] = '\0';
    create_my_text_bis(my_text, pos, stat_total);
    return my_text;
}

static sfText *create_my_text_lvl(sfVector2f pos, int value)
{
    sfText *my_text = sfText_create();

    if (!my_text)
        return NULL;
    sfText_setPosition(my_text, pos);
    sfText_setFont(my_text, sfFont_createFromFile(ARIAL_FONT));
    sfText_setString(my_text, int_to_str(value));
    sfText_setColor(my_text, sfBlack);
    sfText_setCharacterSize(my_text, 40);
    return my_text;
}

static void destroy_my_text(sfText *my_text)
{
    sfFont *font;

    if (my_text != NULL) {
        font = sfText_getFont(my_text);
        sfFont_destroy(font);
        sfText_destroy(my_text);
    }
}

int init_my_text(stats_t *stat)
{
    int fd = open("assets/font/arial/arial.ttf", O_RDONLY);

    destroy_my_text(stat->text_attack);
    destroy_my_text(stat->text_defense);
    destroy_my_text(stat->text_life);
    destroy_my_text(stat->text_level);
    if (fd < 3)
        return (84);
    close(fd);
    stat->text_attack = create_my_text((sfVector2f){485, 558},
    stat->attack, stat->stuff->attack);
    stat->text_defense = create_my_text((sfVector2f){515, 508},
    stat->defense, stat->stuff->defense);
    stat->text_life = create_my_text((sfVector2f){450, 608},
    stat->life, stat->stuff->life);
    stat->text_level = create_my_text_lvl((sfVector2f){470, 460}, stat->level);
    return 0;
}
