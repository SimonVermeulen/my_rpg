/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** parameter_volume
*/

#include "game.h"

static int enable_addon(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("parameter_volume", object);
    float *number = get_value_list(list, "number", 2);
    data_t *data = get_data_addon(engine);
    float *volume = get_value_list(data->data, "volume", 2);

    if (!number || !volume)
        return exit_game(engine, 84);
    *volume = *number;
}

static void *init_addon(list_t *list)
{
    return copy_list(list);
}

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "parameter_volume");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

int init_parameter_volume_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = enable_addon;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = enable_addon;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("parameter_volume", addon, engine) == sfFalse)
        return 84;
    return 0;
}
