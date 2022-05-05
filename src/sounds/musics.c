/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** musics
*/

#include "my_rpg.h"
#include "defines.h"

int init_sfx(combat_t *combat)
{
    combat->sfx = malloc(sizeof(sfx_t));

    if (!combat->sfx)
        return 84;
    combat->sfx->sound = sfSound_create();
    combat->sfx->buffer = sfSoundBuffer_createFromFile(SLASH_SFX);
    if (!combat->sfx->buffer || !combat->sfx->sound) {
        if (combat->sfx->sound)
            sfSound_destroy(combat->sfx->sound);
        if (combat->sfx->buffer)
            sfSoundBuffer_destroy(combat->sfx->buffer);
        return 84;
    }
    sfSound_setBuffer(combat->sfx->sound, combat->sfx->buffer);
    sfSound_setVolume(combat->sfx->sound, 15);
    return 0;
}

int play_music(rpg_t *rpg)
{
    if (init_sfx(rpg->combat) == 84)
        return 84;
    sfMusic_play(rpg->sounds->music);
    sfMusic_setLoop(rpg->sounds->music, sfTrue);
    sfMusic_setVolume(rpg->sounds->music, rpg->sounds->sound_music);
    return 0;
}
