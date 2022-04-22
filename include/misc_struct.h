/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** various structs
*/

#pragma once

typedef struct music_s {
    sfMusic *music;
    bool is_played;
} music_t;

typedef struct shader {
    sfShader *get;
    sfSprite *sh_sprite;
    sfTexture *sh_texture;
    sfRenderStates *sh_state;
    sfRenderTexture *render_texture;
} shader_t;

typedef struct debug {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
} debug_t;
