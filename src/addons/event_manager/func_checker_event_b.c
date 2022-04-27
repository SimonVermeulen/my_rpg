/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** func_checker_event_b
*/

#include "game.h"

bool is_key_pressed_event(engine_t *engine, object_t *object, void *event)
{
    int value = *((double *) event);
    bool result = if_key_pressed(engine, value);

    return result;
}

bool is_key_released_event(engine_t *engine, object_t *object, void *event)
{
    int value = *((double *) event);

    return if_key_released(engine, value);
}