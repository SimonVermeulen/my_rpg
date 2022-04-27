/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event_controller
*/

#include "game.h"

bool is_click_event(engine_t *engine, object_t *object, void *event);
bool is_hover_event(engine_t *engine, object_t *object, void *event);
bool is_trigger_event(engine_t *engine, object_t *object, void *event);

static bool (*const event_func[])(engine_t *, object_t *, void *) =
{
    is_click_event,
    NULL,
    is_hover_event,
    is_trigger_event
};

static int execute_event(object_t *object, engine_t *engine, list_t *data,
    event_manager_t *event)
{
    object_t *object_info = seach_object(engine,
        get_value_list(data, "object", 4));
    int *type = get_value_list(data, "type", 3);
    double *value = get_value_list(data, "value", 2);
    object_t *object_enable = seach_object(engine,
        get_value_list(data, "object_enable", 4));
    int *disable = get_value_list(data, "disable", 3);

    if (!type || !value || !disable)
        return exit_game(engine, 84);
    if (!object_info)
        object_info = object;
    if (event_func[*type % 4] &&
        (*event_func[*type % 4])(engine, object_info, value)) {
        event->count++;
        set_active(true, object_enable, engine);
        if (*disable)
            set_active(false, object, engine);
    }
}

int event_event_manager(object_t *object, engine_t *engine)
{
    event_manager_t *event_manager = get_addon_data("event_manager", object);

    if (event_manager->count >= event_manager->length)
        return 0;
    execute_event(object, engine, event_manager->actions[event_manager->count %
        event_manager->length], event_manager);
}