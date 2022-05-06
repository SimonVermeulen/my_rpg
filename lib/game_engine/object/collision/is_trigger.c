/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** is_trigger.c
*/

#include "game_engine.h"

collision_t *compare_trigger(list_t *scene, object_t *main,
    collision_t *collision, list_t *collisions);

collision_t *compare_inside_trigger(object_t *object, collision_t *collision,
    object_t *main, list_t *collisions)
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
            create_add_node(second, 4, object->name, collisions);
        travel = travel->next;
    }
    if (object->childs)
        compare_trigger(object->childs, main, collision, collisions);
    return NULL;
}

collision_t *compare_trigger(list_t *scene, object_t *main,
    collision_t *collision, list_t *collisions)
{
    node_t *travel = NULL;

    travel = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, travel = travel->next) {
        compare_inside_trigger(travel->value, collision, main, collisions);
    }
    return NULL;
}

collision_t *compare_trigger_engine(engine_t *engine, object_t *object,
    collision_t *collision, list_t *collisions)
{
    if (!object->is_active)
        return NULL;
    if (engine->actual_scene) {
        compare_trigger(engine->actual_scene->object, object,
            collision, collisions);
    }
    if (engine->const_scene) {
        compare_trigger(engine->const_scene->object, object,
            collision, collisions);
    }
    return NULL;
}

list_t *is_trigger(engine_t *engine, object_t *object)
{
    node_t *travel = object->collision.collisions->head;
    collision_t *collision = NULL;
    list_t *collisions = create_empty_list();

    for (int i = 0; i < object->collision.collisions->nb_elements; i++) {
        collision = travel->value;
        compare_trigger_engine(engine, object, collision, collisions);
        travel = travel->next;
    }
    return collisions;
}