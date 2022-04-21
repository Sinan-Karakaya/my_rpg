/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** option_ig
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

static void do_button_option_ig(rpg_t *rpg, int i)
{
    if (i == 0) {
        printf("Ici ce sera la musique\n");
    }
    if (i == 1) {
        printf("Ici ce sera le KeyBindings\n");
    }
    if (i == 2) {
        rpg->menu->is_main = true;
        rpg->menu->option->is_active = false;
    }
    if (i == 3)
        rpg->menu->option->is_active = false;
}

void buttons_controls_option_ig(rpg_t *rpg, bt_list_t *bt_list, sfEvent event)
{
    int button;

    if (rpg->menu->option->is_active == true) {
        button = detect_click_on_bt(bt_list, event, 0, 4);
        do_button_option_ig(rpg, button);
    }
}

void display_buttons_option_ig(rpg_t *rpg)
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
        sfRenderWindow_drawSprite(rpg->window, BUTTONSO->lst_bt[i]->sprite, NULL);
        sfRenderWindow_drawText(rpg->window, BUTTONSO->lst_bt[i]->text, NULL);
    }
}