/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** scale.c
*/

#include "game_engine.h"

static void (*const set_scales[])(void *, sfVector2f) =
{
    sfCircleShape_setScale,
    sfSprite_setScale,
    sfConvexShape_setScale,
    sfRectangleShape_setScale,
    sfText_setScale,
    NULL
};

bool set_scale_vector(object_t *object, sfVector2f scale)
{
    if (!object->entity || !set_scales[object->entity->type])
        return false;
    (*set_scales[object->entity->type])(object->entity->data, scale);
    return true;
}

bool set_scale_float(object_t *object, float x, float y)
{
    return set_scale_vector(object, (sfVector2f) {x, y});
}

bool set_scale_list(object_t *object, list_t *list)
{
    double *x = get_value_list(list, "x", 2);
    double *y = get_value_list(list, "y", 2);

    if (!x || !y)
        return false;
    return set_scale_vector(object, (sfVector2f) {*x, *y});
}

static void (*const scales[])(void *, sfVector2f) =
{
    sfCircleShape_scale,
    sfSprite_scale,
    sfConvexShape_scale,
    sfRectangleShape_scale,
    sfText_scale,
    NULL
};

bool scale_vector(object_t *object, sfVector2f scale)
{
    if (!object->entity || !scales[object->entity->type])
        return false;
    (*scales[object->entity->type])(object->entity->data, scale);
    return true;
}

bool scale_float(object_t *object, float x, float y)
{
    return scale_vector(object, (sfVector2f) {x, y});
}
