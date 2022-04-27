/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** seach_object.c
*/

#include "game_engine.h"

object_t *seek_object_scene(list_t *scene, char const *name)
{
    node_t *node = NULL;
    object_t *value = NULL;
    object_t *object = NULL;

    if (scene == NULL || name == NULL)
        return NULL;
    node = search_from_key(scene, name);
    if (node != NULL)
        return node->value;
    node = scene->head;
    for (int i = 0; i < scene->nb_elements; i++) {
        object = node->value;
        value = seek_object_scene(object->childs, name);
        if (value != NULL)
            return value;
        node = node->next;
    }
    return NULL;
}

object_t *seach_object(engine_t *engine, char const *name)
{
    object_t *object = NULL;

    if (engine->actual_scene)
        object = seek_object_scene(engine->actual_scene->object, name);
    if (object == NULL && engine->const_scene)
        object = seek_object_scene(engine->const_scene->object, name);
    return object;
}
