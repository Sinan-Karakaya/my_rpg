/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-thomas.juin
** File description:
** struct
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#include "menu.h"
#include "world_struct.h"
#include "cmb_struct.h"
#include "misc_struct.h"

typedef enum ow_state {
    RPG_OW_IDLE,
    RPG_OW_WALK_R,
    RPG_OW_WALK_L
} e_ow_state;

typedef struct overworld {
    sfTexture *texture;
    sfSprite *spr;
    sfClock *clock;
    sfIntRect rect;
    sfx_t *sfx;
    e_ow_state state;
    bool was_looking_right;
    int rect_left_i;
    int rect_left_w;
    sfx_t *ow_sfx;
} overworld_t;

typedef enum rpg_scene {
    MAIN_MENU,
    OVERWORLD,
    COMBAT,
    DEATH,
    CINEMATIC
} e_rpg_scene;

typedef struct rpg {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfClock *game_clock;
    combat_t *combat;
    world_t *world;
    overworld_t *overworld;
    camera_t cam;
    float dt;
    sfRenderStates *texture;
    music_t *sounds;
    shader_t *shader;
    bool debug_toggle;
    debug_t *debug;
    menu_t *menu;
    e_rpg_scene scene;
    bool ow_can_move;
    keybind_t *keybinds;
    cine_t *cine;
    end_t *end;
    bool end_toggle;
} rpg_t;
