/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** sound.c
*/

#include "game_engine.h"

static void (*const set_buffers[])(void *, const sfSoundBuffer *) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sfSound_setBuffer
};

bool set_buffer(object_t *object, const char *name)
{
    sfSoundBuffer *buffer = get_item_buffer(object, SOUNDBUFFER, name);

    if (!object->entity || !set_buffers[object->entity->type] || !buffer)
        return false;
    (*set_buffers[object->entity->type])(object->entity->data, buffer);
    return true;
}

static void (*const set_loops[])(void *, sfBool) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sfSound_setLoop
};

bool set_loop(object_t *object, sfBool loop)
{
    if (!object->entity || !set_loops[object->entity->type])
        return false;
    (*set_loops[object->entity->type])(object->entity->data, loop);
    return true;
}

static void (*const set_pitchs[])(void *, float) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sfSound_setPitch
};

bool set_pitch(object_t *object, float pitch)
{
    if (!object->entity || !set_pitchs[object->entity->type])
        return false;
    (*set_pitchs[object->entity->type])(object->entity->data, pitch);
    return true;
}

static void (*const set_volumes[])(void *, float) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sfSound_setVolume
};

bool set_volume(object_t *object, float volume)
{
    if (!object->entity || !set_pitchs[object->entity->type])
        return false;
    (*set_volumes[object->entity->type])(object->entity->data, volume);
    return true;
}
