/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** save_scene
*/

#include "game.h"
#include "my.h"

static int enable_addon(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("save_scene", object);
    char *scene_1 = get_value_list(list, "scene_1", 4);
    char *scene_2 = get_value_list(list, "scene_2", 4);
    data_t *data = get_data_addon(engine);
    node_t *scene_a = search_from_key(data->data, "scene_1");
    node_t *scene_b = search_from_key(data->data, "scene_2");

    if (!scene_a || scene_a->type != 4 || !scene_b || scene_b->type != 4
        || !scene_1 || !scene_2)
        return exit_game(engine, 84);
    free(scene_a->value);
    free(scene_b->value);
    scene_a->value = my_strdup(scene_1);
    scene_b->value = my_strdup(scene_2);
}

static void *init_addon(list_t *list)
{
    return copy_list(list);
}

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "save_scene");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

int init_save_scene_addons(engine_t *engine)
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
    if (create_addon("save_scene", addon, engine) == sfFalse)
        return 84;
    return 0;
}