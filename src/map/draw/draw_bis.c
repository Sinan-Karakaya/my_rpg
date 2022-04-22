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

    for (int i = 1; i < MAP_X - 1; i++) {
        for (int j = MAP_Y - 1; j > 0; j--) {
            quad_offset = get_texture_pos(i, j, rpg);
            point_3d = (sfVector3f){i, height[i][j], j};
            point[0] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i + 1), height[i + 1][j], j};
            point[1] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i  + 1), height[i + 1][j + 1], j + 1};
            point[2] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, quad_offset, 1);
            point_3d = (sfVector3f){(i), height[i][j + 1], j + 1};
            point[1] = to2d(point_3d, rpg);
            draw_triangle(point, rpg, quad_offset, 2);
        }
    }
}

sfVector2i get_object_pos(int x, int y, rpg_t *rpg)
{
    int nbr = rpg->world->object_map[x][y];
    int size = sfTexture_getSize(rpg->texture_o->texture).x;
    int x_pos = 300 * (nbr % (size / 300));
    int y_pos = 300 * (nbr / (size / 300));
    sfVector2i quad_offset = {x_pos, y_pos};

    return quad_offset;
}

void draw_object(rpg_t *rpg)
{
    sfRectangleShape *bat = sfRectangleShape_create();
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, rpg->texture_o->texture, sfTrue);
    sfVector2f *point = rpg->cam.render->point;
    int **height = rpg->world->height_map;
    sfVector3f point_3d;
    sfVector2i ofset = {0, 0};
    sfTime time = sfClock_getElapsedTime(rpg->world->water_clock);
    int milli_time = sfTime_asMilliseconds(time) / 7000;

    for (int i = 1; i < MAP_X - 1; i++) {
        for (int j = MAP_Y - 1; j > 0; j--) {
            if (rpg->world->object_map[i][j] == 0) {
                continue;
            }
            ofset = get_object_pos(i, j, rpg);
            point_3d = (sfVector3f){i, height[i][j], j};
            point[0] = to2d(point_3d, rpg);
            point_3d = (sfVector3f){(i + 4), height[i][j], j};
            point[1] = to2d(point_3d, rpg);
            sfSprite_setTextureRect(sprite, (sfIntRect){ofset.x - 300, ofset.y + 300, 300, -300});
            sfSprite_setPosition(sprite, point[0]);
            sfSprite_setScale(sprite, (sfVector2f){(point[1].x - point[0].x) / 150, -(point[1].x - point[0].x) / 150});
            sfRenderWindow_drawSprite(rpg->window, sprite, NULL);
        }
    }
    sfRectangleShape_destroy(bat);
}