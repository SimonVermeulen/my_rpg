/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** 3d_parameter.c
*/

#include "game_engine.h"

static void (*const set_relatives[])(void *, sfBool) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sfSound_setRelativeToListener
};

bool set_relative(object_t *object, sfBool relative)
{
    if (!object->entity || !set_relatives[object->entity->type])
        return false;
    (*set_relatives[object->entity->type])(object->entity->data, relative);
    return true;
}

static void (*const set_min_distances[])(void *, float) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sfSound_setMinDistance
};

bool set_min_distance(object_t *object, float distance)
{
    if (!object->entity || !set_min_distances[object->entity->type])
        return false;
    (*set_min_distances[object->entity->type])(object->entity->data, distance);
    return true;
}

static void (*const set_attenuations[])(void *, float) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sfSound_setMinDistance
};

bool set_attenuation(object_t *object, float attenuation)
{
    if (!object->entity || !set_attenuations[object->entity->type])
        return false;
    (*set_attenuations[object->entity->type])(object->entity->data,
        attenuation);
    return true;
}

static void (*const set_playing_offsets[])(void *, sfInt64) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sfSound_setPlayingOffset
};

bool set_playing_offset(object_t *object, sfInt64 microseconds)
{
    if (!object->entity || !set_playing_offsets[object->entity->type])
        return false;
    (*set_playing_offsets[object->entity->type])(object->entity->data,
        microseconds);
    return true;
}
