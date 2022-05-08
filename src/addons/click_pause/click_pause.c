/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** click_pause
*/

#include "game.h"

static int event_addon(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("click_pause", object);
    static double time = 0;

    time += (time < 50) ? get_delta(engine) : 0;
    if (time < 50)
        return 0;
    if (if_key_pressed(engine, sfKeyEscape)) {
        set_active(true, seach_object(engine, get_value_list(list, "enable",
            4)), engine);
        time = 0;
    }
    return 0;
}

static void *init_addon(list_t *list)
{
    return copy_list(list);
}

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "click_pause");
    if (node == NULL)
        return 0;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

int init_click_pause_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = NULL;
    addon->on_event = event_addon;
    addon->on_tick = NULL;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("click_pause", addon, engine) == sfFalse)
        return 84;
    return 0;
}