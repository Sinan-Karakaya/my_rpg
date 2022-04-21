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

#define BUTTONS rpg->menu->main->buttons
#define BUTTONSO rpg->menu->option->buttons

//INITIALIZATION
int init_all(rpg_t *rpg);

// UTILS
int handle_args(int ac, char **av);
int init_sfml(rpg_t *rpg, int debug_mode);
void print_debug(rpg_t *rpg);
float get_time(sfClock *clock);
float get_time_mil(sfClock *clock);
float get_dt(sfClock *game_clock);
int get_rand_small_range(void);
void free_rpg(rpg_t *rpg);
bool do_aabb_mouse(sfMouseButtonEvent mouse, sfSprite *sp);
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
void destroy_world(rpg_t *game);
int **str_to_int_tab();
void draw_triangle(sfVector2f *points, rpg_t *game, sfVector2i tex_pos, int i);
sfVector2i get_texture_pos(int x, int y, rpg_t *rpg);

// OVERWORLD
void overworld_loop(rpg_t *rpg);
int init_player_overworld(rpg_t *rpg);
void animate_player_overworld(rpg_t *rpg);

// SHADER
void init_shaders(rpg_t *rpg);
void update_shaders(shader_t *shader, float dt);

// MUSIC
int play_music(rpg_t *rpg);

//MENU
int init_menu(rpg_t *rpg);
int menuloop(rpg_t *rpg);

//BUTTONS
void buttons_controls_menu(rpg_t *rpg, bt_list_t *bt_list, sfEvent event);
button_t *create_button(char *str, sfVector2f pos, int ptr_f, char *img);
int detect_click_on_bt(bt_list_t *bt_list, sfEvent event, size_t s, size_t e);
void init_all_buttons(rpg_t *rpg);
void display_buttons_main(rpg_t *rpg);
void display_buttons_option(rpg_t *rpg);
void display_buttons_option_ig(rpg_t *rpg);
void print_option_ig(rpg_t *rpg);
void buttons_controls_option_ig(rpg_t *rpg, bt_list_t *bt_list, sfEvent event);


//OBJECT
void draw_object(rpg_t *rpg);
