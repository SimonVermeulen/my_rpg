/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** init_collision.c
*/

#include "game_engine.h"

bool add_box_collision(list_t *list, collision_t *collision)
{
    double *left = get_value_list(list, "left", 2);
    double *top = get_value_list(list, "top", 2);
    double *width = get_value_list(list, "width", 2);
    double *height = get_value_list(list, "height", 2);

    collision->box = (sfFloatRect) {0, 0, 0, 0};
    if (!left || !top || !width || !height)
        return false;
    collision->box.left = *left;
    collision->box.top = *top;
    collision->box.width = *width;
    collision->box.height = *height;
    return true;
}

bool add_circle_collision(list_t *list, collision_t *collision)
{
    double *x = get_value_list(list, "x", 2);
    double *y = get_value_list(list, "y", 2);
    double *radius = get_value_list(list, "radius", 2);

    collision->circle.point.x = 0;
    collision->circle.point.y = 0;
    collision->circle.radius = 0;
    if (!x || !y || !radius)
        return false;
    collision->circle.point.x = *x;
    collision->circle.point.y = *y;
    collision->circle.radius = *radius;
    return true;
}

bool add_collision(list_t *list, object_t *object)
{
    char *name = get_value_list(list, "name", 4);
    int *trigger = get_value_list(list, "trigger", 3);
    list_t *box = get_value_list(list, "box", 1);
    list_t *circle = get_value_list(list, "circle", 1);
    collision_t *collision = NULL;

    if (!name || !trigger || (!box && !circle))
        return true;
    collision = malloc(sizeof(collision_t));
    if (!collision)
        return false;
    if (box)
        add_box_collision(box, collision);
    if (circle)
        add_circle_collision(circle, collision);
    collision->trigger = *trigger % 2;
    collision->type = (box) ? 0 : 1;
    collision->object = object;
    return (create_add_node(collision, 0, name, object->collision.collisions))
        ? true : false;
}

bool init_collision(list_t *list, object_t *object)
{
    node_t *node_collisions = search_from_key(list, "collisions");
    list_t **collisions = NULL;

    if (!node_collisions || node_collisions->type != 10)
        return true;
    collisions = node_collisions->value;
    for (int i = 0; i < node_collisions->len; i++) {
        if (!add_collision(collisions[i], object))
            return false;
    }
    return true;
}