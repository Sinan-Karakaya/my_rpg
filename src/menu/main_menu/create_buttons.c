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
}
