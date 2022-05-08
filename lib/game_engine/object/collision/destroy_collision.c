/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** fix_trajectory.c
*/

#include "game_engine.h"

bool destroy_collision(object_t *object)
{
    while (object->collision.collisions->nb_elements != 0) {
        shift_element(object->collision.collisions);
    }
    free(object->collision.collisions);
    return true;
}
