/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** addon.c
*/

#include "game.h"

int tick_example(object_t *object, engine_t *engine)
{
    example_t *example = get_addon_data("example", object);
    collision_t *collision = is_trigger(engine, object);

    if (!example)
        return exit_game(engine, 84);
    if (collision)
        printf("bonjours\n");
}

int event_example(object_t *object, engine_t *engine)
{
    if (if_key_pressed(engine, sfKeyUp))
        move_float(object, 0, 5);
    if (if_key_pressed(engine, sfKeyDown))
        move_float(object, 0, -5);
    if (if_key_pressed(engine, sfKeyLeft))
        move_float(object, -5, 0);
    if (if_key_pressed(engine, sfKeyRight))
        move_float(object, 5, 0);
}

void *init_example(list_t *list)
{
    example_t *example = NULL;
    int *data = get_value_list(list, "data", 3);
    
    if (!data)
        return NULL;
    example = malloc(sizeof(example_t));
    if (!example)
        return NULL;
    example->data = *data;
    return example;
}

int init_example_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = event_example;
    addon->on_tick = tick_example;
    addon->init = init_example;
    addon->on_collision = NULL;
    if (create_addon("example", addon, engine) == sfFalse)
        return 84;
    return 0;
}