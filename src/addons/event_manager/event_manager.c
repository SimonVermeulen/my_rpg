/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_manager
*/

#include "game.h"

int tick_event_manager(object_t *object, engine_t *engine);
int event_event_manager(object_t *object, engine_t *engine);

static void *init_addon(list_t *list)
{
    node_t *actions_node = search_from_key(list, "actions");
    event_manager_t *event_manager = NULL;
    list_t *copy = NULL;

    if (!actions_node || actions_node->type != 10)
        return NULL;
    event_manager = malloc(sizeof(event_manager_t));
    copy = copy_list(list);
    if (!event_manager || !copy)
        return NULL;
    event_manager->data = copy;
    event_manager->actions = search_from_key(copy, "actions")->value;
    event_manager->count = 0;
    event_manager->length = actions_node->len;
    return event_manager;
}

static int end_addon(object_t *object, engine_t *engine)
{
    event_manager_t *event = get_addon_data("event_manager", object);

    free_json_object(event->data);
    return 0;
}

int init_event_manager_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = NULL;
    addon->on_event = event_event_manager;
    addon->on_tick = tick_event_manager;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("event_manager", addon, engine) == sfFalse)
        return 84;
    return 0;
}