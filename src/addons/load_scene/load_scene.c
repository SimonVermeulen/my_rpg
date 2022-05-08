/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load_scene
*/

#include "game.h"

static int enable_addon(object_t *object, engine_t *engine)
{
    data_t *data = get_data_addon(engine);
    char *scene_1 = get_value_list(data->data, "scene_1", 4);
    char *scene_2 = get_value_list(data->data, "scene_2", 4);

    change_scene(scene_1, engine);
    change_secondary_screen(scene_2, engine);
}

static void *init_addon(list_t *list)
{
    return copy_list(list);
}

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "load_scene");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

int init_load_scene_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = enable_addon;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = enable_addon;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("load_scene", addon, engine) == sfFalse)
        return 84;
    return 0;
}