/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** color.c
*/

#include "game_engine.h"

static void (*const set_colors[])(void *, sfColor) =
{
    NULL,
    sfSprite_setColor,
    NULL,
    NULL,
    sfText_setColor,
    NULL
};

bool set_color(object_t *object, const char *name)
{
    sfColor *color = get_item_buffer(object, COLOR, name);

    if (!object->entity || !set_colors[object->entity->type] || !color)
        return false;
    (*set_colors[object->entity->type])(object->entity->data, *color);
    return true;
}
