/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thomas.juin
** File description:
** struct
*/

#pragma once

typedef enum combat_player_state {
    RPG_COMBAT_PLAYER_IDLE,
    RPG_COMBAT_PLAYER_ATTACK,
    RPG_COMBAT_PLAYER_PROTECT,
    RPG_COMBAT_PLAYER_DEATH
} e_combat_player_state;

typedef enum combat_state {
    RPG_COMBAT_PENDING,
    RPG_COMBAT_ATTACKING,
    RPG_COMBAT_DEATH,
} e_combat_state;

typedef struct entity {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    int rect_left_i;
    int rect_left_w;
    int life;
    e_combat_player_state cmb_state;
} entity_t;

typedef struct hud {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfClock *clock;
} hud_t;

typedef struct combat {
    hud_t *hud;
    entity_t *ennemy;
    entity_t *player;
    e_combat_state state;
} combat_t;

typedef struct render {
    sfVector2f *point;
    sfVertexArray *triangle;
} render_t;

typedef struct camera {
    float x;
    float y;
    render_t *render;
} camera_t;

typedef struct world {
    int **height_map;
    int **water_map;
    int **texture_map;
    int **object_map;
} world_t;

typedef struct rpg {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfClock *game_clock;
    combat_t *combat;
    world_t *world;
    camera_t cam;
} rpg_t;
