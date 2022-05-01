/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init map
*/

#include <stdlib.h>
#include "my_rpg.h"

/*
* Possible de donner un shader très sympa au world avec cette ligne notamment:
* tex->shader = rpg->shader->get
* Ca nous permettrait de donner un effet de neige
* ou de pluie au sol par exemple
*/

sfRenderStates *init_struct_texture(char *path, rpg_t *rpg)
{
    sfRenderStates *tex = malloc(sizeof(sfRenderStates));

    tex = malloc(sizeof(sfRenderStates));
    tex->blendMode = sfBlendAlpha;
    tex->transform = sfTransform_Identity;
    tex->texture = sfTexture_createFromFile(path, NULL);
    tex->shader = rpg->world->shader;
    return tex;
}

static sfText *init_text(sfVector2f pos, sfVector2u size)
{
    sfFont *font = sfFont_createFromFile("assets/pnj/alagard.ttf");
    sfText *text = sfText_create();
    sfVector2f origin = {0};
    sfFloatRect rect = {0};

    sfText_setPosition(text, pos);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 4.);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);

    rect = sfText_getGlobalBounds(text);
    origin.x = rect.width / 2;
    origin.y = rect.height / 2;
    sfText_setOrigin(text, origin);
    pos.x = size.x / 4 + pos.x;
    pos.y = size.y / 5 + pos.y;
    sfText_setPosition(text, pos);
    return text;
}

void init_npc(rpg_t *rpg)
{
    rpg->world->gui.chatbox_sprite = sfSprite_create();
    rpg->world->gui.chatbox_texture = CREATE_CHAT;
    rpg->world->gui.text = sfText_create();
    rpg->world->gui.text = init_text((sfVector2f){55, 738}
    , (sfVector2u){0, 0});
    SET_TEX(rpg->world->gui.chatbox_sprite, TEX_CB sfTrue);
    sfSprite_setScale(rpg->world->gui.chatbox_sprite, (sfVector2f){6.1, 6.1});
    sfSprite_setPosition(rpg->world->gui.chatbox_sprite, (sfVector2f){0, 700});
}

void init_world(rpg_t *game)
{
    game->world = malloc(sizeof(world_t));
    init_npc(game);
    game->world->height_map = create_map(MAP_X, MAP_Y);
    game->world->object_map = create_map(MAP_X, MAP_Y);
    game->world->npc_list = malloc(sizeof(npc_t) * NB_NPC);
    sfVector2i zero = {0, 0};
    for (int i = 0; i < NB_NPC; i++)
        game->world->npc_list[i] = (npc_t){"", zero, 0, 0, 0 , 0, 0};
    game->world->world_clock = sfClock_create();
    game->world->texture_map =  str_to_int_tab("texture.map", 1, 17);
    game->world->height_map =  str_to_int_tab("height.map", -1 , 0);
    game->world->texture_o = init_struct_texture("assets/environement/po.png",
    game);
    game->world->texture_n = init_struct_texture("assets/environement/pn.png",
    game);
    game->world->rendered_spr = malloc(sizeof(sfSprite*));
    game->world->rendered_spr[0] = NULL;
    game->world->olberick_pos = (sfVector2i){0, 0};
    if (sfShader_isAvailable())
        game->world->shader = SHADE
}

void destroy_world(rpg_t *game)
{
    for (int i = 0; i < MAP_X; i++) {
        free(game->world->height_map[i]);
        free(game->world->object_map[i]);
        free(game->world->texture_map[i]);
    }
    free(game->world->height_map);
    free(game->world->object_map);
    free(game->world->texture_map);
    free(game->world->world_clock);
}
