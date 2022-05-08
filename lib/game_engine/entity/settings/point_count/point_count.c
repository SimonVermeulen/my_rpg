/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** point_count.c
*/

#include "game_engine.h"

static void (*const set_point_counts[])(void *, size_t) =
{
    sfCircleShape_setPointCount,
    NULL,
    sfConvexShape_setPointCount,
    NULL,
    NULL,
    NULL
};

bool set_point_count(object_t *object, size_t count)
{
    if (!object->entity || !set_point_counts[object->entity->type])
        return false;
    (*set_point_counts[object->entity->type])(object->entity->data, count);
    return true;
}
