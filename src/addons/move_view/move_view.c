/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-adil.nouiri
** File description:
** move_view.c
*/

#include "game.h"

int tick_move_view(object_t *object, engine_t *engine);

int end_move_view(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "move_view");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

void *init_move_view(list_t *list)
{
    double *wait = get_value_list(list, "waitBeforeStart", 2);
    int *start = get_value_list(list, "start", 3);
    list_t **path = get_value_list(list, "path", 10);
    int *bloc = get_value_list(list, "bloc", 3);

    if (!wait || !start || !path || !bloc)
        return NULL;
    return copy_list(list);
}

int init_move_view_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_move_view;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_move_view;
    addon->init = init_move_view;
    addon->on_collision = NULL;
    if (create_addon("move_view", addon, engine) == sfFalse)
        return 84;
    return 0;
}
