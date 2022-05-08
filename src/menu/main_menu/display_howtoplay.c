/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_howtoplay
*/

#include "my_rpg.h"

static void parralax(rpg_t *rpg, sfVector2f actual_pos, int i)
{
    sfVector2f pos = {actual_pos.x, actual_pos.y};
    sfSprite_setPosition(BUTTONS->lst_bt[i]->sprite, actual_pos);
    pos.x += (83);
    pos.y += 38;
    sfText_setPosition(BUTTONS->lst_bt[i]->text, pos);
}

void do_button_howtoplay(rpg_t *rpg, bt_list_t *bt_list, sfEvent event)
{
    int button = -1;

    button = detect_click_on_bt(bt_list, event, 9, 10);
    if (button == 9) {
        rpg->menu->is_howtoplay = false;
        rpg->menu->is_main = true;
    }
}

int display_howtoplay(rpg_t *rpg)
{
    sfVector2f mouse_pos, actual_pos;

    mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x
    / 5, sfMouse_getPositionRenderWindow(rpg->window).y / 5};
    actual_pos = (sfVector2f){mouse_pos.x + 656, mouse_pos.y + 700};
    parralax(rpg, actual_pos, 9);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->option->howtoplay, NULL);
    sfRenderWindow_drawSprite(rpg->window, BUTTONS->lst_bt[9]->sprite, NULL);
    sfRenderWindow_drawText(rpg->window, BUTTONS->lst_bt[9]->text, NULL);
    sfRenderWindow_display(rpg->window);
}