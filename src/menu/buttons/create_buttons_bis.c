/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_buttons_bis
*/

#include "my_rpg.h"

int create_buttons_main_bis(rpg_t *rpg)
{
    rpg->menu->main->buttons->lst_bt[5] = create_button("Debug",
    (sfVector2f){910, 600}, 100, "assets/menu/button.png");
    rpg->menu->main->buttons->lst_bt[6] = create_button("Back",
    (sfVector2f){910, 800}, 100, "assets/menu/button.png");
    rpg->menu->main->buttons->lst_bt[7] = create_button("Keybinds",
    (sfVector2f){1440, 540}, 100, "assets/menu/button.png");
    rpg->menu->main->buttons->lst_bt[8] = create_button("Shaders",
    (sfVector2f){750, 540}, 100, "assets/menu/button.png");
    rpg->menu->main->buttons->lst_bt[9] = create_button("Back",
    (sfVector2f){910, 540}, 100, "assets/menu/button.png");
    return 0;
}