/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init
*/

#include "game.h"

int tick_select_manager(object_t *object, engine_t *engine);
int event_select_manager(object_t *object, engine_t *engine);

static int disable_addon(object_t *object, engine_t *engine)
{
    select_manager_t *select = get_addon_data("select_manager", object);

    select->time = 500;
}

static void *init_addon(list_t *list)
{
    node_t *actions_node = search_from_key(list, "items");
    select_manager_t *select = NULL;
    list_t *copy = NULL;

    if (!actions_node || actions_node->type != 10)
        return NULL;
    select = malloc(sizeof(select_manager_t));
    copy = copy_list(list);
    if (!select || !copy)
        return NULL;
    select->data = copy;
    select->items = search_from_key(copy, "items")->value;
    select->length = actions_node->len;
    select->time = 500;
    select->count = 0;
    return select;
}

int init_select_manager_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = disable_addon;
    addon->on_disable = disable_addon;
    addon->on_end = NULL;
    addon->on_start = disable_addon;
    addon->on_event = event_select_manager;
    addon->on_tick = tick_select_manager;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("select_manager", addon, engine) == sfFalse)
        return 84;
    return 0;
}