/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_position
*/

#include "game.h"

int start_set_position(object_t *object, engine_t *engine)
{
    sfVector2f *vector = get_addon_data("set_position", object);

    set_position_vector(object, *vector);
    return 0;
}

int init_set_position(list_t *list)
{
    double *x = get_value_list(list, "x", 2);
    double *y = get_value_list(list, "y", 2);
    sfVector2f *vector = NULL;

    if (!x || !y)
        return NULL;
    vector = malloc(sizeof(sfVector2f));
    if (!vector)
        return NULL;
    vector->x = *x;
    vector->y = *y;
    return vector;
}

int init_set_position_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_set_position;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = init_set_position;
    addon->on_collision = NULL;
    if (create_addon("set_position", addon, engine) == sfFalse)
        return 84;
    return 0;
}