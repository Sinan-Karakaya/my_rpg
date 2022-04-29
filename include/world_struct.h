/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** world structs
*/

#pragma once

typedef struct render {
    sfVector2f *point;
    sfVertexArray *triangle;
} render_t;

typedef struct camera {
    float x;
    float y;
    float r;
    render_t *render;
} camera_t;

typedef struct npc {
    char *name;
    sfVector2i pos;
    int type;
    int max_life;
    int attack;
    int defense;
    int speed;
} npc_t;

typedef struct world {
    sfVector2i olberick_pos;
    int **height_map;
    int **texture_map;
    sfClock *world_clock;
    int **object_map;
    npc_t *npc_list;
    sfRenderStates *texture_o;
    sfRenderStates *texture_n;
    sfSprite **rendered_spr;
    sfShader *shader;
} world_t;

typedef struct perlin {
    float tmp;
    float s;
    float t;
    float u;
    float v;
    float Cx;
    float Cy;
    float Li1;
    float Li2;
    int gi0;
    int gi1;
    int gi2;
    int gi3;
} perlin_t;
