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
#include <SFML/Audio.h>

#include "struct.h"

#include "defines.h"

// UTILS
int handle_args(int ac, char **av);
int init_sfml(rpg_t *rpg, int debug_mode);
void print_debug(rpg_t *rpg);
float get_time(sfClock *clock);
float get_time_mil(sfClock *clock);
float get_dt(sfClock *game_clock);
int get_rand_small_range(void);
void free_rpg(rpg_t *rpg);
bool do_aabb_mouse(sfMouseMoveEvent mouse, sfSprite *sp);
bool do_aabb_sprites(sfSprite *sp1, sfSprite *sp2);

// USER INTERFACE
int create_hud(combat_t *combat);
void move_hud_in(hud_t *hud);
void move_hud_out(hud_t *hud);
int init_gauge_bar(entity_t *entity);
void draw_hud(rpg_t *rpg, entity_t *player, entity_t *ennemy);
int init_slash(combat_t *combat);
void do_slash(combat_t *combat, sfRenderWindow *window);

// COMBAT
combat_t *init_combat(void);
void combat_loop(rpg_t *rpg, combat_t *combat);
// COMBAT -> OLBERIC
void olberic_do_attack(entity_t *player, combat_t *combat, rpg_t *rpg);
void olberic_do_idle(entity_t *player);
void olberic_protect(entity_t *player, combat_t *combat);
void olberic_death(entity_t *player);
// COMBAT -> BOSS
void animate_boss(entity_t *boss, combat_t *combat);

// MAP
sfVector2f to2d(sfVector3f p, rpg_t *game);
void draw_map(rpg_t *rpg);
void draw_water(rpg_t *rpg);
int **create_map(int heigth, int width);
void init_world(rpg_t *rpg);
void init_cam(rpg_t *game);
sfRenderStates *init_struct_texture(char *path, rpg_t *rpg);
float perlin(float x, float y, float res);

// SHADER
void init_shaders(rpg_t *rpg);
void update_shaders(shader_t *shader, float dt);

// MUSIC
int play_music(rpg_t *rpg);
