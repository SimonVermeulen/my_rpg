/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** outline_color.c
*/

#include "game_engine.h"

static void (*const set_outline_thicknesss[])(void *, sfColor) =
{
    sfCircleShape_setOutlineThickness,
    NULL,
    sfConvexShape_setOutlineThickness,
    sfRectangleShape_setOutlineThickness,
    sfText_setOutlineThickness,
    NULL
};

bool set_outline_thickness(object_t *object, const char *name)
{
    sfColor *color = get_item_buffer(object, COLOR, name);

    if (!object->entity || !set_outline_thicknesss[object->entity->type] ||
        !color)
        return false;
    (*set_outline_thicknesss[object->entity->type])(object->entity->data,
        *color);
    return true;
}
