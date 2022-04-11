/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** string.c
*/

#include "game_engine.h"

static void (*const set_strings[])(void *, const char *) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    sfText_setString,
    NULL
};

bool set_string(object_t *object, const char *string)
{
    if (!object->entity || !set_strings[object->entity->type])
        return false;
    (*set_strings[object->entity->type])(object->entity->data, string);
    return true;
}