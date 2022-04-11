/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** addon.c
*/

#include <stdlib.h>
#include "game_engine.h"
#include "my.h"

void *get_addon_data(char const *name, object_t *object)
{
    node_t *node = NULL;

    if (object == NULL)
        return NULL;
    node = search_from_key(object->addons_data, name);
    if (node == NULL)
        return NULL;
    return node->value;
}

sfBool create_addon(char const *name, addon_t *addon, engine_t *engine)
{
    node_t *node = malloc(sizeof(node_t));

    if (addon == NULL || engine == NULL || node == NULL)
        return sfFalse;
    node->value = addon;
    node->len = 0;
    node->key = my_strdup(name);
    push_element(engine->addons, node);
    return sfTrue;
}

sfBool add_addon(char const *name, object_t *object, engine_t *engine,
    list_t *data)
{
    node_t *node = search_from_key(engine->addons, name);
    node_t *new = NULL;
    addon_t *addon = NULL;
    void *data_struct = NULL;

    if (!object || !engine || !name || !node)
        return sfFalse;
    addon = node->value;
    if (addon->init) {
        data_struct = addon->init(data);
        if (!data_struct)
            return sfFalse;
        new = create_add_node(data_struct, 0, name, object->addons_data);
        if (!new)
            return sfFalse;
    }
    new = create_add_node(node->value, 0, node->key, object->addons);
    return (new) ? true : false;
}

int destroy_addons(list_t *addon, sfBool boolean)
{
    if (addon == NULL)
        return ERROR;
    while (addon->nb_elements != 0) {
        addon->head->len = 0;
        if (boolean == sfTrue) {
            addon->head->value = NULL;
        }
        shift_element(addon);
    }
    free(addon);
    return 0;
}
