/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rect_action
*/

#include "game.h"

int set_rect_with_list(object_t *object, list_t *list, int *start,
    double *count)
{
    int *left = get_value_list(list, "left", 3);
    int *top = get_value_list(list, "top", 3);
    int *width = get_value_list(list, "width", 3);
    int *height = get_value_list(list, "height", 3);

    if (!object || !left || !top || !width || !height)
        return 0;
    set_texture_rect(object, (sfIntRect) {*left, *top, *width, *height});
    *start += 1;
    *count = 0;
    return 0;
}

static int check_rect(object_t *object, engine_t *engine, list_t *rect)
{
    list_t **rects = get_value_list(rect, "rects", 10);
    int length = search_from_key(rect, "rects")->len;
    int *start = get_value_list(rect, "start", 3);
    int *infini = get_value_list(rect, "infini", 3);
    double *start_time = get_value_list(rect, "start-time", 2);
    double *stop_time = get_value_list(rect, "stop-time", 2);
    double *wait = get_value_list(rect, "waitBeforeStart", 2);
    double *count = get_value_list(rect, "count", 2);
    char *enable = get_value_list(rect, "enable", 4);

    *count += get_delta(engine);
    *start_time += get_delta(engine);
    if ((*start == length && *infini == 0)
        || (*start_time >= *stop_time && *stop_time > 0)) {
        set_active(true, seek_object_scene(object->actual_scene, enable),
            engine);
        return true;
    }
    return false;
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
    double *wait = get_value_list(rect, "waitBeforeStart", 2);
    object_t *objecta = get_value_list(rect, "object", 4);

    if (!time)
        return exit_game(engine, 84);
    if (check_rect(object, engine, rect) || *count < *time ||
        *start_time <= *wait)
        return 0;
    return (set_rect_with_list(objecta, rects[*start % length], start, count));
}
