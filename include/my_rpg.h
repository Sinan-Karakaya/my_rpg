/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** header main file
*/

#pragma once

#include <stdbool.h>

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>

#include "struct.h"

#include "defines.h"

// UTILS
int init_sfml(rpg_t *rpg);
float get_time(sfClock *clock);
float get_time_mil(sfClock *clock);
float get_dt(sfClock *game_clock);
void free_rpg(rpg_t *rpg);
bool do_aabb_mouse(sfMouseMoveEvent mouse, sfSprite *sp);
bool do_aabb_sprites(sfSprite *sp1, sfSprite *sp2);

// USER INTERFACE
int create_hud(combat_t *combat);
void move_hud_in(hud_t *hud);
void move_hud_out(hud_t *hud);

// COMBAT
combat_t *init_combat(rpg_t *rpg);
void combat_loop(rpg_t *rpg, combat_t *combat);
void olberic_do_attack(entity_t *player, combat_t *combat);
void olberic_do_idle(entity_t *player);
void olberic_protect(entity_t *player);
void olberic_death(entity_t *player);

// MAP
sfVector2f to2d(sfVector3f p, rpg_t *game);
void draw_map(rpg_t *rpg);
int **create_map(int heigth, int width);
