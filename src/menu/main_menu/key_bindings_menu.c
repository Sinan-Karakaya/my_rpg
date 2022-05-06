/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** key_bindings_menu
*/

#include "my_rpg.h"

static void parralax(rpg_t *rpg, sfVector2f actual_pos, int i)
{
    sfVector2f pos = {actual_pos.x, actual_pos.y};
    sfSprite_setPosition(BUTTONSO->lst_bt[i]->sprite, actual_pos);
    pos.x += (88);
    pos.y += 38;
    sfText_setPosition(BUTTONSO->lst_bt[i]->text, pos);
}

void display_buttons_keybinds_menu(rpg_t *rpg)
{
    do_parralax_keybind(rpg);
    for (size_t i = 9; i < 18; i++) {
        sfRenderWindow_drawSprite(rpg->window, BUTTONSO->lst_bt[i]->sprite,
        NULL);
        sfRenderWindow_drawText(rpg->window, BUTTONSO->lst_bt[i]->text, NULL);
    }
}

void display_buttons_music_menu(rpg_t *rpg)
{
    sfVector2f mouse_pos;
    sfVector2f actual_pos;

    mouse_pos = (sfVector2f){sfMouse_getPositionRenderWindow(rpg->window).x/ 5
    , sfMouse_getPositionRenderWindow(rpg->window).y / 5};
    actual_pos = (sfVector2f){mouse_pos.x + 656, mouse_pos.y + 100};
    parralax(rpg, actual_pos, 4);
    actual_pos = (sfVector2f){mouse_pos.x + 656 - 88, mouse_pos.y + 250};
    parralax(rpg, actual_pos, 5);
    actual_pos.y = mouse_pos.y + 550;
    parralax(rpg, actual_pos, 7);
    actual_pos = (sfVector2f){mouse_pos.x + 656, mouse_pos.y + 400};
    parralax(rpg, actual_pos, 6);
    actual_pos.y = mouse_pos.y + 700;
    parralax(rpg, actual_pos, 8);
    for (size_t i = 4; i < 9; i++) {
        sfRenderWindow_drawSprite(rpg->window, BUTTONSO->lst_bt[i]->sprite,
        NULL);
        sfRenderWindow_drawText(rpg->window, BUTTONSO->lst_bt[i]->text, NULL);
    }
}

static void do_button_music_bis_menu(rpg_t *rpg, int i)
{
    if (i == 6) {
        if (rpg->sounds->is_sound_effect == true) {
            rpg->sounds->is_sound_effect = false;
        } else {
            sfMusic_play(rpg->sounds->music);
            rpg->sounds->is_sound_effect = true;
        }
    }
    change_texture(BUTTONSO, 6, 7);
    if (i == 7) {
        if (rpg->event.mouseButton.x > 930 && rpg->sounds->sound_effect < 100)
            rpg->sounds->sound_effect += 5;
        else if (rpg->event.mouseButton.x < 930 && rpg->sounds->sound_effect > 0)
            rpg->sounds->sound_effect -= 5;
    }
    if (i == 8) {
        rpg->menu->is_music = false;
        rpg->menu->is_option = true;
    }
}

void do_button_music_menu_interact(rpg_t *rpg, int i)
{
    if (i == 4) {
        if (rpg->sounds->is_played == true) {
            sfMusic_pause(rpg->sounds->music);
            rpg->sounds->is_played = false;
        } else {
            sfMusic_play(rpg->sounds->music);
            rpg->sounds->is_played = true;
        }
    }
    change_texture(BUTTONSO, 4, 5);
    if (i == 5) {
        if (rpg->event.mouseButton.x > 960 && rpg->sounds->sound_music < 100)
            rpg->sounds->sound_music += 5;
        else if (rpg->event.mouseButton.x < 960 && rpg->sounds->sound_music > 0)
            rpg->sounds->sound_music -= 5;
        sfMusic_setVolume(rpg->sounds->music, rpg->sounds->sound_music);
    }
    do_button_music_bis_menu(rpg, i);
}
