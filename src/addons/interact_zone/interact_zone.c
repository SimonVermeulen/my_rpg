/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** interact_zone
*/

#include "game.h"

static int event_addon(object_t *object, engine_t *engine)
{
    object_t *main = seach_object(engine, "main_pokemon");
    list_t *interact_zone = get_addon_data("interact_zone", object);
    int *interact = get_value_list(interact_zone, "presskey", 3);

    if (!main || !interact || !if_key_pressed(engine, sfKeyA))
        return 0;
    if (if_collision(main, object))
        set_active(true, seek_object_scene(object->actual_scene,
            get_value_list(interact_zone, "enable", 4)), engine);
}

static int tick_addon(object_t *object, engine_t *engine)
{
    object_t *main = seach_object(engine, "main_pokemon");
    object_t *second = seach_object(engine, "second_pokemon");
    list_t *interact_zone = get_addon_data("interact_zone", object);
    int *interact = get_value_list(interact_zone, "presskey", 3);

    if (!main || interact)
        return 0;
    if (if_collision(main, object))
        set_active(true, seek_object_scene(object->actual_scene,
            get_value_list(interact_zone, "enable", 4)), engine);
}

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "interact_zone");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

static void *init_addon(list_t *list)
{
    return copy_list(list);
}

int init_interact_zone_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = NULL;
    addon->on_event = event_addon;
    addon->on_tick = tick_addon;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("interact_zone", addon, engine) == sfFalse)
        return 84;
    return 0;
}