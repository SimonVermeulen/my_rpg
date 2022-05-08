/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** get_position.c
*/

#include "game_engine.h"

static sfVector2f (*const get_positions[])(void *) =
{
    sfCircleShape_getPosition,
    sfSprite_getPosition,
    sfConvexShape_getPosition,
    sfRectangleShape_getPosition,
    sfText_getPosition,
    sfSound_getPosition
};

sfVector2f get_position(object_t *object)
{
    if (!object->entity || !get_positions[object->entity->type])
        return (sfVector2f) {0, 0};
    return (*get_positions[object->entity->type])(object->entity->data);
}
