/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init bis
*/

#include "my_rpg.h"

static void assign_bis(rpg_t *rpg)
{
    if (rpg->combat->player->stat->class == RPG_CLASS_PEASANT) {
        rpg->combat->player->texture = sfTexture_createFromFile(OLBERIC_PE_PATH, NULL);
        sfSprite_setTexture(rpg->combat->player->sprite,
        rpg->combat->player->texture, sfFalse);
        OW->texture = sfTexture_createFromFile(OLBERIC_OW_PE_PATH, NULL);
        sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
    }
}

void assign_class(rpg_t *rpg)
{
    if (rpg->combat->player->stat->class == RPG_CLASS_WARRIOR) {
        rpg->combat->player->texture = sfTexture_createFromFile(OLBERIC_WA_PATH, NULL);
        sfSprite_setTexture(rpg->combat->player->sprite,
        rpg->combat->player->texture, sfFalse);
        OW->texture = sfTexture_createFromFile(OLBERIC_OW_PATH, NULL);
        sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
        rpg->combat->player->stat->attack += 5;
    } if (rpg->combat->player->stat->class == RPG_CLASS_CLERIC) {
        rpg->combat->player->max_life += 10;
        rpg->combat->player->texture = sfTexture_createFromFile(OLBERIC_CL_PATH, NULL);
        sfSprite_setTexture(rpg->combat->player->sprite,
        rpg->combat->player->texture, sfFalse);
        OW->texture = sfTexture_createFromFile(OLBERIC_OW_CL_PATH, NULL);
        sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
    } assign_bis(rpg);
}

void assign_class_valid_save(rpg_t *rpg)
{
    if (rpg->combat->player->stat->class == RPG_CLASS_WARRIOR) {
        rpg->combat->player->texture = sfTexture_createFromFile(OLBERIC_WA_PATH, NULL);
        sfSprite_setTexture(rpg->combat->player->sprite,
        rpg->combat->player->texture, sfFalse);
        OW->texture = sfTexture_createFromFile(OLBERIC_OW_PATH, NULL);
        sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
    } if (rpg->combat->player->stat->class == RPG_CLASS_CLERIC) {
        rpg->combat->player->texture = sfTexture_createFromFile(OLBERIC_CL_PATH, NULL);
        sfSprite_setTexture(rpg->combat->player->sprite,
        rpg->combat->player->texture, sfFalse);
        OW->texture = sfTexture_createFromFile(OLBERIC_OW_CL_PATH, NULL);
        sfSprite_setTexture(OW->spr, OW->texture, sfFalse);
    } assign_bis(rpg);
}
