/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** is_trigger.c
*/

#include "game_engine.h"

collision_t *compare_trigger(list_t *scene, object_t *main,
    collision_t *collision);

collision_t *compare_inside_trigger(object_t *object, collision_t *collision,
    object_t *main)
{
    node_t *travel = NULL;
    collision_t *second = NULL;

    if (!object->is_active)
        return NULL;
    travel = object->collision.collisions->head;
    for (int i = 0; i < object->collision.collisions->nb_elements; i++) {
        second = travel->value;
        if (get_collision(collision, second) && object != main &&
            second->trigger)
            return second;
        travel = travel->next;
    }
    if (object->childs)
        return compare_trigger(object->childs, main, collision);
    return NULL;
}

collision_t *compare_trigger(list_t *scene, object_t *main,
    collision_t *collision)
{
    node_t *travel = NULL;
    collision_t *result = NULL;

    travel = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, travel = travel->next) {
        result = compare_inside_trigger(travel->value, collision, main);
        if (result)
            return result;
    }
    return NULL;
}

collision_t *compare_trigger_engine(engine_t *engine, object_t *object,
    collision_t *collision)
{
    collision_t *result = NULL;

    if (!object->is_active)
        return NULL;
    if (engine->actual_scene) {
        result = compare_trigger(engine->actual_scene->object, object,
            collision);
        if (result)
            return result;
    }
    if (engine->const_scene) {
        result = compare_trigger(engine->const_scene->object, object,
            collision);
        if (result)
            return result;
    }
    return NULL;
}

collision_t *is_trigger(engine_t *engine, object_t *object)
{
    node_t *travel = object->collision.collisions->head;
    collision_t *collision = NULL;
    collision_t *result = NULL;

    for (int i = 0; i < object->collision.collisions->nb_elements; i++) {
        collision = travel->value;
        result = compare_trigger_engine(engine, object, collision);
        if (result)
            return result;
        travel = travel->next;
    }
    return NULL;
}