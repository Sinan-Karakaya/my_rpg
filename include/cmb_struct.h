/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** combat structs
*/

#pragma once

typedef enum combat_player_state {
    RPG_COMBAT_PLAYER_IDLE,
    RPG_COMBAT_PLAYER_ATTACK,
    RPG_COMBAT_PLAYER_ATTACKED,
    RPG_COMBAT_PLAYER_PROTECT,
    RPG_COMBAT_PLAYER_DEATH,
    RPG_COMBAT_PLAYER_WIN
} e_combat_player_state;

typedef enum combat_state {
    RPG_COMBAT_PENDING,
    RPG_COMBAT_ATTACKING,
    RPG_COMBAT_DEATH,
    RPG_COMBAT_ENNEMY,
    RPG_COMBAT_WIN
} e_combat_state;

typedef enum class_type {
    RPG_CLASS_WARRIOR,
    RPG_CLASS_CLERIC,
    RPG_CLASS_PEASANT
} e_class_type;

typedef struct gauge_bar {
    sfRectangleShape *rect;
    sfRectangleShape *rect_grey;
    sfColor color;
    sfColor grey_color;
    sfVector2f pos;
    sfVector2f size;
} gauge_bar_t;

typedef struct stuff_s {
    int attack;
    int defense;
    int life;
    int xp;
} stuff_t;

typedef struct stats {
    int level;
    int attack;
    int defense;
    int life;
    int xp;
    int xp_needed;
    stuff_t *stuff;
    sfText *text_attack;
    sfText *text_defense;
    sfText *text_life;
    sfText *text_level;
    e_class_type class;
} stats_t;

typedef struct entity {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    gauge_bar_t *bar;
    bool is_npc;
    int rect_left_i;
    int rect_left_w;
    int max_life;
    int life;
    stats_t *stat;
    e_combat_player_state cmb_state;
    char *name;
} entity_t;

typedef struct sfx {
    sfSound *sound;
    sfSoundBuffer *buffer;
} sfx_t;

typedef struct hud {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    bool is_active;
} hud_t;

typedef struct transt {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfClock *clock;
} transt_t;

typedef struct game_over {
    sfFont *font;
    sfText *text;
} game_over_t;

typedef struct combat {
    hud_t *hud;
    hud_t *slash;
    entity_t **ennemy;
    entity_t *curr_ennemy;
    entity_t *player;
    transt_t *transt;
    sfx_t *sfx;
    game_over_t *game_over;
    e_combat_state state;
    bool transition_cmb;
    bool transition_ow;
} combat_t;
