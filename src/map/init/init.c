/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init map
*/

#include <stdlib.h>
#include "my_rpg.h"

sfRenderStates *init_struct_texture(char *path, rpg_t *rpg)
{
    sfRenderStates *tex = malloc(sizeof(sfRenderStates));

    if (!tex)
        return (NULL);
    tex->blendMode = sfBlendAlpha;
    tex->transform = sfTransform_Identity;
    tex->texture = sfTexture_createFromFile(path, NULL);
    if (!tex->texture)
        return (NULL);
    tex->shader = rpg->world->shader;
    return tex;
}

static sfText *init_text(sfVector2f pos, sfVector2u size)
{
    sfFont *font = sfFont_createFromFile("assets/pnj/alagard.ttf");
    sfText *text = sfText_create();
    sfVector2f origin = {0};
    sfFloatRect rect = {0};

    if (!font || !text)
        return NULL;
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 4.);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    rect = sfText_getGlobalBounds(text);
    origin.x = rect.width / 2, origin.y = rect.height / 2;
    sfText_setOrigin(text, origin);
    pos.x = size.x / 4 + pos.x, pos.y = size.y / 5 + pos.y;
    sfText_setPosition(text, pos);
    return text;
}

int init_npc(rpg_t *rpg)
{
    rpg->world->gui.actual_quest = 0;
    rpg->world->gui.chatbox_sprite = sfSprite_create();
    rpg->world->gui.chatbox_texture = CREATE_CHAT;
    rpg->world->gui.text = sfText_create();
    if (!rpg->world->gui.chatbox_sprite || !rpg->world->gui.text
    || !rpg->world->gui.chatbox_texture)
        return 84;
    rpg->world->gui.text = init_text((sfVector2f){55, 738}
    , (sfVector2u){0, 0});
    if (!rpg->world->gui.text)
        return 84;
    SET_TEX(rpg->world->gui.chatbox_sprite, TEX_CB sfTrue);
    sfSprite_setScale(rpg->world->gui.chatbox_sprite, (sfVector2f){6.1, 6.1});
    sfSprite_setPosition(rpg->world->gui.chatbox_sprite, (sfVector2f){0, 700});
    return 0;
}

static int init_world_bis(rpg_t *game)
{
    game->world->world_clock = sfClock_create();
    game->world->texture_map =  str_to_int_tab("./maps/texture.map", 1, 17);
    game->world->height_map =  str_to_int_tab("./maps/height.map", -1 , 0);
    game->world->texture_o = init_struct_texture("assets/environement/po.png",
    game);
    game->world->texture_n = init_struct_texture("assets/environement/pr.png",
    game);
    game->world->texture_p = init_struct_texture("assets/environement/pp.png",
    game);
    if (!game->world->texture_map || !game->world->height_map)
        return 84;
    game->world->rendered_spr = malloc(sizeof(sfSprite*));
    if (!game->world->rendered_spr)
        return 84;
    game->world->rendered_spr[0] = NULL;
    game->world->olberick_pos = (sfVector2i){0, 0};
    return 0;
}

int init_world(rpg_t *game)
{
    game->world = malloc(sizeof(world_t));
    if (!game->world)
        return 84;
    game->world->height_map = create_map(MAP_X, MAP_Y);
    game->world->object_map = create_map(MAP_X, MAP_Y);
    game->world->npc_list = malloc(sizeof(npc_t) * NB_NPC);
    if (!game->world->height_map || !game->world->object_map
    || !game->world->npc_list || init_npc(game))
        return 84;
    sfVector2i zero = {0, 0};
    for (int i = 0; i < NB_NPC; i++)
        game->world->npc_list[i] = (npc_t){"", zero, 0, 0, 0 , 0, 0};
    if (init_world_bis(game))
        return 84;
    if (sfShader_isAvailable())
        game->world->shader = NULL;
    return 0;
}
