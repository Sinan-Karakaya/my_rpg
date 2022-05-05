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
    size_t sound_music;
    bool is_sound_effect;
    size_t sound_effect;
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

typedef struct keybind_s {
    int key_left;
    int key_right;
    int key_up;
    int key_down;
    int key_inventory;
    int key_attack;
    int key_protect;
    int key_run;
} keybind_t;

typedef struct cine {
    entity_t *player;
    entity_t *car;
    sfClock *clock;
    sfTexture *background;
    sfSprite *sprite;
    sfx_t *sfx;
} cine_t;
