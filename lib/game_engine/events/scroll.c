/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** scroll.c
*/

#include "game_engine.h"

bool is_scrolling(engine_t *engine)
{
    return engine->event.type == sfEvtMouseWheelScrolled;
}

sfMouseWheelScrollEvent *get_scrolling(engine_t *engine)
{
    sfMouseWheelScrollEvent *data = NULL;

    if (engine->event.type == sfEvtMouseWheelScrolled)
        data = &engine->event.mouseWheelScroll;
    return data;
}
