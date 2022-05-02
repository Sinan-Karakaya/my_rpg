/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_text
*/

#include "my_rpg.h"
#include "my.h"

static stats_t *create_my_text(sfVector2f pos, int value)
{
    sfText *my_text = sfText_create();
    sfText_setPosition(my_text, pos);
    sfText_setFont(my_text, sfFont_createFromFile("assets/font/arial/arial.ttf"));
    sfText_setString(my_text, int_to_str(value));
    sfText_setColor(my_text, sfBlack);
    sfText_setCharacterSize(my_text, 40);
}

int init_my_text(stats_t *stat)
{
    if (stat->text_attack != NULL)
        sfText_destroy(stat->text_attack);
    if (stat->text_defense != NULL)
        sfText_destroy(stat->text_defense);
    if (stat->text_life != NULL)
        sfText_destroy(stat->text_life);
    if (stat->text_level != NULL)
        sfText_destroy(stat->text_level);
    stat->text_attack = create_my_text((sfVector2f){485, 558}, stat->attack);
    stat->text_defense = create_my_text((sfVector2f){515, 508}, stat->defense);
    stat->text_life = create_my_text((sfVector2f){450, 608}, stat->life);
    stat->text_level = create_my_text((sfVector2f){470, 460}, stat->level);
}
