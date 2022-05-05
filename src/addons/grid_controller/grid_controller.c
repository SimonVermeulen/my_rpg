/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** grid_controller.c
*/

#include "game.h"

int event_grid_controller(object_t *object, engine_t *engine);

int tick_grid_controller(object_t *object, engine_t *engine);

static int start_addon(object_t *object, engine_t *engine)
{
    grid_controller_t *controller = get_addon_data("grid_controller", object);

    controller->object = seach_object(engine, get_value_list(controller->list,
        "object", 4));
    if (!controller->object)
        return exit_game(engine, 84);
    controller->move_point = get_position(controller->object);
}

static void *init_addon(list_t *list)
{
    grid_controller_t *controller = malloc(sizeof(grid_controller_t));

    if (!controller)
        return NULL;
    controller->list = copy_list(list);
    if (!controller->list)
        return NULL;
    controller->object = NULL;
    controller->move_point = (sfVector2f) {0, 0};
    return controller;
}

static int end_addon(object_t *object, engine_t *engine)
{
    grid_controller_t *controller = get_addon_data("grid_controller", object);

    free_json_object(controller->list);
    return 0;
}

int init_grid_controller_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = start_addon;
    addon->on_event = event_grid_controller;
    addon->on_tick = tick_grid_controller;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("grid_controller", addon, engine) == sfFalse)
        return 84;
    return 0;
}