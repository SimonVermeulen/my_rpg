/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** if_collision
*/

#include "game_engine.h"

bool check_collision_object(object_t *a, collision_t *b)
{
    node_t *node_a = NULL;

    node_a = a->collision.collisions->head;
    for (int i = 0; i < a->collision.collisions->nb_elements; i++) {
        if (get_collision(node_a->value, b))
            return true;
        node_a = node_a->next;
    }
    return false;
}

bool if_collision(object_t *object_a, object_t *object_b)
{
    node_t *node_a = NULL;

    if (!object_a || !object_b || !object_a->collision.collisions ||
        !object_b->collision.collisions)
        return false;
    node_a = object_a->collision.collisions->head;
    for (int i = 0; i < object_a->collision.collisions->nb_elements; i++) {
        if (check_collision_object(object_b, node_a->value))
            return true;
        node_a = node_a->next;
    }
    return false;
}