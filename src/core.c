/*
** EPITECH PROJECT, 2022
** my_rph
** File description:
** main file
*/

#include <stdlib.h>
#include "my_rpg.h"

int event(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtClosed)
        return 1;
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code == sfKeyDown)
            rpg->cam.y -= 50 * rpg->dt;
        if (rpg->event.key.code == sfKeyUp)
            rpg->cam.y += 50 * rpg->dt;
        if (rpg->event.key.code == sfKeyRight)
            rpg->cam.x += 200 * rpg->dt;
        if (rpg->event.key.code == sfKeyLeft)
            rpg->cam.x -= 200 * rpg->dt;
    }
    return 0;
}

static int menuloop(rpg_t *rpg)
{
    init_menu(rpg);
    sfVector2f mouse_pos;

    while (sfRenderWindow_isOpen(rpg->window)) {
        mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x / 60 - 340
        , sfMouse_getPositionRenderWindow(rpg->window).y / 60 - 200};
        sfSprite_setPosition(rpg->menu->main->far_g_sprite, mouse_pos);
        sfRenderWindow_clear(rpg->window, sfBlack);
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->main->far_g_sprite, NULL);
         mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x / 30 - 340
        , sfMouse_getPositionRenderWindow(rpg->window).y / 30 - 400};
        sfSprite_setPosition(rpg->menu->main->back_g_sprite, mouse_pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->main->back_g_sprite, NULL);
         mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x / 12 - 600
        , sfMouse_getPositionRenderWindow(rpg->window).y / 12 - 400};
        sfSprite_setPosition(rpg->menu->main->mid_g_sprite, mouse_pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->main->mid_g_sprite, NULL);
        sfRenderWindow_display(rpg->window);
        sfRenderWindow_pollEvent(rpg->window, &rpg->event);
    }
    return 0;
}
static int gameloop(rpg_t *rpg, combat_t *combat)
{
    int temp = 0;

    while (sfRenderWindow_isOpen(rpg->window)) {
        rpg->dt = get_dt(rpg->game_clock);
        sfRenderWindow_clear(rpg->window, sfBlack);
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            if (event(rpg) == 1)
                return 1;
        }
        draw_water(rpg);
        draw_map(rpg);
        draw_object(rpg);
        combat_loop(rpg, combat);
        temp += rpg->dt;
        update_shaders(rpg->shader, rpg->dt);
        print_debug(rpg);
        //sfRenderWindow_drawSprite(rpg->window, rpg->shader->sh_sprite, rpg->shader->sh_state);
        sfRenderWindow_display(rpg->window);
    }
    return 0;
}

int main(int ac, char **av)
{
    int debug_mode = handle_args(ac, av);
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (debug_mode == -1)
        return 0;
    if (!rpg || init_sfml(rpg, debug_mode))
        return 84;
    rpg->combat = init_combat();
    init_cam(rpg);
    init_world(rpg);
    init_shaders(rpg);
    rpg->texture = init_struct_texture("assets/environement/pr.png", rpg);
    rpg->sounds = malloc(sizeof(music_t));
    rpg->sounds->music = sfMusic_createFromFile("assets/music/vista.ogg");
    play_music(rpg);
    menuloop(rpg);
    if (gameloop(rpg, rpg->combat)) {
        free_rpg(rpg);
        return 0;
    }
    return 0;
}
