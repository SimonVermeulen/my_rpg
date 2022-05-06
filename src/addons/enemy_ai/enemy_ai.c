/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** enemi_ai.c
*/

#include "game.h"

static sfVector2f get_next_position(object_t *object, engine_t *engine)
{
    object_t *main = seach_object(engine, "main_pokemon");
    object_t *cont = seach_object(engine, "controller");
    grid_controller_t *controller = get_addon_data("grid_controller", cont);
    sfVector2f normal = get_normalize_vector(get_position(object),
        get_position(main));
    
    if (!controller)
        return get_position(object);
    normal.x = round(normal.x);
    normal.y = round(normal.y);
    normal.x *= 75;
    normal.y *= 75;
    normal.x += get_position(object).x;
    normal.y += get_position(object).y;
    if (equal_vector2f(controller->move_point, normal) ||
        !if_collision(object, main))
        return get_position(object);
    return normal;
}

static int tick_addon(object_t *object, engine_t *engine)
{
    grid_controller_t *controller = get_addon_data("enemy_ai", object);
    sfVector2f normal = get_normalize_vector(get_position(object),
        controller->move_point);
    
    normal.x *= 15 * (get_delta(engine) / 100);
    normal.y *= 15 * (get_delta(engine) / 100);
    move_vector(object, normal);
    if (equal_vector2f_pov(get_position(object),
        controller->move_point, 1)) {
        set_position_vector(object, controller->move_point);
        controller->move_point = get_next_position(object, engine);
    }
}

static int start_addon(object_t *object, engine_t *engine)
{
    grid_controller_t *controller = get_addon_data("enemy_ai", object);

    controller->move_point = get_position(object);
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
    addon->on_tick = tick_addon;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("enemy_ai", addon, engine) == sfFalse)
        return 84;
    return 0;
}