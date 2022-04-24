/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** time utils func
*/

#include "my_rpg.h"

float get_time(sfClock *clock)
{
    return (sfClock_getElapsedTime(clock).microseconds / 1000000.0);
}

float get_time_mil(sfClock *clock)
{
    return (sfClock_getElapsedTime(clock).microseconds / 1000.0);
}

float get_dt(sfClock *game_clock)
{
    return sfClock_restart(game_clock).microseconds * 0.000001;
}
