/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** rect_animation.c
*/

#include "game_engine.h"

int set_rect_with_list(object_t *object, list_t *list, int *start,
    double *count)
{
    int *left = get_value_list(list, "left", 3);
    int *top = get_value_list(list, "top", 3);
    int *width = get_value_list(list, "width", 3);
    int *height = get_value_list(list, "height", 3);

    if (!left || !top || !width || !height)
        return 0;
    set_texture_rect(object, (sfIntRect) {*left, *top, *width, *height});
    *start += 1;
    *count = 0;
    return 0;
}

int tick_rect_animation(object_t *object, engine_t *engine)
{
    list_t *rect = get_addon_data("rect_animation", object);
    list_t **rects = get_value_list(rect, "rects", 10);
    int length = search_from_key(rect, "rects")->len;
    int *start = get_value_list(rect, "start", 3);
    int *infini = get_value_list(rect, "infini", 3);
    double *count = get_value_list(rect, "count", 2);
    double *time = get_value_list(rects[*start % length], "time", 2);
    double *start_time = get_value_list(rect, "start-time", 2);
    double *stop_time = get_value_list(rect, "stop-time", 2);

    if (!time)
        return exit_game(engine, 84);
    *count += get_delta(engine);
    *start_time += get_delta(engine);
    if (*count < *time || (*start == length && *infini == 0)
        || (*start_time >= *stop_time && *stop_time > 0))
        return 0;
    set_rect_with_list(object, rects[*start % length], start, count);
    return 0;
}

int end_rect_animation(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "rect_animation");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

void *init_rect_animation(list_t *list)
{
    int *infini = get_value_list(list, "infini", 3);
    int *start = get_value_list(list, "start", 3);
    double *count = get_value_list(list, "count", 2);
    list_t **rects = get_value_list(list, "rects", 10);
    double *start_time = get_value_list(list, "start-time", 2);
    double *stop_time = get_value_list(list, "stop-time", 2);

    if (!infini || !start || !rects || !count || !start_time || !stop_time)
        return NULL;
    return copy_list(list);
}

int init_rect_animation_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_rect_animation;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_rect_animation;
    addon->init = init_rect_animation;
    addon->on_collision = NULL;
    if (create_addon("rect_animation", addon, engine) == sfFalse)
        return 84;
    return 0;
}
