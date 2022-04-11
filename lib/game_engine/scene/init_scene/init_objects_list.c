/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** init_scene_by_list.c
*/

#include "game_engine.h"

list_t *add_objects_by_list(node_t *lists, list_t *scene, engine_t *engine,
    object_t *parent)
{
    list_t **array = NULL;

    if (lists == NULL || scene == NULL)
        return NULL;
    array = lists->value;
    for (int i = 0; i < lists->len; i++) {
        if (create_object_list(array[i], scene, engine, parent) == NULL)
            return NULL;
    }
    return scene;
}

list_t *init_objects_list(list_t *object, engine_t *engine, object_t *parent)
{
    list_t *scene = NULL;
    node_t *node = NULL;

    if (object == NULL || engine == NULL)
        return NULL;
    scene = create_empty_list();
    if (scene == NULL)
        return NULL;
    node = search_from_key(object, "objects");
    if (node == NULL || node->type != 10)
        return NULL;
    return add_objects_by_list(node, scene, engine, parent);
}
