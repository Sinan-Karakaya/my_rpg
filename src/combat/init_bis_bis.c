/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init bis
*/

#include "my_rpg.h"

static int assign_bis(rpg_t *rpg)
{
    if (rpg->combat->player->stat->class == RPG_CLASS_PEASANT) {
        rpg->combat->player->texture = sfTexture_createFromFile(
        OLBERIC_PE_PATH, NULL);
        OW->texture = sfTexture_createFromFile(OLBERIC_OW_PE_PATH, NULL);
        if (!rpg->combat->player->texture || !OW->texture)
            return (84);
        sfSprite_setTexture(rpg->combat->player->sprite,
        rpg->combat->player->texture, sfFalse);
        sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
    }
    return 0;
}

int assign_class(rpg_t *rpg)
{
    if (rpg->combat->player->stat->class == RPG_CLASS_WARRIOR) {
        P_TEXTU = sfTexture_createFromFile(OLBERIC_WA_PATH, NULL);
        OW->texture = sfTexture_createFromFile(OLBERIC_OW_PATH, NULL);
        if (!rpg->combat->player->texture || !OW->texture)
            return 84;
        sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
        sfSprite_setTexture(rpg->combat->player->sprite,
        rpg->combat->player->texture, sfFalse);
        rpg->combat->player->stat->attack += 5;
    } if (rpg->combat->player->stat->class == RPG_CLASS_CLERIC) {
        P_TEXTU = sfTexture_createFromFile(OLBERIC_CL_PATH, NULL);
        OW->texture = sfTexture_createFromFile(OLBERIC_OW_CL_PATH, NULL);
        if (!rpg->combat->player->texture || !OW->texture)
            return 84;
        sfSprite_setTexture(rpg->combat->player->sprite,
        rpg->combat->player->texture, sfFalse);
        sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
        rpg->combat->player->max_life += 10;
    } return assign_bis(rpg);
}

int assign_class_valid_save(rpg_t *rpg)
{
    if (rpg->combat->player->stat->class == RPG_CLASS_WARRIOR) {
        rpg->combat->player->texture = sfTexture_createFromFile(
        OLBERIC_WA_PATH, NULL);
        OW->texture = sfTexture_createFromFile(OLBERIC_OW_PATH, NULL);
        if (!rpg->combat->player->texture || !OW->texture)
            return (84);
        sfSprite_setTexture(rpg->combat->player->sprite,
        rpg->combat->player->texture, sfFalse);
        sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
    } if (rpg->combat->player->stat->class == RPG_CLASS_CLERIC) {
        rpg->combat->player->texture = sfTexture_createFromFile(
        OLBERIC_CL_PATH, NULL);
        OW->texture = sfTexture_createFromFile(OLBERIC_OW_CL_PATH, NULL);
        if (!rpg->combat->player->texture || !OW->texture)
            return (84);
        sfSprite_setTexture(rpg->combat->player->sprite,
        rpg->combat->player->texture, sfFalse);
        sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
    } return assign_bis(rpg);
}
