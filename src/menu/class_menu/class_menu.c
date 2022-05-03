/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** class menu
*/

#include "my_rpg.h"

void class_menu_button(sfEvent event, rpg_t *rpg)
{
    if (do_aabb_mouse_rect(event.mouseButton,
    (sfIntRect){160, 150, 360, 430})) {
        rpg->combat->player->stat->class = RPG_CLASS_WARRIOR;
        rpg->menu->no_class = false;
        rpg->menu->is_class = false;
        rpg->menu->is_main = false;
    } if (do_aabb_mouse_rect(event.mouseButton,
    (sfIntRect){788, 150, 360, 430})) {
        rpg->combat->player->stat->class = RPG_CLASS_CLERIC;
        rpg->menu->no_class = false;
        rpg->menu->is_class = false;
        rpg->menu->is_main = false;
    } if (do_aabb_mouse_rect(event.mouseButton,
    (sfIntRect){1400, 150, 360, 430})) {
        rpg->combat->player->stat->class = RPG_CLASS_PEASANT;
        rpg->menu->no_class = false;
        rpg->menu->is_class = false;
        rpg->menu->is_main = false;
    }
}

void class_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->class->sprite, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->menu->class->text, NULL);
}
