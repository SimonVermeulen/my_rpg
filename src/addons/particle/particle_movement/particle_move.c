/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** particle_move
*/

#include "game.h"

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "particle_move");
    if (node == NULL)
        return 0;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

static int delete_object(object_t *object, engine_t *engine)
{
    return destroy_object(object);
}

static int tick_addon(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("particle_move", object);
    int *var = get_value_list(list, "variation", 3);
    double *time = get_value_list(list, "time", 2);
    double *count = get_value_list(list, "count", 2);
    double *speed = get_value_list(list, "speed", 2);
    sfVector2f path = create_vector2f_list(get_value_list(list, "path", 1));
    sfVector2f normal;

    if (!var || !time || !count)
        return exit_game(engine, 84);
    *count += get_delta(engine);
    if (*time < *count)
        return add_function(delete_object, 0, object, engine);
    path.x += get_position(object).x;
    path.y += get_position(object).y;
    path.x += rand() % *var * ((rand() % 2 == 1) ? -1 : 1);
    path.y += rand() % *var * ((rand() % 2 == 1) ? -1 : 1);
    normal = get_normalize_vector(get_position(object), path);
    normal.x *= get_delta(engine) / 100 * *speed;
    normal.y *= get_delta(engine) / 100 * *speed;
    move_vector(object, normal);
}

static void *init_addon(list_t *list)
{
    return copy_list(list);
}

int init_particle_move_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_addon;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("particle_move", addon, engine) == sfFalse)
        return 84;
    return 0;
}
