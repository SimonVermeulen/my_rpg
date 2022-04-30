/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_controller
*/

#include "game.h"

static int event_player_controller(object_t *object, engine_t *engine)
{
    player_contoller_t *controller = get_addon_data("player_controller",
        object);

    if (if_key_pressed(engine, sfKeyUp))
        *controller = (player_contoller_t) {true, (sfVector2f) {0, 1}};
    if (if_key_pressed(engine, sfKeyDown))
        *controller = (player_contoller_t) {true, (sfVector2f) {0, -1}};
    if (if_key_pressed(engine, sfKeyLeft))
        *controller = (player_contoller_t) {true, (sfVector2f) {-1, 0}};
    if (if_key_pressed(engine, sfKeyRight))
        *controller = (player_contoller_t) {true, (sfVector2f) {1, 0}};
    // if (if_key_released(engine, sfKeyUp) || if_key_released(engine, sfKeyDown)
    //     || if_key_released(engine, sfKeyLeft) ||
    //     if_key_released(engine, sfKeyRight))
    //     *controller = (player_contoller_t) {false, (sfVector2f) {0, 0}};
}

static int tick_player_controller(object_t *object, engine_t *engine)
{
    player_contoller_t *controller = get_addon_data("player_controller",
        object);
    object_t *main = seach_object(engine, "main_pokemon");
    object_t *second = seach_object(engine, "second_pokemon");
    sfVector2f normal;

    if (!main || !second)
        return 0;
    controller->direction.x *= (get_delta(engine) / 100) * 5;
    controller->direction.y *= (get_delta(engine) / 100) * 5;
    if (controller->is_moving)
        move_vector(main, controller->direction);
    controller->is_moving = false;
    normal = get_normalize_vector(get_position(second), get_position(main));
    normal.x *= (get_delta(engine) / 100) * 5;
    normal.y *= (get_delta(engine) / 100) * 5;
    move_vector(second, normal);
}

static void *init_addon(list_t *list)
{
    player_contoller_t *player_controller = malloc(sizeof(player_contoller_t));

    player_controller->is_moving = false;
    player_controller->direction = (sfVector2f) {0, 0};
    return player_controller;
}

int init_player_controller_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = event_player_controller;
    addon->on_tick = tick_player_controller;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("player_controller", addon, engine) == sfFalse)
        return 84;
    return 0;
}