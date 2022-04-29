/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** multi_disable
*/

#include "game.h"

static int start_addon(object_t *object, engine_t *engine)
{
    multi_enable_t *multi = get_addon_data("multi_disable", object);
    object_t *item = NULL;

    for (int i = 0; i < multi->length; i++) {
        item = NULL;
        if (multi->all)
            item = seach_object(engine, multi->items[i]);
        if (!item)
            item = seek_object_scene(object->actual_scene, multi->items[i]);
        set_active(false, item, engine);
    }
    return 0;
}

static int end_addon(object_t *object, engine_t *engine)
{
    multi_enable_t *multi = get_addon_data("multi_disable", object);

    free_json_object(multi->data);
    return 0;
}

static void *init_addon(list_t *list)
{
    node_t *actions_node = search_from_key(list, "objects");
    multi_enable_t *multi = NULL;
    list_t *copy = NULL;

    if (!actions_node || actions_node->type != 40)
        return NULL;
    multi = malloc(sizeof(multi_enable_t));
    copy = copy_list(list);
    if (!multi || !copy)
        return NULL;
    multi->data = copy;
    multi->items = search_from_key(copy, "objects")->value;
    multi->length = actions_node->len;
    multi->all = (get_value_list(list, "all", 3)) ? true : false;
    return multi;
}

int init_multi_disable_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = start_addon;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = start_addon;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("multi_disable", addon, engine) == sfFalse)
        return 84;
    return 0;
}