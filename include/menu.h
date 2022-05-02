/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "stdbool.h"

typedef struct button_s {
    sfSprite *sprite;
    sfText *text;
    sfRectangleShape *rect;
    bool toggle;
    bool hover;
    bool is_hover;
    int name;
    int ptr_function;
} button_t;

typedef struct bt_list_s {
    unsigned int nbr_bt;
    button_t **lst_bt;
} bt_list_t;

typedef struct keys_s {
    int data;
    char *name;
} keys_t;

typedef struct menu_main_s {
    sfSprite *fore_g_sprite;
    sfTexture *fore_g_texture;
    sfSprite *mid_g_sprite;
    sfTexture *mid_g_texture;
    sfSprite *back_g_sprite;
    sfTexture *back_g_texture;
    sfSprite *far_g_sprite;
    sfTexture *far_g_texture;
    bt_list_t *buttons;
} menu_main_t;

typedef struct menu_option_s {
    bt_list_t *buttons;
    bool is_active;
    bool is_main;
    bool music;
    bool keybinds;
} menu_option_t;

typedef struct slots_s {
    sfSprite *sprite;
    sfSprite *item_sprite;
    sfText *item_text;
    size_t item_id;
    int item_lvl;
    int item_dmg;
    int item_def;
    int item_hp;
    int item_xp;
} slots_t;

typedef struct menu_inventory_s {
    sfSprite *sprite;
    slots_t **slots;
    sfSprite *player;
    slots_t *stuff;
    bt_list_t *buttons;
} menu_inventory_t;

typedef struct menu {
    bool is_main;
    bool is_option;
    bool is_inventory;
    bool is_closed;
    menu_main_t *main;
    menu_option_t *option;
    menu_inventory_t *inventory;
} menu_t;

#endif
