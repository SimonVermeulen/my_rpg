/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** get_bounds.c
*/

#include "game_engine.h"

static sfFloatRect (*const local_bounds[])(const void *) =
{
    sfCircleShape_getLocalBounds,
    sfSprite_getLocalBounds,
    sfConvexShape_getLocalBounds,
    sfRectangleShape_getLocalBounds,
    sfText_getLocalBounds,
    NULL
};

sfFloatRect get_local_bounds(object_t *object)
{
    if (!object->entity || !local_bounds[object->entity->type])
        return (sfFloatRect) {0, 0, 0, 0};
    return (*local_bounds[object->entity->type])(object->entity->data);
}

static sfFloatRect (*const global_bounds[])(const void *) =
{
    sfCircleShape_getGlobalBounds,
    sfSprite_getGlobalBounds,
    sfConvexShape_getGlobalBounds,
    sfRectangleShape_getGlobalBounds,
    sfText_getGlobalBounds,
    NULL
};

sfFloatRect get_global_bounds(object_t *object)
{
    if (!object->entity || !global_bounds[object->entity->type])
        return (sfFloatRect) {0, 0, 0, 0};
    return (*global_bounds[object->entity->type])(object->entity->data);
}