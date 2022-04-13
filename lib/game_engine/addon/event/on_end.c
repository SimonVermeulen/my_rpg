/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** on_end.c
*/

#include "game_engine.h"

int loop_execution_end(object_t *object, engine_t *engine)
{
    addon_t *addon = NULL;
    node_t *node = NULL;

    node = object->addons->head;
    for (int i = 0; i < object->addons->nb_elements; i++, node = node->next) {
        addon = node->value;
        if (addon->on_end != NULL)
            add_function(addon->on_end, 0, object, engine);
    }
    return 0;
}

int window_on_end(list_t *scene, engine_t *engine)
{
    object_t *object = NULL;
    node_t *node = NULL;

    if (scene == NULL)
        return 0;
    node = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, node = node->next) {
        object = node->value;
        loop_execution_end(object, engine);
        on_start(object->childs, engine);
    }
    return 0;
}

int on_end(list_t *scene, engine_t *engine)
{
    if (scene == NULL || engine == NULL)
        return 84;
    window_on_end(scene, engine);
    return 0;
}
