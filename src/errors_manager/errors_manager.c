/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** errors_manager
*/

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

const char *errors[] = {
    "assets/cinematic/back_ground.png",
    "assets/cinematic/car_crash.ogg",
    "assets/cinematic/road.png",
    "assets/cinematic/tehla.png",
    "assets/cinematic/tessla.png",
    "assets/combat/player/olberic_cmb_apo.png",
    "assets/combat/player/olberic_cmb_cleric.png",
    "assets/combat/player/olberic_cmb_pea.png",
    "assets/combat/bear.png",
    "assets/combat/boss_spritesheet.png",
    "assets/combat/slash.png",
    "assets/combat/wolf.png",
    "assets/environement/po.png",
    "assets/environement/pp.png",
    "assets/environement/pr.png",
    "assets/font/arial/arial.ttf",
    "assets/font/itc-souvenir/Souvenir-Bold.otf",
    "assets/hud/hud_guide.png",
    "assets/items/armor_rm.png",
    "assets/items/armor.png",
    "assets/items/boots.png",
    "assets/items/godsbeard.png",
    "assets/items/helmet_rm.png",
    "assets/items/sword_rm.png",
    "assets/items/sword.png",
    "assets/menu/background.png",
    "assets/menu/button_toggle.png",
    "assets/menu/button.png",
    "assets/menu/class_scroll.png",
    "assets/menu/class_selection.png",
    "assets/menu/farground.png",
    "assets/menu/htp.png",
    "assets/menu/inventory.png",
    "assets/menu/midground.png",
    "assets/menu/slots.png",
    "assets/music/slash.ogg",
    "assets/music/vista.ogg",
    "assets/music/combat.ogg",
    "assets/overworld/olberic_ow_cleric.png",
    "assets/overworld/olberic_ow_pea.png",
    "assets/overworld/player_overworld.png",
    "assets/pnj/alagard.ttf",
    "assets/pnj/chatbox.png",
    NULL
};

static char *my_strndup(char *src, int n)
{
    char *new = malloc(sizeof(char) * (n + 1));
    int i = 0;

    for (; i < n; i++)
        new[i] = src[i];
    new[i] = '\0';
    return new;
}

static int is_existing(char **env, char *args)
{
    char *my_env;
    int len = my_strlen(args);
    int i = 0;

    for (; env[i] != NULL; i++) {
        my_env = my_strndup(env[i], len);
        if (my_strcmp(my_env, args) == 0)
            return 0;
    }
    return 84;
}

static int check_env(char **env)
{
    if (!env)
        return 84;
    if (is_existing(env, "DISPLAY") == 84)
        return 84;
    return 0;
}

int errors_manager(char **env)
{
    int fd = 0;

    if (check_env(env) == 84) {
        write(2, "Error occured in the env.\n", 26);
        return 84;
    }
    for (size_t i = 0; errors[i] != NULL; i++) {
        fd = open(errors[i], O_RDONLY);
        if (fd < 3) {
            write(2, "Error occured in the loading of the assets.\n", 44);
            return 84;
        }
        close(fd);
    }
    return 0;
}
