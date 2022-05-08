/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** player.c
*/

#include "game_engine.h"

static void (*const play_sounds[])(void *) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sfSound_play
};

bool play_sound(object_t *object)
{
    if (!object->entity || !play_sounds[object->entity->type])
        return false;
    (*play_sounds[object->entity->type])(object->entity->data);
    return true;
}

static void (*const stop_sounds[])(void *) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sfSound_stop
};

bool stop_sound(object_t *object)
{
    if (!object->entity || !stop_sounds[object->entity->type])
        return false;
    (*stop_sounds[object->entity->type])(object->entity->data);
    return true;
}

static void (*const pause_sounds[])(void *) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sfSound_pause
};

bool pause_sound(object_t *object)
{
    if (!object->entity || !pause_sounds[object->entity->type])
        return false;
    (*pause_sounds[object->entity->type])(object->entity->data);
    return true;
}
