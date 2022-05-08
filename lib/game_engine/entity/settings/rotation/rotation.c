/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** rotation.c
*/

#include "game_engine.h"

static void (*const set_rotations[])(void *, float) =
{
    sfCircleShape_setRotation,
    sfSprite_setRotation,
    sfConvexShape_setRotation,
    sfRectangleShape_setRotation,
    sfText_setRotation,
    NULL
};

bool set_rotation(object_t *object, float angle)
{
    if (!object->entity || !set_rotations[object->entity->type])
        return false;
    (*set_rotations[object->entity->type])(object->entity->data, angle);
    return true;
}

static void (*const rotates[])(void *, float) =
{
    sfCircleShape_rotate,
    sfSprite_rotate,
    sfConvexShape_rotate,
    sfRectangleShape_rotate,
    sfText_rotate,
    NULL
};

bool rotate(object_t *object, float angle)
{
    if (!object->entity || !rotates[object->entity->type])
        return false;
    (*rotates[object->entity->type])(object->entity->data, angle);
    return true;
}
