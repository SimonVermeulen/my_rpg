/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-adil.nouiri
** File description:
** mobs_animation
*/

#include "game.h"

static sfIntRect set_default_rect(list_t *list, sfIntRect first_call)
{
    sfFloatRect bounds = get_local_bounds(list->head->prev->value);
    int *nb_frames = search_from_key(list, "nb_frames")->value;
    int *nb_lines = search_from_key(list, "nb_lines")->value;
    int *line = search_from_key(list, "line")->value;

    if (first_call.height != 0 || first_call.width != 0)
        return (first_call);
    first_call.height = (bounds.height / *nb_lines) / 2;
    first_call.width = bounds.width / *nb_frames;
    first_call.top = *line * first_call.height;
    set_texture_rect(list->head->prev->value, first_call);
    return (first_call);
}

static int tick_mobs_animation(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("mobs_animation", object);
    int *max_step = search_from_key(list, "nb_frames")->value;
    int *infini = search_from_key(list, "infini");
    static sfIntRect rect = {0, 0, 0, 0};
    static int step = 0;

    rect = set_default_rect(list, rect);
    if (step < *max_step) {
        rect.left += rect.width;
        set_texture_rect(list->head->prev->value, rect);
        step++;
    } else if (*infini != 0) {
        step = 0;
        rect.left = 0;
    }    
}

static int start_mobs_animation(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("mobs_animation", object);
    char *name = get_value_list(list, "object_value", 4);
    object_t *object_ta = seek_object_scene(object->actual_scene, name);
    node_t *check = search_from_key(list, "object_value");

    if (!object_ta)
        object_ta = object;
    if (check || !create_add_node(object_ta, 1, "object_value", list))
        return exit_game(engine, 84);
    return (0);
}

static void *init_mobs_animation(list_t *list)
{
    double *wait = get_value_list(list, "waitBeforeStart", 2);
    int *nb_frames = get_value_list(list, "nb_frames", 3);
    char *enable = get_value_list(list, "enable", 4);
    char *object = get_value_list(list, "object", 4);
    int *infini = get_value_list(list, "infini", 3);
    int *line = get_value_list(list, "line", 3);
    int *nb_lines = get_value_list(list, "nb_lines", 3);

    if (!infini || !wait || !enable || !object || !nb_frames || !line ||
        !nb_lines)
        return (NULL);
    return copy_list(list);
}

int init_mobs_animation_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_mobs_animation;
    addon->on_event = NULL;
    addon->on_tick = tick_mobs_animation;
    addon->init = init_mobs_animation;
    addon->on_collision = NULL;
    if (create_addon("mobs_animation", addon, engine) == sfFalse)
        return 84;
    return 0;
}
