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
    sfVector2f scaling = {3, 3};

    sfSprite_setScale(sprite, scaling);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void check_inv(rpg_t *rpg)
{
    static char *inv[] = {"NULL", "assets/items/armor.png",
    "assets/items/godsbeard.png", "assets/items/sword.png"};
    size_t item_id;
    size_t x = 0;

    for (size_t nbline = 0; nbline < 5; nbline++) {
        for (size_t nbcol = 0; nbcol < 6; nbcol++) {
            item_id = rpg->menu->inventory->slots[x]->item_id;
            if (rpg->menu->inventory->slots[x]->item_id != 0 && rpg->menu->inventory->slots[x]->sprite == NULL) {
                rpg->menu->inventory->slots[x]->sprite
                = init_sprite((sfVector2f){750 + 120 * nbcol, 150 + 115 * nbline}, inv[item_id]);
            }
            x++;
        }
    }
}

void display_character(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, OW->spr, NULL);
}

void print_inventory(rpg_t *rpg)
{
    check_inv(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->inventory->sprite, NULL);
    for (size_t x = 0; x < 30; x++) {
        if (rpg->menu->inventory->slots[x]->sprite != NULL
        && rpg->menu->inventory->slots[x]->item_id != 0) {
            sfRenderWindow_drawSprite(rpg->window,
            rpg->menu->inventory->slots[x]->sprite, NULL);
        }
    }
    init_my_text(rpg->combat->player->stat);
    if (rpg->combat->player->stat->text_attack != NULL)
        sfRenderWindow_drawText(rpg->window, rpg->combat->player->stat->text_attack, NULL);
    if (rpg->combat->player->stat->text_defense != NULL)
        sfRenderWindow_drawText(rpg->window, rpg->combat->player->stat->text_defense, NULL);
    if (rpg->combat->player->stat->text_life != NULL)
        sfRenderWindow_drawText(rpg->window, rpg->combat->player->stat->text_life, NULL);
    if (rpg->combat->player->stat->text_level != NULL)
        sfRenderWindow_drawText(rpg->window, rpg->combat->player->stat->text_level, NULL);
    display_character(rpg);
}
