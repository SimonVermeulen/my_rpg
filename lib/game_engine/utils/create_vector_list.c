/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** create_vector2f_list.c
*/

#include "game_engine.h"

sfVector2f *malloc_vector2f_list(list_t *list)
{
    sfVector2f *position = NULL;
    double *x = get_value_list(list, "x", 2);
    double *y = get_value_list(list, "y", 2);

    if (!x || !y)
        return NULL;
    position = malloc(sizeof(sfVector2f));
    if (!position)
        return NULL;
    position->x = *x;
    position->y = *y;
    return position;
}

sfVector2i *malloc_vector2i_list(list_t *list)
{
    sfVector2i *position = NULL;
    int *x = get_value_list(list, "x", 3);
    int *y = get_value_list(list, "y", 3);

    if (!x || !y)
        return NULL;
    position = malloc(sizeof(sfVector2i));
    if (!position)
        return NULL;
    position->x = *x;
    position->y = *y;
    return position;
}

sfVector2f create_vector2f_list(list_t *list)
{
    double *x = get_value_list(list, "x", 2);
    double *y = get_value_list(list, "y", 2);

    if (!x || !y)
        return (sfVector2f) {0, 0};
    return (sfVector2f) {*x, *y};
}

sfVector2i create_vector2i_list(list_t *list)
{
    int *x = get_value_list(list, "x", 3);
    int *y = get_value_list(list, "y", 3);

    if (!x || !y)
        return (sfVector2i) {0, 0};
    return (sfVector2i) {*x, *y};
}
