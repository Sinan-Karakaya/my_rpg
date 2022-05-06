/*
** EPITECH PROJECT, 2022
** sprite_button.c
** File description:
** sprite_button
*/

#include "my_rpg.h"
#include <stdlib.h>

static sfSprite *init_sprite(sfVector2f pos, char *filename)
{
    sfTexture *texture = sfTexture_createFromFile(
    filename, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scaling = {2, 2};

    if (!texture || !sprite)
        return NULL;
    sfSprite_setScale(sprite, scaling);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static sfText *init_text(sfVector2f pos, const char *txt, sfVector2u size)
{
    sfFont *font = sfFont_createFromFile("assets/font/arial/arial.ttf");
    sfText *text = sfText_create();
    sfVector2f origin = {0};
    sfFloatRect rect = {0};

    sfText_setPosition(text, pos);
    sfText_setString(text, txt);
    sfText_setColor(text, sfBlack);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 25);
    rect = sfText_getGlobalBounds(text);
    origin.x = rect.width / 2;
    origin.y = rect.height / 2;
    sfText_setOrigin(text, origin);
    pos.x = size.x / 4 + pos.x;
    pos.y = size.y / 5 + pos.y;
    sfText_setPosition(text, pos);
    return text;
}

static button_t *build_button(char *txt, sfVector2f pos, int ptr, char *name)
{
    button_t *button = NULL;
    sfVector2u size = {0};
    sfVector2f size_rect = {88, 52};
    const sfTexture *texture_temp = NULL;

    button = malloc(sizeof(button_t));
    if (!button)
        return NULL;
    button->hover = false;
    button->is_hover = false;
    button->toggle = false;
    button->sprite = init_sprite(pos, name);
    if (!button->sprite)
        return NULL;
    texture_temp = sfSprite_getTexture(button->sprite);
    size = sfTexture_getSize(texture_temp);
    button->text = init_text(pos, txt, size);
    button->ptr_function = ptr;
    button->rect = sfRectangleShape_create();
    if (!button->rect || !button->text)
        return NULL;
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size_rect);
    sfRectangleShape_setScale(button->rect, (sfVector2f){2, 2});
    return button;
}

button_t *create_button(char *str, sfVector2f pos, int ptr_f, char *img)
{
    button_t *button_test;

    button_test = build_button(str, pos, ptr_f, img);
    return button_test;
}
