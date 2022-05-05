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
void init_keybind(rpg_t *rpg);
int init_buttons(rpg_t *rpg);
int init_sound(rpg_t *rpg);
int init_menu(rpg_t *rpg);
void assign_class(rpg_t *rpg);
void assign_class_valid_save(rpg_t *rpg);
void init_font(rpg_t *rpg);
bool cam_is_in_bounds(float x, float y);
bool cmb_is_in_bounds(camera_t cam);

// UTILS
int event(rpg_t *rpg);
int handle_args(int ac, char **av);
int init_sfml(rpg_t *rpg, int debug_mode);
void print_debug(rpg_t *rpg);
float get_time(sfClock *clock);
float get_time_mil(sfClock *clock);
float get_dt(sfClock *game_clock);
int get_rand_small_range(void);
int toss_coin(void);
void free_rpg(rpg_t *rpg);
bool do_aabb_mouse(sfMouseButtonEvent mouse, sfSprite *sp);
bool do_aabb_mouse_rect(sfMouseButtonEvent mouse, sfIntRect rect);
bool do_aabb_sprites(sfSprite *sp1, sfSprite *sp2);
bool do_aabb_sprites_rectangle(sfSprite *sp1, sfRectangleShape *sp2);
void y_sorter(rpg_t *rpg, float player_y);
void get_olb_pos(int i, int j, rpg_t *rpg);

// USER INTERFACE
int create_hud(combat_t *combat);
void move_hud_in(hud_t *hud);
void move_hud_out(hud_t *hud);
int init_gauge_bar(entity_t *entity);
void draw_hud(rpg_t *rpg, entity_t *player, entity_t *ennemy);
int init_slash(combat_t *combat);
void do_slash(combat_t *combat, sfRenderWindow *window);

// COMBAT
void init_combat(rpg_t *rpg);
void combat_loop(rpg_t *rpg, combat_t *combat);
void do_transition_ow(rpg_t *rpg, transt_t *e);
void do_transition_cmb(rpg_t *rpg, transt_t *e);
void do_transition_death(rpg_t *rpg, transt_t *e);
void add_to_inventory(rpg_t *rpg);
void check_stat(rpg_t *rpg);
// COMBAT -> OLBERIC
void olberic_do_attack(entity_t *player, combat_t *combat, rpg_t *rpg);
void olberic_do_idle(entity_t *player);
void olberic_protect(entity_t *player, combat_t *combat);
void olberic_death(entity_t *player);
// COMBAT -> BOSS
void animate_boss(entity_t *boss, combat_t *combat);
// COMBAT -> ENNEMIES
void animate_bear(entity_t *bear, combat_t *combat);
void animate_wolf(entity_t *wolf, combat_t *combat);
void spawn_ennemy(rpg_t *rpg);

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
int **str_to_int_tab(char *string, int n, int case_);
void draw_triangle(sfVector2f *points, rpg_t *game, sfVector2i tex_pos, int i);
sfVector2i get_texture_pos(int x, int y, rpg_t *rpg);
sfVector2i get_object_pos(int x, int y, rpg_t *rpg);

// NPC
void check_quest(rpg_t *rpg);
void draw_npc(rpg_t *rpg);
void draw_quest_list(rpg_t *rpg);

// OVERWORLD
void overworld_loop(rpg_t *rpg);
int init_player_overworld(rpg_t *rpg);
void animate_player_overworld(rpg_t *rpg);
void get_dir(rpg_t *rpg);
int ow_aabb(rpg_t *rpg, sfVector2f offset);

// SHADER
void init_shaders(rpg_t *rpg);
void update_shaders(shader_t *shader, float dt);
int light(rpg_t *rpg , int i, int j, int n);

// MUSIC
int play_music(rpg_t *rpg);

//MENU
int init_menu(rpg_t *rpg);
int menuloop(rpg_t *rpg);
int load_loop(rpg_t *rpg, int n);
void draw_game_over(rpg_t *rpg);


//BUTTONS
void buttons_controls_menu(rpg_t *rpg, bt_list_t *bt_list, sfEvent event);
button_t *create_button(char *str, sfVector2f pos, int ptr_f, char *img);
int detect_click_on_bt(bt_list_t *bt_list, sfEvent event, size_t s, size_t e);
void init_all_buttons(rpg_t *rpg);
void display_buttons_main(rpg_t *rpg);
void display_buttons_option(rpg_t *rpg);
void print_parralax(rpg_t *rpg);
void buttons_controls_option_ig(rpg_t *rpg, bt_list_t *bt_list, sfEvent event);
void display_options_ig(rpg_t *rpg);
button_t *create_button_2(char *str, sfVector2f pos, int ptr_f, char *img);
void do_parralax_keybind(rpg_t *rpg);
void replace_text(rpg_t *rpg, int button);
void do_parralax_keyinput(rpg_t *rpg);
int detect_click_on_bt_2(bt_list_t *bt_list, sfEvent event, size_t s, size_t e);

//INVENTORY
void print_inventory(rpg_t *rpg);
void init_inventory(rpg_t *rpg);
int detect_click_on_inv(bt_list_t *bt_list, sfEvent event, size_t s, size_t e);
button_t *create_slots(char *str, sfVector2f pos, int ptr_f, char *img);
int manage_inv(rpg_t *rpg, int button);
void check_inv(rpg_t *rpg);
int slots_controls(rpg_t *rpg, sfEvent event);
int init_stats(rpg_t *rpg);

//INVENTORY UTILS
void clearstrnbr(char *str, int len);
void loop_int_to_str(int data[], int *big_num, int *pos, char *str);
char *int_to_str(int nb);
int init_my_text(stats_t *stat);

//CLASS MENU
void init_class_menu(rpg_t *rpg);
void class_menu(rpg_t *rpg);
void class_menu_button(sfEvent event, rpg_t *rpg);

// SAVE
bool read_save(rpg_t *rpg);
void save_game(rpg_t *rpg);

//OBJECT
void draw_object(rpg_t *rpg);

//ERROR_MANAGER
int errors_manager(void);

//MAIN
void do_loop(rpg_t *rpg);