/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load_data_object
*/

#include "game.h"
#include "my.h"

static int rename_object(list_t *list, char *name)
{
    node_t *node = search_from_key(list, "name");
    char *copy = my_strdup(name);

    if (!node || node->type != 4 || !copy)
        return false;
    free(node->value);
    node->value = copy;
    return true;
}

static int start_addon(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("load_data_object", object);
    char *name = get_value_list(list, "object", 4);
    data_t *data = get_data_addon(engine);
    list_t *object_list = NULL;

    if (!name || !data || object->childs)
        return exit_game(engine, 84);
    object->childs = create_empty_list();
    object_list = launch_parsing(get_value_list(data->data, name, 4));
    if (!object->childs || !object_list || !rename_object(object_list, name))
        return exit_game(engine, 84);
    create_object_list(object_list, object->childs, engine, object);
    on_start(object->childs, engine);
}

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "load_data_object");
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

int init_load_data_object_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = start_addon;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("load_data_object", addon, engine) == sfFalse)
        return 84;
    return 0;
}
