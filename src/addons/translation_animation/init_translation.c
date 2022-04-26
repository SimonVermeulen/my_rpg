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
        node = create_add_node(position, 4, "path", positions_final);
        if (!node)
            return NULL;
    }
    return positions_final;
}

static int write_data(translation_animation_t *translation, list_t *list)
{
    double *wait = get_value_list(list, "waitBeforeStart", 2);
    int *infini = get_value_list(list, "infini", 3);
    int *reverse = get_value_list(list, "reverse", 3);
    int *spawn = get_value_list(list, "spawn", 3);

    if (!wait || !infini || !reverse)
        return false;
    translation->infini = *infini;
    translation->reverse = *reverse;
    translation->step = (spawn) ? *spawn : 0;
    translation->count_wait = 0;
    translation->wait = *wait;
    translation->is_reverse = 0;
    translation->object = NULL;
    translation->name = get_value_list(list, "name", 4);
    translation->name_enable = get_value_list(list, "name_enable", 4);
    return true;
}

void *init_translation_animation(list_t *list)
{
    node_t *positions = search_from_key(list, "paths");
    translation_animation_t *translation = NULL;

    if (!positions || positions->type != 10)
        return NULL;
    translation = malloc(sizeof(translation_animation_t));
    if (!translation || !write_data(translation, list))
        return NULL;
    translation->positions = create_list_positions(positions->value,
        positions->len);
    if (!translation->positions || translation->positions->nb_elements == 0)
        return NULL;
    return translation;
}