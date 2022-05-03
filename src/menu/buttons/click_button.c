/*
** EPITECH PROJECT, 2022
** click_button.c
** File description:
** click button
*/

#include "my_rpg.h"

static int test_click_on_bt (sfVector2f coord_click, button_t *button, int len,
int height)
{
    sfVector2f pos = sfSprite_getPosition(button->sprite);
    sfTexture *texture = (sfTexture *)sfSprite_getTexture(button->sprite);
    sfVector2u size = sfTexture_getSize(texture);
    size.x = size.x * len;
    size.y = size.y * height;

    if (coord_click.x >= pos.x
    && coord_click.x < pos.x + size.x
    && coord_click.y >= pos.y
    && coord_click.y < pos.y + size.y)
        return true;
    else
        return false;
}

int detect_click_on_bt(bt_list_t *bt_list, sfEvent event, size_t s, size_t e)
{
    sfVector2f coord_click = {event.mouseButton.x, event.mouseButton.y};
    bool toggle = false;

    for (size_t i = s; i < e; i++) {
        if (test_click_on_bt(coord_click, bt_list->lst_bt[i], 2, 2)) {
            toggle = bt_list->lst_bt[i]->toggle;
            bt_list->lst_bt[i]->toggle = (toggle == true) ? false : true;
            return i;
        }
    }
    return -1;
}

int detect_click_on_bt_2(bt_list_t *bt_list, sfEvent event, size_t s, size_t e)
{
    sfVector2f coord_click = {event.mouseButton.x, event.mouseButton.y};
    bool toggle = false;

    for (size_t i = s; i < e; i++) {
        if (test_click_on_bt(coord_click, bt_list->lst_bt[i], 4, 2)) {
            toggle = bt_list->lst_bt[i]->toggle;
            bt_list->lst_bt[i]->toggle = (toggle == true) ? false : true;
            return i;
        }
    }
    return -1;
}

int detect_click_on_inv(bt_list_t *bt_list, sfEvent event, size_t s, size_t e)
{
    sfVector2f coord_click = {event.mouseButton.x, event.mouseButton.y};
    bool toggle = false;

    for (size_t i = s; i < e; i++) {
        if (!bt_list->lst_bt[i])
            return -1;
        if (test_click_on_bt(coord_click, bt_list->lst_bt[i], 1, 1)) {
            toggle = bt_list->lst_bt[i]->toggle;
            bt_list->lst_bt[i]->toggle = (toggle == true) ? false : true;
            return i;
        }
    }
    return -1;
}
