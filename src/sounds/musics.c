/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** musics
*/

#include "struct.h"

int play_music(rpg_t *rpg)
{
    sfMusic_play(rpg->sounds->music);
    sfMusic_setLoop(rpg->sounds->music, sfTrue);
    sfMusic_setVolume(rpg->sounds->music, 15);
    return 0;
}