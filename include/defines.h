/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** defines header
*/

#pragma once

#define RES_X 1920
#define RES_Y 1080

#define MAP_X 150
#define MAP_Y 80

// Thanks Epitech's norm
#define OW rpg->overworld
#define PLAYER_OW_HEIGHT 35
#define PLAYER_OW_IDLE_W 20

#define FONT_PATH "assets/font/itc-souvenir/Souvenir-Bold.otf"
#define HUD_PATH "assets/hud/hud_guide.png"

#define SLASH_PATH "assets/combat/slash.png"
#define SLASH_SFX "assets/music/slash.ogg"
#define SLASH_WIDTH 126
#define SLASH_HEIGHT 150

#define BOSS_PATH "assets/combat/boss_spritesheet.png"
#define BOSS_WIDTH 190
#define BOSS_HEIGHT 170
#define BOSS_HEALTH 1000

#define OLBERIC_PATH "assets/combat/sprite_combat_olberic.png"
#define OLBERIC_OW_PATH "assets/overworld/player_overworld.png"
#define OLBERIC_WIDTH 23
#define OLBERIC_HEIGHT 45
#define OLBERIC_HEALTH 100

extern const int olberic_rect_left[26];
extern const int olberic_rect_w[26];

extern const int player_ow_rect_w_r[6];
extern const int player_ow_rect_l_r[6];
extern const int player_ow_rect_w_l[6];
extern const int player_ow_rect_l_l[6];
