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

const static char *errors[] = {
    "assets/combat/player/olberic_cmb_apo.png",
    "assets/combat/player/olberic_cmb_cleric.png",
    "assets/combat/player/olberic_cmb_pea.png",
    "assets/combat/boss_spritesheet.png",
    "assets/combat/slash.png",
    "assets/environement/pn.png",
    "assets/environement/po.png",
    "assets/environement/pr.png",
    "assets/font/arial/arial.ttf",
    "assets/font/itc-souvenir/Souvenir-Bold.otf",
    "assets/hud/hud_guide.png",
    "assets/items/armor.png",
    "assets/items/godsbeard.png",
    "assets/items/sword.png",
    "assets/menu/background.png",
    "assets/menu/button_toggle.png",
    "assets/menu/button.png",
    "assets/menu/farground.png",
    "assets/menu/inventory.png",
    "assets/menu/midground.png",
    "assets/menu/slots.png",
    "assets/music/slash.ogg",
    "assets/music/vista.ogg",
    "assets/overworld/olberic_ow_cleric.png",
    "assets/overworld/olberic_ow_pea.png",
    "assets/overworld/player_overworld.png",
    "assets/pnj/alagard.ttf",
    "assets/pnj/chatbox.png"
};

int errors_manager(void)
{
    int fd = 0;

    for (size_t i = 0; i < 28; i++) {
        fd = open(errors[i], O_RDONLY);
        if (fd < 3) {
            write(2, "Error occured in the loading of the assets.\n", 44);
            return (84);
        }
    }
    return (0);
}