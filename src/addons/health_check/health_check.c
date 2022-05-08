/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** health_check.c
*/

#include "game.h"

static int tick_addons(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("health_check", object);
    data_t *data = get_data_addon(object->engine);
    double *life_a = get_value_list(data->data, "lifea", 2);
    double *life_b = get_value_list(data->data, "lifeb", 2);

    if (!life_a || !life_b)
        return exit_game(engine, 84);
    if (*life_a <= 0 || *life_b <= 0) {
        *life_a = 100;
        *life_b = 100;
        set_active(true, seach_object(engine,
            get_value_list(list, "enable", 4)), engine);
    }
}

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "health_check");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

static void *init_addons(list_t *list)
{
    return copy_list(list);
}

int init_health_check_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_addons;
    addon->init = init_addons;
    addon->on_collision = NULL;
    if (create_addon("health_check", addon, engine) == sfFalse)
        return 84;
    return 0;
}
