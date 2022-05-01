/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** data
*/

#include "game.h"
#include "my.h"

data_t *get_data_addon(engine_t *engine)
{
    return get_addon_data("data", seach_object(engine, "data"));
}

bool save_data_addon(engine_t *engine)
{
    data_t *data = get_addon_data("data", seach_object(engine, "data"));

    return launch_writing(data->data, data->path, 0);
}

static int end_addon(object_t *object, engine_t *engine)
{
    data_t *data = get_addon_data("data", object);

    save_data_addon(engine);
    free(data->path);
    free_json_object(data->data);
}

static void *init_addon(list_t *list)
{
    char *path = get_value_list(list, "path", 4);
    list_t *value = launch_parsing(path);
    data_t *data = malloc(sizeof(data_t));

    if (!path || !data)
        return NULL;
    if (!value)
        value = create_empty_list();
    data->path = my_strdup(path);
    if (!data->path)
        return NULL;
    data->data = value;
    return data;
}

int init_data_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("data", addon, engine) == sfFalse)
        return 84;
    return 0;
}