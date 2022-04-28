/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** tick
*/

#include "game.h"

static int get_type_2(object_t *object, engine_t *engine, dialogue_t *event)
{
    int *type = NULL;

    if (event->count >= event->length)
        return 0;
    type = get_value_list(event->texts[event->count], "type", 3);
    if (*type == 3 && event->wait <= 0) {
        event->active = true;
        event->count++;
    }
    return 0;
}

int tick_dialogue_manager(object_t *object, engine_t *engine)
{
    dialogue_t *event = get_addon_data("dialogue_manager", object);
    double *wait = NULL;

    event->wait -= (event->wait > 0) ? get_delta(engine) : 0;
    get_type_2(object, engine, event);
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