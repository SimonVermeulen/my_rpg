/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** time.c
*/

#include "game_engine.h"

int set_time(engine_t *engine)
{
    engine->time.delta_time = sfClock_create();
    engine->time.delta = 0;
    engine->time.time = sfClock_create();
    if (engine->time.delta_time == NULL || engine->time.time == NULL)
        return 84;
    return 0;
}

float get_delta(engine_t *engine)
{
    float a = sfClock_getElapsedTime(engine->time.delta_time).microseconds;
    float b = 1000;

    return a / b;
}
