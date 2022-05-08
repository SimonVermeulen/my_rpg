/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** init.c
*/

#include "game.h"
#include "my.h"

static void *init_addon(list_t *list)
{
    grid_t *grid = malloc(sizeof(grid_t));
    node_t *node = NULL;

    if (!grid)
        return NULL;
    grid->list = copy_list(list);
    if (!grid->list)
        return NULL;
    node = search_from_key(grid->list, "map");
    if (!node || node->type != 40)
        return NULL;
    grid->map = node->value;
    grid->height = node->len;
    grid->width = my_strlen(grid->map[0]);
    return grid;
}

static int end_addon(object_t *object, engine_t *engine)
{
    grid_t *grid = get_addon_data("grid", object);

    free_json_object(grid->list);
    return 0;
}

int init_grid_addons(engine_t *engine)
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
    if (create_addon("grid", addon, engine) == sfFalse)
        return 84;
    return 0;
}
