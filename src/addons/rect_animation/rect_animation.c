/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** rect_animation.c
*/

#include "game_engine.h"

int tick_rect_animation(object_t *object, engine_t *engine);

int end_rect_animation(object_t *object, engine_t *engine)
{
    node_t *node = NULL;
    node_t *objecta = NULL;

    node = search_from_key(object->addons_data, "rect_animation");
    if (node == NULL)
        return 0;
    objecta = search_from_key(node->value, "object");
    if (objecta)
        objecta->value = NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

void *init_rect_animation(list_t *list)
{
    double *wait = get_value_list(list, "waitBeforeStart", 2);
    int *infini = get_value_list(list, "infini", 3);
    int *start = get_value_list(list, "start", 3);
    double *count = get_value_list(list, "count", 2);
    list_t **rects = get_value_list(list, "rects", 10);
    double *stop_time = get_value_list(list, "stop-time", 2);

    if (!infini || !start || !rects || !count || !stop_time || !wait)
        return NULL;
    return copy_list(list);
}

static int start_addon(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("rect_animation", object);
    char *name = get_value_list(list, "object_name", 4);
    object_t *object_ta = seek_object_scene(object->actual_scene, name);
    node_t *text = search_from_key(list, "object");

    if (!object_ta)
        object_ta = object;
    if (text || !create_add_node(object_ta, 4, "object", list))
        return exit_game(engine, 84);
    return 0;
}

int init_rect_animation_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = start_addon;
    addon->on_disable = NULL;
    addon->on_end = end_rect_animation;
    addon->on_start = start_addon;
    addon->on_event = NULL;
    addon->on_tick = tick_rect_animation;
    addon->init = init_rect_animation;
    addon->on_collision = NULL;
    if (create_addon("rect_animation", addon, engine) == sfFalse)
        return 84;
    return 0;
}
