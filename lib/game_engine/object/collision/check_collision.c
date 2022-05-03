/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** check_collision.c
*/

#include "game_engine.h"

int execute_collision_event(collision_t *a, collision_t *b, object_t *object)
{
    node_t *travel = object->addons->head;
    addon_t *addon = NULL;

    for (int i = 0; i < object->addons->nb_elements; i++) {
        addon = travel->value;
        if (addon->on_collision)
            addon->on_collision(a, b, object->engine);
        travel = travel->next;
    }
    return 0;
}

bool fix_collision(collision_t *a, collision_t *b, object_t *object)
{
    sfVector2f normal_a;
    sfVector2f normal_b;

    if (get_collision(a, b) && !a->trigger && !b->trigger
        && a->object != b->object) {
        execute_collision_event(a, b, object);
        normal_a = get_normalize_vector(get_position(object),
        object->collision.last_position);
        normal_b = normal_a;
        for (int i = 0; equal_vector2f_pov(normal_a, normal_b, 0.01) &&
            get_collision(a, b); i++) {
            move_vector(object, normal_b);
            normal_b = get_normalize_vector(get_position(object),
                object->collision.last_position);
        }
    }
    return false;
}

bool compare_collisions(list_t *scene, object_t *main,
    collision_t *collision)
{
    node_t *travel_a = NULL;
    node_t *travel_b = NULL;
    object_t *object = NULL;

    travel_a = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, travel_a = travel_a->next) {
        object = travel_a->value;
        if (!object->is_active)
            continue;
        travel_b = object->collision.collisions->head;
        for (int i = 0; i < object->collision.collisions->nb_elements; i++) {
            fix_collision(collision, travel_b->value, main);
            travel_b = travel_b->next;
        }
        if (object->childs)
            compare_collisions(object->childs, main, collision);
    }
    return true;
}

bool compare_collisions_engine(engine_t *engine, object_t *object,
    collision_t *collision)
{
    if (!object->is_active)
        return false;
    if (engine->actual_scene)
        compare_collisions(engine->actual_scene->object, object, collision);
    if (engine->const_scene)
        compare_collisions(engine->const_scene->object, object, collision);
    return false;
}

bool check_collision_event(engine_t *engine, list_t *scene)
{
    node_t *travel_a = NULL;
    node_t *travel_b = NULL;
    object_t *object = NULL;

    travel_a = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, travel_a = travel_a->next) {
        object = travel_a->value;
        if (equal_vector2f(object->collision.last_position,
            get_position(object)))
            continue;
        travel_b = object->collision.collisions->head;
        for (int i = 0; i < object->collision.collisions->nb_elements; i++,
            travel_b = travel_b->next)
            compare_collisions_engine(engine, object, travel_b->value);
        object->collision.last_position = get_position(object);
        if (object->childs)
            check_collision_event(engine, object->childs);
    }
    return false;
}