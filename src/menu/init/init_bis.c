/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_bis
*/

#include "my_rpg.h"
#include <stdlib.h>

static sfSprite *init_sprite(sfVector2f pos, char *filename)
{
    sfTexture *texture = sfTexture_createFromFile(
    filename, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scaling = {2, 2};

    sfSprite_setScale(sprite, scaling);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static void init_button_inventory(rpg_t *rpg)
{
    size_t x = 0;
    size_t y = 0;

    rpg->menu->inventory->buttons = malloc(sizeof(bt_list_t));
    rpg->menu->inventory->buttons->nbr_bt = 34;
    rpg->menu->inventory->buttons->lst_bt = malloc(sizeof(button_t *) *
    (rpg->menu->inventory->buttons->nbr_bt));
    for (size_t i = 0; i < 30; i++) {
        rpg->menu->inventory->buttons->lst_bt[i] = create_slots(" ",
        (sfVector2f){750 + 120 * x, 150 + 115 * y}, 100, "assets/menu/slots.png");
        x++;
        if (x > 5) {
            x = 0;
            y++;
        }
    }
    for (size_t i = 30, y = 0; i < rpg->menu->inventory->buttons->nbr_bt; i++) {
        rpg->menu->inventory->buttons->lst_bt[i] = create_slots(" ",
        (sfVector2f){1490, 180 + 140 * y}, 100, "assets/menu/slots.png");
        y++;
    }
}

void init_inventory(rpg_t *rpg)
{
    INVENTORY->sprite =
    init_sprite((sfVector2f){300, 100}, "assets/menu/inventory.png");
    rpg->menu->inventory->slots = malloc(sizeof(slots_t *) * 34);
    for (size_t i = 0; i < 34; i++)
        rpg->menu->inventory->slots[i] = malloc(sizeof(slots_t));
    for (size_t i = 0; i < 34; i++) {
        rpg->menu->inventory->slots[i]->item_id = 0;
        rpg->menu->inventory->slots[i]->sprite = NULL;
    }
    init_button_inventory(rpg);
    rpg->menu->inventory->slots[0]->item_id = 1;
    rpg->menu->inventory->slots[1]->item_id = 2;
    rpg->menu->inventory->slots[2]->item_id = 3;
    rpg->menu->inventory->slots[3]->item_id = 4;
    rpg->menu->inventory->slots[4]->item_id = 5;
    rpg->menu->inventory->slots[5]->item_id = 6;
    rpg->menu->inventory->slots[6]->item_id = 7;
    rpg->menu->inventory->slots[33]->item_id = 6;
}

void init_class_menu(rpg_t *rpg)
{
    rpg->menu->class = malloc(sizeof(menu_class_t));
    rpg->menu->class->texture = sfTexture_createFromFile(CLASS_MENU, NULL);
    rpg->menu->class->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->menu->class->sprite, rpg->menu->class->texture,
    sfFalse);
    sfSprite_setPosition(rpg->menu->class->sprite, (sfVector2f){0, 0});
    rpg->menu->class->font = sfFont_createFromFile(FONT_PATH);
    rpg->menu->class->text = sfText_create();
    sfText_setFont(rpg->menu->class->text, rpg->menu->class->font);
    sfText_setCharacterSize(rpg->menu->class->text, 30);
    sfText_setPosition(rpg->menu->class->text, (sfVector2f){750, 800});
    sfText_setString(rpg->menu->class->text, "Choose your class");
    sfText_setFillColor(rpg->menu->class->text, sfWhite);
    sfText_setOutlineColor(rpg->menu->class->text, sfBlack);
    sfText_setOutlineThickness(rpg->menu->class->text, 1);
    rpg->menu->is_class = false;
    rpg->menu->no_class = false;
}
