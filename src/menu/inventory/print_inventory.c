/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** print_inventory
*/

#include "my_rpg.h"

const char *inv[] = {"NULL", "assets/items/armor.png",
"assets/items/godsbeard.png", "assets/items/sword.png",
"assets/items/armor_rm.png", "assets/items/helmet_rm.png",
"assets/items/sword_rm.png", "assets/items/boots.png"};

static sfSprite *init_sprite(sfVector2f pos, const char *filename)
{
    sfTexture *texture = sfTexture_createFromFile(
    filename, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scaling = {3, 3};

    if (!texture || !sprite)
        return (NULL);
    sfSprite_setScale(sprite, scaling);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static void check_inv_bis(rpg_t *rpg, size_t item_id, sfVector2f col_line,
size_t x)
{
    if (item_id != 0 && rpg->menu->inventory->slots[x]->sprite == NULL
    && item_id < 8) {
        rpg->menu->inventory->slots[x]->sprite
        = init_sprite((sfVector2f){750 + 120 * col_line.x, 150 + 115 *
        col_line.y}, inv[item_id]);
    }
}

void check_inv(rpg_t *rpg)
{
    size_t item_id;
    size_t x = 0;

    for (size_t nbline = 0; nbline < 5; nbline++) {
        for (size_t nbcol = 0; nbcol < 6; nbcol++) {
            item_id = rpg->menu->inventory->slots[x]->item_id;
            check_inv_bis(rpg, item_id, (sfVector2f){nbcol, nbline}, x);
            x++;
        }
    }
    for (size_t i = 30, y = 0; i < 34; i++) {
        item_id = rpg->menu->inventory->slots[i]->item_id;
        if (rpg->menu->inventory->slots[i]->item_id != 0
        && rpg->menu->inventory->slots[i]->sprite == NULL && item_id < 8) {
            rpg->menu->inventory->slots[i]->sprite = init_sprite(
            (sfVector2f){1490, 180 + 140 * y}, inv[item_id]);
        }
        y++;
    }
}

void print_inventory(rpg_t *rpg)
{
    check_inv(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->inventory->sprite, NULL);
    for (size_t x = 0; x < 34; x++) {
        if (rpg->menu->inventory->slots[x]->sprite != NULL
        && rpg->menu->inventory->slots[x]->item_id != 0) {
            sfRenderWindow_drawSprite(rpg->window,
            rpg->menu->inventory->slots[x]->sprite, NULL);
        }
    } init_my_text(rpg->combat->player->stat, rpg);
    if (rpg->combat->player->stat->text_attack != NULL)
        sfRenderWindow_drawText(rpg->window, PLAYER_STATS->text_attack, NULL);
    if (rpg->combat->player->stat->text_defense != NULL)
        sfRenderWindow_drawText(rpg->window, PLAYER_STATS->text_defense, NULL);
    if (rpg->combat->player->stat->text_life != NULL)
        sfRenderWindow_drawText(rpg->window, PLAYER_STATS->text_life, NULL);
    if (rpg->combat->player->stat->text_level != NULL)
        sfRenderWindow_drawText(rpg->window, PLAYER_STATS->text_level, NULL);
    sfRenderWindow_drawSprite(rpg->window, OW->spr, NULL);
}
