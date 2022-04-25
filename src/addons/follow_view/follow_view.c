/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** follow_view
*/

#include "game.h"

static int tick_addon(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("follow_view", object);
    object_t *object_follow = seek_object_scene(object->actual_scene,
        get_value_list(list, "object", 4));
    int *bloc = get_value_list(list, "bloc", 3);
    secondary_screen_t *secondary_screen = get_secondary_screen_data(engine);

    if (!bloc)
        return exit_game(engine, 84);
    if (!object_follow)
        object_follow = object;
    if (*bloc == 1)
        sfView_setCenter(secondary_screen->bloc_1,
            get_position(object_follow));
    else
        sfView_setCenter(secondary_screen->bloc_2,
            get_position(object_follow));
    return 0;
}

static void *init_addon(list_t *list)
{
    return copy_list(list);
}

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "follow_view");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

int init_follow_view_addons(engine_t *engine)
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
    if (create_addon("follow_view", addon, engine) == sfFalse)
        return 84;
    return 0;
}