/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** dialogue_manager
*/

#include "game.h"

int event_dialogue_manager(object_t *object, engine_t *engine)
{
    dialogue_t *event = get_addon_data("dialogue_manager", object);
    int *type = NULL;

    if (event->count >= event->length || event->wait > 0)
        return 0;
    type = get_value_list(event->texts[event->count], "type", 3);
    if (type && *type == 1 && if_key_pressed(engine, sfKeyA)) {
        set_active(false, seek_object_scene(object->actual_scene,
            get_value_list(event->texts[event->count], "enable", 4)), engine);
        event->count++;
        event->active = false;
        if (event->count < event->length)
            set_active(true, seek_object_scene(object->actual_scene,
            get_value_list(event->texts[event->count], "enable", 4)), engine);
    }
    return 0;
}

int tick_dialogue_manager(object_t *object, engine_t *engine)
{
    dialogue_t *event = get_addon_data("dialogue_manager", object);
    double *wait = NULL;

    event->wait -= (event->wait > 0) ? get_delta(engine) : 0;
    if (event->active || event->count >= event->length) {
        if (event->count == event->length) {
            set_active(true,
            seek_object_scene(object->actual_scene, event->enable), engine);
            set_active(!event->disable, object, engine);
            event->count = 0;
        }
        return 0;
    }
    wait = get_value_list(event->texts[event->count], "wait", 2);
    event->wait = (wait) ? *wait : 0;
    set_active(true, seek_object_scene(object->actual_scene,
        get_value_list(event->texts[event->count], "enable", 4)), engine);
    event->active = true;
    return 0;
}

static int end_addon(object_t *object, engine_t *engine)
{
    dialogue_t *event = get_addon_data("dialogue_manager", object);

    free_json_object(event->data);
    return 0;
}

static void *init_addon(list_t *list)
{
    node_t *actions_node = search_from_key(list, "actions");
    dialogue_t *dialogue = NULL;
    list_t *copy = NULL;

    if (!actions_node || actions_node->type != 10)
        return NULL;
    dialogue = malloc(sizeof(dialogue_t));
    copy = copy_list(list);
    if (!dialogue || !copy)
        return NULL;
    dialogue->data = copy;
    dialogue->texts = search_from_key(copy, "actions")->value;
    dialogue->count = 0;
    dialogue->wait = 0;
    dialogue->active = false;
    dialogue->length = actions_node->len;
    dialogue->enable = get_value_list(copy, "enable", 4);
    dialogue->disable = (get_value_list(copy, "disable", 3)) ? 1 : 0;
    return dialogue;
}

int init_dialogue_manager_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = NULL;
    addon->on_event = event_dialogue_manager;
    addon->on_tick = tick_dialogue_manager;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("dialogue_manager", addon, engine) == sfFalse)
        return 84;
    return 0;
}