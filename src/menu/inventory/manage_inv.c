/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** manage_inv
*/

#include "my_rpg.h"

static int change_slots(rpg_t *rpg, int button, int key)
{
    int save = 0;

    if (key == button || key == -1)
        return (0);
    save = rpg->menu->inventory->slots[key]->item_id;
    sfSprite_destroy(rpg->menu->inventory->slots[key]->sprite);
    rpg->menu->inventory->slots[key]->sprite = NULL;
    sfSprite_destroy(rpg->menu->inventory->slots[button]->sprite);
    rpg->menu->inventory->slots[button]->sprite = NULL;
    rpg->menu->inventory->slots[key]->item_id =
    rpg->menu->inventory->slots[button]->item_id;
    rpg->menu->inventory->slots[button]->item_id = save;
    sfRenderWindow_display(rpg->window);
    init_stats(rpg);
    return 0;
}

static int manage_inv_bis(rpg_t *rpg)
{
    int key = -1;

    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        print_parralax(rpg);
        print_inventory(rpg);
        if (rpg->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (rpg->event.type == sfEvtMouseButtonPressed)
            key = detect_click_on_inv(rpg->menu->inventory->buttons,
            rpg->event, 0, 34);
        if (key != -1)
            break;
        sfRenderWindow_display(rpg->window);
    }
    return key;
}

int manage_inv(rpg_t *rpg, int button)
{
    int key = -1;

    if (button == -1)
        return (-1);
    while (key == -1) {
        key = manage_inv_bis(rpg);
    }
    return change_slots(rpg, button, key);
}
