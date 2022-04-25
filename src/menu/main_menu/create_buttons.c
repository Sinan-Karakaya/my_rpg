/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_buttons
*/

#include "my_rpg.h"

static void init_button_option_ig(rpg_t *rpg)
{
    rpg->menu->option->buttons->lst_bt[0] = create_button("Sounds",
    (sfVector2f){910, 200}, 100, "assets/menu/button.png");
    rpg->menu->option->buttons->lst_bt[1] = create_button("Key Bindings",
    (sfVector2f){910, 350}, 100, "assets/menu/button.png");
    rpg->menu->option->buttons->lst_bt[2] = create_button("Return to menu",
    (sfVector2f){910, 500}, 100, "assets/menu/button.png");
    rpg->menu->option->buttons->lst_bt[3] = create_button("<- Back",
    (sfVector2f){910, 650}, 100, "assets/menu/button.png");
    rpg->menu->option->buttons->lst_bt[4] = create_button("Music",
    (sfVector2f){910, 200}, 100, "assets/menu/button.png");
    rpg->menu->option->buttons->lst_bt[5] = create_button("Bar Music",
    (sfVector2f){910, 350}, 100, "assets/menu/button.png");
    rpg->menu->option->buttons->lst_bt[6] = create_button("Sound Effects",
    (sfVector2f){910, 500}, 100, "assets/menu/button.png");
    rpg->menu->option->buttons->lst_bt[7] = create_button("Bar Sound effect",
    (sfVector2f){910, 650}, 100, "assets/menu/button.png");
    rpg->menu->option->buttons->lst_bt[8] = create_button("<- Back",
    (sfVector2f){1550, 460}, 100, "assets/menu/button.png");
}

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
    rpg->menu->main->buttons->lst_bt[4]->toggle = true;
    rpg->menu->main->buttons->lst_bt[5] = create_button("<- Back",
    (sfVector2f){910, 800}, 100, "assets/menu/button.png");
    init_button_option_ig(rpg);
}
