/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** print_inventory
*/

#include "my_rpg.h"

static sfSprite *init_sprite(sfVector2f pos, char *filename)
{
    sfTexture *texture = sfTexture_createFromFile(
    filename, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scaling = {1, 1};

    sfSprite_setScale(sprite, scaling);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static void check_inv(rpg_t *rpg)
{
    static char *inv[] = {"NULL", "assets/items/armor.png",
    "assets/items/godsbeard.png", "assets/items/sword.png"};
    size_t item_id;

    for (size_t nbline = 0; nbline < 5; nbline++) {
        for (size_t nbcol = 0; nbcol < 6; nbcol++) {
            item_id = rpg->menu->inventory->slots[nbline][nbcol].item_id;
            if (rpg->menu->inventory->slots[nbline][nbcol].item_id != 0) {
                rpg->menu->inventory->slots[nbline][nbcol].sprite
                = init_sprite((sfVector2f){100, 100}, inv[item_id]);
            }
        }
    }
}

void print_inventory(rpg_t *rpg)
{
    check_inv(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->inventory->sprite, NULL);
    for (size_t nbline = 0; nbline < 5; nbline++) {
        for (size_t nbcol = 0; nbcol < 6; nbcol++) {
            if (rpg->menu->inventory->slots[nbline][nbcol].sprite != NULL
            && rpg->menu->inventory->slots[nbline][nbcol].item_id != 0) {
                sfRenderWindow_drawSprite(rpg->window,
                rpg->menu->inventory->slots[nbline][nbcol].sprite, NULL);
            }
        }
    }
}