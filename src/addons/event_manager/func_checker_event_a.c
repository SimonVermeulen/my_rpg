/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** func_checker_event
*/

#include "game.h"

bool is_click_event(engine_t *engine, object_t *object, void *event)
{
    if (get_left_click_pressed(engine) && is_hover(engine, object))
        return true;
    return false;
}

bool is_time_event(engine_t *engine, object_t *object, void *event)
{
    double *time = event;

    if (*time <= 0)
        return true;
    *time -= get_delta(engine);
    return false;
}

bool is_hover_event(engine_t *engine, object_t *object, void *event)
{
    return is_hover(engine, object);
}

bool is_trigger_event(engine_t *engine, object_t *object, void *event)
{
    return (is_trigger(engine, object)) ? true : false;
}