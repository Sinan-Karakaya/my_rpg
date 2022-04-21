/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** shader file
*/

#include <stdlib.h>
#include "my_rpg.h"

void init_shaders(rpg_t *rpg)
{
    if (sfShader_isAvailable()) {
        rpg->shader = malloc(sizeof(shader_t));
        rpg->shader->get = malloc(sizeof(sfShader*));
        rpg->shader->get = sfShader_createFromFile(NULL, NULL, SHADER_PATH);
        rpg->shader->sh_texture = sfTexture_create(1920, 1080);
        rpg->shader->sh_sprite = sfSprite_create();
        sfSprite_setTexture(rpg->shader->sh_sprite, rpg->shader->sh_texture,
        sfFalse);
        sfSprite_setColor(rpg->shader->sh_sprite, sfTransparent);
        rpg->shader->sh_state = malloc(sizeof(sfRenderStates));
        rpg->shader->sh_state->shader = rpg->shader->get;
        rpg->shader->sh_state->blendMode = sfBlendAlpha;
        rpg->shader->sh_state->transform = sfTransform_Identity;
        rpg->shader->sh_state->texture = NULL;
        sfSprite_setPosition(rpg->shader->sh_sprite, (sfVector2f){0, 0});
        sfShader_setVec2Uniform(rpg->shader->get, "resolution",
        (sfVector2f){1920, 1080});
        sfShader_setFloatUniform(rpg->shader->get, "time", rpg->dt);
    }
}

void update_shaders(shader_t *shader, float dt)
{
    sfShader_setVec2Uniform(shader->get, "resolution",
    (sfVector2f){RES_X, RES_Y});
    sfShader_setFloatUniform(shader->get, "time", dt);
}
