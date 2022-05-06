/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_controller
*/

#include "game.h"

int event_player_controller(object_t *object, engine_t *engine);

static int tick_player_controller(object_t *object, engine_t *engine)
{
    player_contoller_t *controller = get_addon_data("player_controller",
        object);
    object_t *main = seach_object(engine, "main_pokemon");
    object_t *second = seach_object(engine, "second_pokemon");
    sfVector2f normal;
    list_t *list = NULL;

    if (!main || !second)
        return 0;
    normal.x = controller->direction.x * engine->time.delta / 100 * 10;
    normal.y = controller->direction.y * engine->time.delta / 100 * 10;
    move_vector(main, normal);
    list = is_trigger(engine, main);
    if (get_value_list(list, "second_pokemon", 4))
        return destroy_addons(list, true);
    normal = get_normalize_vector(get_position(second), get_position(main));
    normal.x *= engine->time.delta / 100 * 10;
    normal.y *= engine->time.delta / 100 * 10;
    move_vector(second, normal);
    destroy_addons(list, true);
}

static int end_addon(object_t *object, engine_t *engine)
{
    player_contoller_t *controller = get_addon_data("player_controller",
        object);

    free_json_object(controller->list);
}

static void *init_addon(list_t *list)
{
    player_contoller_t *player_controller = malloc(sizeof(player_contoller_t));

    player_controller->direction = (sfVector2f) {0, 0};
    player_controller->list = copy_list(list);
    if (!player_controller->list)
        return NULL;
    player_controller->last = NULL;
    return player_controller;
}

int init_player_controller_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = NULL;
    addon->on_event = event_player_controller;
    addon->on_tick = tick_player_controller;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("player_controller", addon, engine) == sfFalse)
        return 84;
    return 0;
}