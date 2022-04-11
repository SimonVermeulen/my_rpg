/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** click_pressed.c
*/

#include "game_engine.h"

bool get_left_click_pressed(engine_t *engine)
{
    return engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseLeft;
}

bool get_right_click_pressed(engine_t *engine)
{
    return engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseRight;
}

bool get_middle_click_pressed(engine_t *engine)
{
    return engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == sfMouseMiddle;
}

bool get_extra_click_pressed(engine_t *engine, int number)
{
    return engine->event.type == sfEvtMouseButtonPressed
        && engine->event.mouseButton.button == number;
}