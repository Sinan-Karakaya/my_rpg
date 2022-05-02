/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** manage_inv
*/

#include "my_rpg.h"

int manage_inv(rpg_t *rpg, int button)
{
    int key = -1;
    int save = 0;

    if (button == -1)
        return (-1);
    while (key == -1) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            print_parralax(rpg);
            print_inventory(rpg);
            if (rpg->event.type == sfEvtClosed)
                sfRenderWindow_close(rpg->window);
            if (rpg->event.type == sfEvtMouseButtonPressed)
                key = detect_click_on_inv(rpg->menu->inventory->buttons, rpg->event, 0, 30);
            if (key != -1)
                break;
            sfRenderWindow_display(rpg->window);
        }
    }
    if (key == button)
        return (0);
    save = rpg->menu->inventory->slots[key]->item_id;
    sfSprite_destroy(rpg->menu->inventory->slots[key]->sprite);
    rpg->menu->inventory->slots[key]->sprite = NULL;
    sfSprite_destroy(rpg->menu->inventory->slots[button]->sprite);
    rpg->menu->inventory->slots[button]->sprite = NULL;
    rpg->menu->inventory->slots[key]->item_id = rpg->menu->inventory->slots[button]->item_id;
    rpg->menu->inventory->slots[button]->item_id = save;
    return 0;
}