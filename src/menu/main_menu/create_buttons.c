/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_buttons
*/

#include "my_rpg.h"

void init_all_buttons(rpg_t *rpg)
{
    rpg->menu->main->buttons->lst_bt[0] = create_button("START",
    (sfVector2f){910, 400}, 100, "assets/menu/button.png");
    rpg->menu->main->buttons->lst_bt[1] = create_button("Option",
    (sfVector2f){910, 600}, 100, "assets/menu/button.png");
    rpg->menu->main->buttons->lst_bt[2] = create_button("Quit",
    (sfVector2f){910, 800}, 100, "assets/menu/button.png");
    rpg->menu->main->buttons->lst_bt[3] = create_button("Music",
    (sfVector2f){910, 400}, 100, "assets/menu/button.png");
    rpg->menu->main->buttons->lst_bt[4] = create_button("Debug",
    (sfVector2f){910, 600}, 100, "assets/menu/button.png");
    rpg->menu->main->buttons->lst_bt[5] = create_button("Return to menu",
    (sfVector2f){910, 800}, 100, "assets/menu/button.png");
}
