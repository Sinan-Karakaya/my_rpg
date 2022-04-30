/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw bis
*/

#include "my_rpg.h"

void draw_map(rpg_t *rpg)
{
    sfVector2f *point = rpg->cam.render->point;
    int **height = rpg->world->height_map;
    sfVector3f point_3d;
    sfVector2i quad_offset = {0, 0};

    for (int j = MAP_Y - 1; j > 0; j--) {
        for (int i = 1; i < MAP_X - 1; i++) {
            quad_offset = get_texture_pos(i, j, rpg);
            point[0] = to2d((sfVector3f){i, height[i][j], j}, rpg);
            point[1] = to2d((sfVector3f){(i + 1), height[i + 1][j], j}, rpg);
            point_3d = (sfVector3f){(i  + 1), height[i + 1][j + 1], j + 1};
            point[2] = to2d(point_3d, rpg);
            light(rpg, i, j, 1);
            draw_triangle(point, rpg, quad_offset, 1);
            point[1] = to2d((sfVector3f){(i), height[i][j + 1], j + 1}, rpg);
            light(rpg, i, j, 1);
            draw_triangle(point, rpg, quad_offset, 2);
            get_olb_pos(i, j, rpg);
        }
    }
}

sfVector2i get_object_pos(int x, int y, rpg_t *rpg)
{
    int nbr = rpg->world->object_map[x][y];
    int size = sfTexture_getSize(rpg->world->texture_o->texture).x;
    int x_pos = 300 * (nbr % (size / 300));
    int y_pos = 300 * (nbr / (size / 300));
    sfVector2i quad_offset = {x_pos, y_pos};

    return quad_offset;
}

static void draw_obj_bis(rpg_t *rpg, int **height, sfSprite *sp, int i)
{
    sfVector2i offset = {0, 0};
    sfVector3f point_3d;
    sfVector2f *point = rpg->cam.render->point;

    for (int j = MAP_Y - 1; j > 0; j--) {
        if (rpg->world->object_map[i][j] == 0)
            continue;
        offset = get_object_pos(i, j, rpg);
        point_3d = (sfVector3f){i, height[i][j], j};
        point[0] = to2d(point_3d, rpg);
        point_3d = (sfVector3f){(i + 4), height[i][j], j};
        point[1] = to2d(point_3d, rpg);
        sfSprite_setTextureRect(sp, (sfIntRect){offset.x - 300, offset.y +
        300, 300, -300});
        sfSprite_setPosition(sp, point[0]);
        sfSprite_setScale(sp, (sfVector2f){(point[1].x - point[0].x) /
        150, -(point[1].x - point[0].x) / 150});
        sfRenderWindow_drawSprite(rpg->window, sp, NULL);
    }
}

void draw_object(rpg_t *rpg)
{
    sfRectangleShape *bat = sfRectangleShape_create();
    sfSprite *sprite = sfSprite_create();
    int **height = rpg->world->height_map;

    sfSprite_setTexture(sprite, rpg->world->texture_o->texture, sfTrue);
    for (int i = 1; i < MAP_X - 1; i++) {
        draw_obj_bis(rpg, height, sprite, i);
    }
    sfRectangleShape_destroy(bat);
}
