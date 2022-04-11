/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** is_trigger.c
*/

#include "game_engine.h"

bool compare_trigger(list_t *scene, object_t *main, collision_t *collision);

bool compare_inside_trigger(object_t *object, collision_t *collision, object_t *main)
{
    node_t *travel = NULL;
    collision_t *second = NULL;

    if (!object->is_active)
        return false;
    travel = object->collision.collisions->head;
    for (int i = 0; i < object->collision.collisions->nb_elements; i++) {
        second = travel->value;
        if (get_collision(collision, second) && object != main &&
            second->trigger)
            return true;
        travel = travel->next;
    }
    if (object->childs)
        if (compare_trigger(object->childs, main, collision))
            return true;
    return false;
}

bool compare_trigger(list_t *scene, object_t *main, collision_t *collision)
{
    node_t *travel = NULL;

    travel = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, travel = travel->next) {
        if (compare_inside_trigger(travel->value, collision, main))
            return true;
    }
    return false;
}

bool compare_trigger_engine(engine_t *engine, object_t *object,
    collision_t *collision)
{
    if (!object->is_active)
        return false;
    if (engine->actual_scene)
        if (compare_trigger(engine->actual_scene->object, object, collision))
            return true;
    if (engine->const_scene)
        if (compare_trigger(engine->const_scene->object, object, collision))
            return true;
    return false;
}

collision_t *is_trigger(engine_t *engine, object_t *object)
{
    node_t *travel = object->collision.collisions->head;
    collision_t *collision = NULL;

    for (int i = 0; i < object->collision.collisions->nb_elements; i++) {
        collision = travel->value;
        if (compare_trigger_engine(engine, object, collision))
            return true;
        travel = travel->next;
    }
    return false;
}