/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_manager
*/

#include "game.h"

bool is_click_event(engine_t *engine, object_t *object, void *event);
bool is_time_event(engine_t *engine, object_t *object, void *event);
bool is_hover_event(engine_t *engine, object_t *object, void *event);
bool is_trigger_event(engine_t *engine, object_t *object, void *event);

bool (*const event_func[])(engine_t *, object_t *, void *) =
{
    is_click_event,
    is_time_event,
    is_hover_event,
    is_trigger_event
};

static int execute_event(object_t *object, engine_t *engine, list_t *data,
    event_manager_t *event)
{
    object_t *object_info = seach_object(engine,
        get_value_list(data, "object", 4));
    int *type = get_value_list(data, "type", 3);
    int *value = get_value_list(data, "value", 3);
    object_t *object_enable = seach_object(engine,
        get_value_list(data, "object_enable", 4));
    int *disable = get_value_list(data, "disable", 3);

    if (!type || !value || !disable)
        return exit_game(engine, 84);
    if (!object_info)
        object_info = object;
    if ((*event_func[*type % 4])(engine, object_info, value)) {
        event->count++;
        set_active(true, object_enable, engine);
        if (*disable)
            set_active(false, object, engine);
    }
}

static int event_addon(object_t *object, engine_t *engine)
{
    event_manager_t *event_manager = get_addon_data("event_manager", object);

    if (event_manager->count >= event_manager->length)
        return 0;
    execute_event(object, engine, event_manager->actions[event_manager->count %
        event_manager->length], event_manager);
}

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
    free(event);
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
    addon->on_event = event_addon;
    addon->on_tick = NULL;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("event_manager", addon, engine) == sfFalse)
        return 84;
    return 0;
}