/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_bis
*/

#include "my_rpg.h"

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

void init_inventory(rpg_t *rpg)
{
    INVENTORY->sprite =
    init_sprite((sfVector2f){300, 100}, "assets/menu/inventory.png");
    rpg->menu->inventory->slots = malloc(sizeof(slots_t *) * 5);
    for (size_t i = 0; i < 5; i++) {
        rpg->menu->inventory->slots[i] = malloc(sizeof(slots_t) * 6);
    }
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 6; j++) {
            rpg->menu->inventory->slots[i][j].item_id = 0;
            rpg->menu->inventory->slots[i][j].sprite = NULL;
        }
    }
    rpg->menu->inventory->slots[0][0].item_id = 2;
}