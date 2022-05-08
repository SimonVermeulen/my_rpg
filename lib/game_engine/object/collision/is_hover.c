/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** is_hover.c
*/

#include "game_engine.h"
#include <math.h>

bool get_hover_by_point(collision_t *a, sfVector2f point)
{
    float distance = 0;
    sfVector2f pa = get_position(a->object);

    if (a->trigger)
        return false;
    if (a->type == CIRCLE) {
        distance = sqrt(pow(point.x - (a->circle.point.x + pa.x), 2) +
            pow(point.y - (a->circle.point.y + pa.y), 2));
        return (distance <= a->circle.radius) ? true : false;
    }
    if (a->type == BOX) {
        return sfFloatRect_contains(&a->box, point.x, point.y);
    }
    return false;
}

bool is_hover(engine_t *engine, object_t *object)
{
    sfVector2f mouse = get_mouse_position(engine);
    node_t *travel = object->collision.collisions->head;
    collision_t *collision = NULL;

    for (int i = 0; i < object->collision.collisions->nb_elements; i++) {
        collision = travel->value;
        if (get_hover_by_point(collision, mouse))
            return true;
        travel = travel->next;
    }
    return false;
}

bool is_hover_point(object_t *object, sfVector2f point)
{
    node_t *travel = object->collision.collisions->head;
    collision_t *collision = NULL;

    for (int i = 0; i < object->collision.collisions->nb_elements; i++) {
        collision = travel->value;
        if (get_hover_by_point(collision, point))
            return true;
        travel = travel->next;
    }
    return false;
}

object_t *is_hover_all(engine_t *engine, sfVector2f point)
{
    node_t *travel = NULL;

    if (!engine || !engine->actual_scene->object)
        return NULL;
    travel = engine->actual_scene->object->head;
    for (int i = 0; i < engine->actual_scene->object->nb_elements; i++) {
        if (is_hover_point(travel->value, point))
            return travel->value;
        travel = travel->next;
    }
    return NULL;
}
