/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** origin.c
*/

#include "game_engine.h"

static void (*const set_origins[])(void *, sfVector2f) =
{
    sfCircleShape_setScale,
    sfSprite_setScale,
    sfConvexShape_setScale,
    sfRectangleShape_setScale,
    sfText_setScale,
    NULL
};

bool set_origin(object_t *object, sfVector2f origin)
{
    if (!object->entity || !set_origins[object->entity->type])
        return false;
    (*set_origins[object->entity->type])(object->entity->data, origin);
    return true;
}

bool set_origin_list(object_t *object, list_t *list)
{
    double *x = get_value_list(list, "x", 2);
    double *y = get_value_list(list, "y", 2);

    if (!x || !y)
        return false;
    return set_origin(object, (sfVector2f) {*x, *y});
}

bool set_origin_anchor(object_t *object, int type)
{
    sfFloatRect rect = get_local_bounds(object);
    int anchors[9][2] = {{0, 0}, {rect.width / 2, 0}, {rect.width, 0},
        {0, rect.height / 2}, {rect.width / 2, rect.height / 2},
        {rect.width, rect.height / 2}, {0, rect.height},
        {rect.width / 2, rect.height}, {rect.width, rect.height}};
    
    if (type < 0 || type >= 8)
        return false;
    return set_origin(object, (sfVector2f) {anchors[type][0],
        anchors[type][1]});
}