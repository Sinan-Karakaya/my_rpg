/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_buttons
*/

#include "my_rpg.h"

static void parralax(rpg_t *rpg, sfVector2f actual_pos, int i)
{
    sfVector2f pos = {actual_pos.x, actual_pos.y};
    sfSprite_setPosition(BUTTONS->lst_bt[i]->sprite, actual_pos);
    pos.x += (83);
    pos.y += 38;
    sfText_setPosition(BUTTONS->lst_bt[i]->text, pos);
}

static void change_texture(rpg_t *rpg, size_t start, size_t end)
{
    sfTexture *texture = sfTexture_createFromFile(
    "assets/menu/button.png", (const sfIntRect *)NULL);
    sfTexture *texture_to = sfTexture_createFromFile(
    "assets/menu/button_toggle.png", (const sfIntRect *)NULL);

    for (size_t i = start; i < end; i++) {
        if (BUTTONS->lst_bt[i]->toggle == true) {
            sfSprite_setTexture(BUTTONS->lst_bt[i]->sprite, texture_to, true);
        } else {
            sfSprite_setTexture(BUTTONS->lst_bt[i]->sprite, texture, true);
        }
    }
}

void display_buttons_main(rpg_t *rpg)
{
    sfVector2f mouse_pos;
    sfVector2f actual_pos;

    mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x/ 5
    , sfMouse_getPositionRenderWindow(rpg->window).y / 5};
    actual_pos = (sfVector2f){mouse_pos.x + 656, mouse_pos.y + 285};
    parralax(rpg, actual_pos, 0);
    actual_pos.y = mouse_pos.y + 445;
    parralax(rpg, actual_pos, 1);
    actual_pos.y = mouse_pos.y + 600;
    parralax(rpg, actual_pos, 2);

    for (size_t i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(rpg->window, BUTTONS->lst_bt[i]->sprite,
        NULL);
        sfRenderWindow_drawText(rpg->window, BUTTONS->lst_bt[i]->text, NULL);
    }
}

void display_buttons_option(rpg_t *rpg)
{
    sfVector2f mouse_pos;
    sfVector2f actual_pos;

    mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x/ 5
    , sfMouse_getPositionRenderWindow(rpg->window).y / 5};
    actual_pos = (sfVector2f){mouse_pos.x + 656, mouse_pos.y + 285};
    parralax(rpg, actual_pos, 3);
    actual_pos.y = mouse_pos.y + 445;
    parralax(rpg, actual_pos, 4);
    actual_pos.y = mouse_pos.y + 600;
    parralax(rpg, actual_pos, 5);
    change_texture(rpg, 3, 5);
    for (size_t i = 3; i < 6; i++) {
        sfRenderWindow_drawSprite(rpg->window, BUTTONS->lst_bt[i]->sprite,
        NULL);
        sfRenderWindow_drawText(rpg->window, BUTTONS->lst_bt[i]->text, NULL);
    }
}

