/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** point.c
*/

#include "game_engine.h"

static void (*const set_points[])(void *, size_t, sfVector2f) =
{
    NULL,
    NULL,
    sfConvexShape_setPoint,
    NULL,
    NULL,
    NULL
};

bool set_point(object_t *object, size_t index, sfVector2f point)
{
    if (!object->entity || !set_points[object->entity->type])
        return false;
    (*set_points[object->entity->type])(object->entity->data, index, point);
    return true;
}

void add_point_by_list(object_t *object, list_t *list)
{
    int *index = get_value_list(list, "index", 3);
    double *x = get_value_list(list, "x", 2);
    double *y = get_value_list(list, "y", 2);

    if (!index || !x || !y)
        return;
    set_point(object, *index, (sfVector2f) {*x, *y});
}

bool set_point_list(object_t *object, list_t *list)
{
    node_t *points_node = search_from_key(list, "points");
    list_t **points = NULL;

    if (!points_node || points_node->type != 10)
        return false;
    points = points_node->value;
    for (int i = 0; i < points_node->len; i++)
        add_point_by_list(object, points[i]);
    return true;
}
