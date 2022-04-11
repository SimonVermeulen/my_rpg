/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** size.c
*/

#include "game_engine.h"

static void (*const set_sizes[])(void *, sfVector2f) =
{
    NULL,
    NULL,
    NULL,
    sfRectangleShape_setSize,
    NULL,
    NULL
};

bool set_size(object_t *object, sfVector2f size)
{
    if (!object->entity || !set_sizes[object->entity->type])
        return false;
    (*set_sizes[object->entity->type])(object->entity->data, size);
    return true;
}

bool set_size_list(object_t *object, list_t *list)
{
    double *x = get_value_list(list, "x", 2);
    double *y = get_value_list(list, "y", 2);

    if (!x || !y)
        return false;
    return set_size(object, (sfVector2f) {*x, *y});
}