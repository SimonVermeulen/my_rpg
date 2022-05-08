/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** radius.c
*/

#include "game_engine.h"

static void (*const set_radiuss[])(void *, float) =
{
    sfCircleShape_setRadius,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

bool set_radius(object_t *object, float radius)
{
    if (!object->entity || !set_radiuss[object->entity->type])
        return false;
    (*set_radiuss[object->entity->type])(object->entity->data, radius);
    return true;
}
