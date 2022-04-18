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
    int ptr_function;
} button_t;

typedef struct bt_list_s {
    unsigned int nbr_bt;
    button_t **lst_bt;
} bt_list_t;

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
    sfSprite *fore_g_sprite;
    sfTexture *fore_g_texture;
    sfSprite *mid_g_sprite;
    sfTexture *mid_g_texture;
    sfSprite *back_g_sprite;
    sfTexture *back_g_texture;
    sfSprite *far_g_sprite;
    sfTexture *far_g_texture;
} menu_option_t;

typedef struct menu {
    bool is_main;
    bool is_option;
    bool is_closed;
    menu_main_t *main;
    menu_option_t *option;
} menu_t;

#endif /* !MENU_H_ */