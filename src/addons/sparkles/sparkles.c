/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-adil.nouiri
** File description:
** sparkles
*/

#include "game.h"

int tick_sparkles(object_t *object, engine_t *engine)
{
    sparkles_t *sparkles = get_addon_data("sparkles", object);

    if ((int)(get_delta(engine) / 100) % 2 == 0)
        sparkles->order = -1;
    else
        sparkles->order = 0;
    return 0;
}

int start_sparkles(object_t *object, engine_t *engine)
{
    sparkles_t *sparkles = get_addon_data("sparkles", object);

    return 0;
}

void *init_sparkles(list_t *list)
{
    int *order = get_value_list(list, "order", 3);
    sparkles_t *sparkles = NULL;

    if (!order)
        return NULL;
    sparkles = malloc(sizeof(sparkles_t));
    if (!sparkles)
        return NULL;
    sparkles->order = *order;
    return sparkles;
}

int init_sparkles_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_sparkles;
    addon->on_event = NULL;
    addon->on_tick = tick_sparkles;
    addon->init = init_sparkles;
    addon->on_collision = NULL;
    if (create_addon("sparkles", addon, engine) == sfFalse)
        return 84;
    return 0;
}
