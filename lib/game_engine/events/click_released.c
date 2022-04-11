/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** click_released.c
*/

#include "game_engine.h"

bool get_left_click_released(engine_t *engine)
{
    return engine->event.type == sfEvtMouseButtonReleased
        && engine->event.mouseButton.button == sfMouseLeft;
}

bool get_right_click_released(engine_t *engine)
{
    return engine->event.type == sfEvtMouseButtonReleased
        && engine->event.mouseButton.button == sfMouseRight;
}

bool get_middle_click_released(engine_t *engine)
{
    return engine->event.type == sfEvtMouseButtonReleased
        && engine->event.mouseButton.button == sfMouseMiddle;
}

bool get_extra_click_released(engine_t *engine, int number)
{
    return engine->event.type == sfEvtMouseButtonReleased
        && engine->event.mouseButton.button == number;
}