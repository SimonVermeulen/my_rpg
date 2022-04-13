/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_translation
*/

#include "game.h"

vector_speed_t *create_vector_speed(list_t *list)
{
    double *x = get_value_list(list, "x", 2);
    double *y = get_value_list(list, "y", 2);
    double *speed = get_value_list(list, "speed", 2);
    vector_speed_t *vector = NULL;

    if (!x || !y || !speed)
        return NULL;
    vector = malloc(sizeof(vector_speed_t));
    if (!vector)
        return NULL;
    vector->speed = *speed;
    vector->position.x = *x;
    vector->position.y = *y;
    return vector;
}

list_t *create_list_positions(list_t **positions, int length)
{
    vector_speed_t *position = NULL;
    list_t *positions_final = create_empty_list();
    node_t *node = NULL;

    if (!positions_final)
        return NULL;
    for (int i = 0; i < length; i++) {
        position = create_vector_speed(positions[i]);
        if (!position)
            return NULL;
        node = create_add_node(position, 0, "path", positions_final);
        if (!node)
            return NULL;
    }
    return positions_final;
}

void *init_translation_animation(list_t *list)
{
    double *wait = get_value_list(list, "waitBeforeStart", 2);
    int *infini = get_value_list(list, "infini", 3);
    int *reverse = get_value_list(list, "reverse", 3);
    node_t *positions = search_from_key(list, "paths");
    translation_animation_t *translation = NULL;

    if (!wait || !positions || positions->type != 10 || !infini || !reverse)
        return NULL;
    translation = malloc(sizeof(translation_animation_t));
    if (!translation)
        return NULL;
    translation->infini = *infini;
    translation->reverse = *reverse;
    translation->step = 0;
    translation->count_wait = 0;
    translation->wait = *wait;
    translation->normal = (sfVector2f) {0, 0};
    translation->is_reverse = 0;
    translation->positions = create_list_positions(positions->value,
        positions->len);
    if (!translation->positions)
        return NULL;
    return translation;
}