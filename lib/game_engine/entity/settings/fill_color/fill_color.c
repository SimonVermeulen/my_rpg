/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** fill_color.c
*/

#include "game_engine.h"

static void (*const set_fill_colors[])(void *, sfColor) =
{
    sfCircleShape_setFillColor,
    NULL,
    sfConvexShape_setFillColor,
    sfRectangleShape_setFillColor,
    sfText_setFillColor,
    NULL
};

bool set_fill_color(object_t *object, const char *name)
{
    sfColor *color = get_item_buffer(object, COLOR, name);

    if (!object->entity || !set_fill_colors[object->entity->type] || !color)
        return false;
    (*set_fill_colors[object->entity->type])(object->entity->data, *color);
    return true;
}