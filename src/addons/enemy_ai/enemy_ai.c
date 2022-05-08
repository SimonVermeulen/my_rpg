/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** enemi_ai.c
*/

#include "game.h"

void coroutine_attack_event(grid_controller_t *controller);
int attack_ai(grid_controller_t *controller, object_t *enemy,
    engine_t *engine);
int tick_enemy_ai(object_t *object, engine_t *engine);

static int start_addon(object_t *object, engine_t *engine)
{
    grid_controller_t *controller = get_addon_data("enemy_ai", object);

    controller->object = object;
    controller->move_point = get_position(object);
    controller->coroutine = sfThread_create(coroutine_attack_event,
        controller);
    if (!controller->coroutine)
        return exit_game(engine, 84);
}

static void *init_addon(list_t *list)
{
    grid_controller_t *controller = malloc(sizeof(grid_controller_t));

    if (!controller)
        return NULL;
    controller->list = NULL;
    controller->object = NULL;
    controller->move_point = (sfVector2f) {0, 0};
    controller->time = 0;
    controller->is_attack = false;
    controller->coroutine = NULL;
    return controller;
}

static int end_addon(object_t *object, engine_t *engine)
{
    grid_controller_t *controller = get_addon_data("second_ai", object);

    if (!controller->coroutine)
        return 0;
    sfThread_terminate(controller->coroutine);
    sfThread_destroy(controller->coroutine);
    return 0;
}

int init_enemy_ai_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_addon;
    addon->on_event = NULL;
    addon->on_tick = tick_enemy_ai;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("enemy_ai", addon, engine) == sfFalse)
        return 84;
    return 0;
}
