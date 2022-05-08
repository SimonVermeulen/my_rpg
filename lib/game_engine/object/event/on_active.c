/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** on_enable.c
*/

#include "game_engine.h"

int on_active(object_t *object, engine_t *engine)
{
    addon_t *addon = NULL;
    node_t *node = object->addons->head;

    for (int i = 0; i < object->addons->nb_elements; i++, node = node->next) {
        addon = node->value;
        if (object->is_active == sfTrue) {
            add_function(addon->on_enable, 0, object, engine);
            continue;
        }
        add_function(addon->on_disable, 0, object, engine);
    }
    return 0;
}
