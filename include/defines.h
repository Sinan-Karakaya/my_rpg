/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** defines header
*/

#pragma once

#include <unistd.h>

#define ERROR(str) write(2, "ERROR: Could not load:", 23); \
                   write(2, str, my_strlen(str)); \
                   write(2, "\n", 1);

#define RES_X 1920
#define RES_Y 1080

#define IS_SHADER 1
#define SHADE sfShader_createFromFile(NULL, NULL, "src/map/draw/light.frag");

#define MAP_X 150
#define MAP_Y 80
#define NB_NPC 50

#define DRAW_BIS_REC offset.y + 300 * frame, 300, -300}
#define DRAW_BIS_TEX sp, (sfIntRect){offset.x - 300,

#define CINE_PLAYER rpg->cine->player
#define CAR_PATH "assets/cinematic/tehla.png"
#define CAR_SFX "assets/cinematic/car_crash.ogg"

// MENU
#define MENU_BG "assets/menu/background.png"
#define MENU_FAR "assets/menu/farground.png"
#define MENU_MID "assets/menu/midground.png"

#define CLASS_MENU "assets/menu/class_selection.png"

#define SHADER_PATH "shader/fragment_shader.fs"

#define IN_OVERWORLD (rpg->scene == OVERWORLD)
#define OVERWORLD_MUSIC "assets/music/vista.ogg"
#define BATTLE_MUSIC NULL

// Thanks Epitech's norm
#define OW rpg->overworld
#define PLAYER_OW_HEIGHT 35
#define PLAYER_OW_IDLE_W 20

#define FONT_PATH "assets/font/itc-souvenir/Souvenir-Bold.otf"
#define HUD_PATH "assets/hud/hud_guide.png"

#define STAT rpg->combat->player->stat

#define SLASH_PATH "assets/combat/slash.png"
#define SLASH_SFX "assets/music/slash.ogg"
#define SLASH_WIDTH 126
#define SLASH_HEIGHT 150

#define BOSS_PATH "assets/combat/boss_spritesheet.png"
#define BOSS_WIDTH 190
#define BOSS_HEIGHT 170
#define BOSS_HEALTH 1000

#define OLBERIC_WA_PATH "assets/combat/player/olberic_cmb_apo.png"
#define OLBERIC_CL_PATH "assets/combat/player/olberic_cmb_cleric.png"
#define OLBERIC_PE_PATH "assets/combat/player/olberic_cmb_pea.png"
#define OLBERIC_OW_PATH "assets/overworld/player_overworld.png"
#define OLBERIC_OW_CL_PATH "assets/overworld/olberic_ow_cleric.png"
#define OLBERIC_OW_PE_PATH "assets/overworld/olberic_ow_pea.png"
#define OLBERIC_WIDTH 23
#define OLBERIC_HEIGHT 45
#define OLBERIC_HEALTH 100

#define BEAR_PATH "assets/combat/bear.png"
#define BEAR_HEIGHT 98
#define BEAR_WIDTH 87
#define BEAR_FRAMES 6

#define WOLF_PATH "assets/combat/wolf.png"
#define WOLF_HEIGHT 57
#define WOLF_WIDTH 95
#define WOLF_FRAMES 8

#define KEYUP rpg->keybinds->key_up
#define KEYDOWN rpg->keybinds->key_down
#define KEYLEFT rpg->keybinds->key_left
#define KEYRIGHT rpg->keybinds->key_right
#define KEYINV rpg->keybinds->key_inventory
#define KEYATK rpg->keybinds->key_attack
#define KEYPROTECT rpg->keybinds->key_protect
#define KEYRUN rpg->keybinds->key_run

#define PLAYER_STATS rpg->combat->player->stat
#define STUFF rpg->combat->player->stat->stuff

#define INVENTORY rpg->menu->inventory
#define SCALE_PNJ_X (sfVector2f){(point[1].x - point[0].x) / 150
#define SCALE_PNJ_Y -(point[1].x - point[0].x) / 150}
#define HEIGHT rpg->world->height_map
#define CREATE_CHAT sfTexture_createFromFile("assets/pnj/chatbox.png", NULL)
#define SET_TEX sfSprite_setTexture
#define TEX_CB rpg->world->gui.chatbox_texture,

#define CALCUL_1(x, y, i, j) (sfVector2f){((point[1].x - point[0].x) / 150 * \
                             (offset_tab[rpg->world->object_map[i][j]].y - \
                             offset_tab[rpg->world->object_map[i][j]].x)), \
                             -(point[1].x - point[0].x) * 0.1})

#define CALCUL_2(x, y, i, j) (sfVector2f){point[0].x + ((point[1].x - \
                             point[0].x) / 150 * \
                             offset_tab[rpg->world->object_map[i][j]].x),\
                             point[0].y})

extern const int olberic_rect_left[26];
extern const int olberic_rect_w[26];

extern const int player_ow_rect_w_l[6];
extern const int player_ow_rect_l_l[6];
extern const int player_ow_rect_w_r[6];
extern const int player_ow_rect_l_r[6];
