/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** particle_a
*/

#include "game.h"

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "particle");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

static int create_particle(list_t *object_list, object_t *object,
    list_t *particle)
{
    sfVector2f pos =
        create_vector2f_list(get_value_list(particle, "position", 1));
    object_t *child = create_object_list(object_list, object->childs,
        object->engine, object);
    
    set_position_vector(child, pos);
}

static int tick_addon(object_t *object, engine_t *engine)
{
    list_t *particle = get_addon_data("particle", object);
    int *spawn_count = get_value_list(particle, "spawn_count", 3);
    double *time = get_value_list(particle, "time", 2);
    double *count = get_value_list(particle, "count", 2);
    char *particle_path = get_value_list(particle, "particle_path", 4);
    list_t *object_list = NULL;

    if (!spawn_count || !time || !count || !particle_path)
        return exit_game(engine, 84);
    if (!object->childs)
        object->childs = create_empty_list();
    *count += get_delta(engine);
    object_list = launch_parsing(particle_path);
    if (*time > *count || !object_list)
        return free_json_object(object_list);
    for (int i = 0; i < *spawn_count; i++)
        create_particle(object_list, object, particle);
    free_json_object(object_list);
    *count = 0;
}

static void *init_addon(list_t *list)
{
    return copy_list(list);
}

int init_particle_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_addon;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("particle", addon, engine) == sfFalse)
        return 84;
    return 0;
}
