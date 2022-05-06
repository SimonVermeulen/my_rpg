/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** second_ai.c
*/

#include "game.h"
#include <math.h>

int second_ai_follow_main(object_t *second, grid_controller_t *controller);
int second_ai_attack_enemy(object_t *second, grid_controller_t *controller,
    object_t *direction);

static int tick_addon(object_t *object, engine_t *engine)
{
    object_t *second = seach_object(engine, "second_pokemon");
    grid_controller_t *controller = get_addon_data("second_ai", object);
    list_t *enemy = NULL;
    collision_t *collision = NULL;
    
    if (!second || !controller)
        return exit_game(engine, 84);
    enemy = is_trigger(engine, second);
    collision = get_value_list(enemy, "enemy", 4);
    destroy_addons(enemy, true);
    if (collision)
        return second_ai_attack_enemy(second, controller, collision->object);
    second_ai_follow_main(second, controller);
}

static int start_addon(object_t *object, engine_t *engine)
{
    object_t *second = seach_object(engine, "second_pokemon");
    grid_controller_t *controller = get_addon_data("second_ai", object);

    controller->move_point = get_position(second);
}

static void *init_addon(list_t *list)
{
    grid_controller_t *controller = malloc(sizeof(grid_controller_t));

    if (!controller)
        return NULL;
    controller->list = NULL;
    controller->object = NULL;
    controller->move_point = (sfVector2f) {0, 0};
    return controller;
}

int init_second_ai_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_addon;
    addon->on_event = NULL;
    addon->on_tick = tick_addon;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("second_ai", addon, engine) == sfFalse)
        return 84;
    return 0;
}