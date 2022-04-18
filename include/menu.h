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

typedef struct menu_main_s {
    sfSprite *fore_g_sprite;
    sfTexture *fore_g_texture;
    sfSprite *mid_g_sprite;
    sfTexture *mid_g_texture;
    sfSprite *back_g_sprite;
    sfTexture *back_g_texture;
    sfSprite *far_g_sprite;
    sfTexture *far_g_texture;
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
    menu_main_t *main;
    menu_option_t *option;
} menu_t;

#endif /* !MENU_H_ */
