/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free
*/

#include <stdlib.h>
#include "my_rpg.h"

static void destroy_ow(overworld_t *ow)
{
    sfTexture_destroy(ow->texture);
    sfSprite_destroy(ow->spr);
    sfClock_destroy(ow->clock);
    free(ow);
}

static void destroy_rpg_bis(rpg_t *rpg)
{
    sfClock_destroy(rpg->cine->clock);
    sfTexture_destroy(rpg->cine->background);
    sfSprite_destroy(rpg->cine->sprite);
    free(rpg->cine);
    sfText_destroy(rpg->end->text);
    sfFont_destroy(rpg->end->font);
    free(rpg->end);
    free(rpg);
}

static void destroy_rpg(rpg_t *rpg)
{
    sfClock_destroy(rpg->game_clock);
    destroy_ow(rpg->overworld);
    free(rpg->texture);
    if (IS_SHADER == 1) {
        sfShader_destroy(rpg->shader->get);
        sfSprite_destroy(rpg->shader->sh_sprite);
        sfTexture_destroy(rpg->shader->sh_texture);
        sfRenderTexture_destroy(rpg->shader->render_texture);
        free(rpg->shader);
    } sfFont_destroy(rpg->debug->font);
    sfText_destroy(rpg->debug->text);
    destroy_menu(rpg->menu);
    free(rpg->keybinds);
    free_entity(rpg->cine->player);
    free_entity(rpg->cine->car);
    destroy_rpg_bis(rpg);
}

void free_rpg(rpg_t *rpg)
{
    sfRenderWindow_destroy(rpg->window);
    sfMusic_destroy(rpg->sounds->music);
    sfSound_destroy(rpg->cine->sfx->sound);
    destroy_world(rpg);
    sfSoundBuffer_destroy(rpg->cine->sfx->buffer);
    combat_destroy(rpg);
    destroy_rpg(rpg);
}
