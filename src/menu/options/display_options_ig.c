/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** option_menu
*/

#include "my_rpg.h"

static void parralax(rpg_t *rpg, sfVector2f actual_pos, int i)
{
    sfVector2f pos = {actual_pos.x, actual_pos.y};
    sfSprite_setPosition(BUTTONSO->lst_bt[i]->sprite, actual_pos);
    pos.x += (83);
    pos.y += 38;
    sfText_setPosition(BUTTONSO->lst_bt[i]->text, pos);
}

static void display_buttons_option_ig(rpg_t *rpg)
{
    sfVector2f mouse_pos;
    sfVector2f actual_pos;

    mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x/ 5
    , sfMouse_getPositionRenderWindow(rpg->window).y / 5};
    actual_pos = (sfVector2f){mouse_pos.x + 656, mouse_pos.y};
    parralax(rpg, actual_pos, 0);
    actual_pos.y = mouse_pos.y + 200;
    parralax(rpg, actual_pos, 1);
    actual_pos.y = mouse_pos.y + 400;
    parralax(rpg, actual_pos, 2);
    actual_pos.y = mouse_pos.y + 600;
    parralax(rpg, actual_pos, 3);

    for (size_t i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(rpg->window, BUTTONSO->lst_bt[i]->sprite,
        NULL);
        sfRenderWindow_drawText(rpg->window, BUTTONSO->lst_bt[i]->text, NULL);
    }
}

void display_buttons_music_ig(rpg_t *rpg)
{
    sfVector2f mouse_pos;
    sfVector2f actual_pos;

    mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x/ 5
    , sfMouse_getPositionRenderWindow(rpg->window).y / 5};
    actual_pos = (sfVector2f){mouse_pos.x + 656, mouse_pos.y + 100};
    parralax(rpg, actual_pos, 4);
    actual_pos.y = mouse_pos.y + 250;
    parralax(rpg, actual_pos, 5);
    actual_pos.y = mouse_pos.y + 400;
    parralax(rpg, actual_pos, 6);
    actual_pos.y = mouse_pos.y + 550;
    parralax(rpg, actual_pos, 7);
    actual_pos.y = mouse_pos.y + 700;
    parralax(rpg, actual_pos, 8);

    for (size_t i = 4; i < 9; i++) {
        sfRenderWindow_drawSprite(rpg->window, BUTTONSO->lst_bt[i]->sprite,
        NULL);
        sfRenderWindow_drawText(rpg->window, BUTTONSO->lst_bt[i]->text, NULL);
    }
}

void display_buttons_keybinds_ig(rpg_t *rpg)
{
    do_parralax_keybind(rpg);
    for (size_t i = 9; i < 18; i++) {
        sfRenderWindow_drawSprite(rpg->window, BUTTONSO->lst_bt[i]->sprite,
        NULL);
        sfRenderWindow_drawText(rpg->window, BUTTONSO->lst_bt[i]->text, NULL);
    }
}

void display_options_ig(rpg_t *rpg)
{
    if (rpg->menu->option->is_main == true) {
        print_parralax(rpg);
        display_buttons_option_ig(rpg);
    }
    if (rpg->menu->option->music == true) {
        print_parralax(rpg);
        display_buttons_music_ig(rpg);
    }
    if (rpg->menu->option->keybinds == true) {
        print_parralax(rpg);
        display_buttons_keybinds_ig(rpg);
    }
}