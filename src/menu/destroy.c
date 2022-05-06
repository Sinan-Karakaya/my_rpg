/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy menu
*/

#include <stdlib.h>

#include "my_rpg.h"

static void destroy_button(button_t *button)
{
    sfSprite_destroy(button->sprite);
    sfText_destroy(button->text);
    sfRectangleShape_destroy(button->rect);
    free(button);
}

static void destroy_menu_main(menu_main_t *menu)
{
    sfSprite_destroy(menu->mid_g_sprite);
    sfTexture_destroy(menu->mid_g_texture);
    sfSprite_destroy(menu->back_g_sprite);
    sfTexture_destroy(menu->back_g_texture);
    sfSprite_destroy(menu->far_g_sprite);
    sfTexture_destroy(menu->far_g_texture);
    for (size_t i = 0; i < menu->buttons->nbr_bt; i++)
        destroy_button(menu->buttons->lst_bt[i]);
    free(menu->buttons->lst_bt);
    free(menu->buttons);
    free(menu);
}

static void destroy_inventory(menu_inventory_t *i)
{
    sfSprite_destroy(i->sprite);
    for (size_t j = 0; j < i->buttons->nbr_bt; j++)
        destroy_button(i->buttons->lst_bt[j]);
    free(i->buttons->lst_bt);
    free(i->buttons);
    for (size_t j = 0; j < 34; j++) {
        if (i->slots[j]->item_id == 0)
            continue;
        sfSprite_destroy(i->slots[j]->sprite);
        sfSprite_destroy(i->slots[j]->item_sprite);
        sfText_destroy(i->slots[j]->item_text);
        free(i->slots[j]);
    } free(i->slots);
    free(i);
}

void destroy_menu(menu_t *m)
{
    destroy_menu_main(m->main);
    for (size_t i = 0; i < m->option->buttons->nbr_bt; i++) {
        destroy_button(m->option->buttons->lst_bt[i]);
    } free(m->option->buttons->lst_bt);
    free(m->option->buttons);
    destroy_inventory(m->inventory);
    sfTexture_destroy(m->class->texture);
    sfSprite_destroy(m->class->sprite);
    sfText_destroy(m->class->text);
    sfFont_destroy(m->class->font);
    free(m->class);
    free(m);
}
