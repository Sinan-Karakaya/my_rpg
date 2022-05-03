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

static sfText *create_my_text(sfVector2f pos, int value)
{
    sfText *my_text = sfText_create();
    sfText_setPosition(my_text, pos);
    sfText_setFont(my_text, sfFont_createFromFile("assets/font/arial/arial.ttf"));
    sfText_setString(my_text, int_to_str(value));
    sfText_setColor(my_text, sfBlack);
    sfText_setCharacterSize(my_text, 40);
    return my_text;
}

static void destroy_my_text(sfText *my_text)
{
    if (my_text != NULL) {
        sfFont_destroy(sfText_getFont(my_text));
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
    stat->text_attack = create_my_text((sfVector2f){485, 558}, stat->attack);
    stat->text_defense = create_my_text((sfVector2f){515, 508}, stat->defense);
    stat->text_life = create_my_text((sfVector2f){450, 608}, stat->life);
    stat->text_level = create_my_text((sfVector2f){470, 460}, stat->level);
    return 0;
}
