/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** outline_color.c
*/

#include "game_engine.h"

static void (*const set_outline_colors[])(void *, sfColor) =
{
    sfCircleShape_setOutlineColor,
    NULL,
    sfConvexShape_setOutlineColor,
    sfRectangleShape_setOutlineColor,
    sfText_setOutlineColor,
    NULL
};

bool set_outline_color(object_t *object, const char *name)
{
    sfColor *color = get_item_buffer(object, COLOR, name);

    if (!object->entity || !set_outline_colors[object->entity->type] || !color)
        return false;
    (*set_outline_colors[object->entity->type])(object->entity->data, *color);
    return true;
}
