/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** key.c
*/

#include "game_engine.h"

bool if_key_pressed(engine_t *engine, int key)
{
    return engine->event.type == sfEvtKeyPressed &&
        engine->event.key.code == key;
}

bool if_key_released(engine_t *engine, int key)
{
    return engine->event.type == sfEvtKeyReleased &&
        engine->event.key.code == key;
}

sfKeyEvent *get_key_pressed(engine_t *engine, int key)
{
    sfKeyEvent *data = NULL;

    if (engine->event.type == sfEvtKeyPressed &&
        engine->event.key.code == key)
        data = &engine->event.key;
    return data;
}

sfKeyEvent *get_key_released(engine_t *engine, int key)
{
    sfKeyEvent *data = NULL;

    if (engine->event.type == sfEvtKeyReleased &&
        engine->event.key.code == key)
        data = &engine->event.key;
    return data;
}