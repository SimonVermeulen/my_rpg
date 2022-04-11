/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** set_position.c
*/

#include "game_engine.h"

static void (*const set_positions[])(void *, sfVector2f) =
{
    sfCircleShape_setPosition,
    sfSprite_setPosition,
    sfConvexShape_setPosition,
    sfRectangleShape_setPosition,
    sfText_setPosition,
    sfSound_setPosition
};

bool set_position_vector(object_t *object, sfVector2f position)
{
    if (!object->entity || !set_positions[object->entity->type])
        return false;
    (*set_positions[object->entity->type])(object->entity->data, position);
    return true;
}

bool set_position_float(object_t *object, float x, float y)
{
    return set_position_vector(object, (sfVector2f) {x, y});
}

bool set_position_list(object_t *object, list_t *list)
{
    double *x = get_value_list(list, "x", 2);
    double *y = get_value_list(list, "y", 2);

    if (!x || !y)
        return false;
    return set_position_float(object, *x, *y);
}

bool move_float(object_t *object, float x, float y)
{
    sfVector2f position = get_position(object);

    position.x += x;
    position.y += y;
    return set_position_vector(object, position);
}

bool move_vector(object_t *object, sfVector2f position)
{
    return move_float(object, position.x, position.y);
}