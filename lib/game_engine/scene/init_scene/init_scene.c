/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** scene.c
*/

#include "game_engine.h"
#include "my.h"

bool init_scene_path(const char *path, const char *name, engine_t *engine)
{
    char *copy_path = my_strdup(path);
    node_t *node = NULL;

    if (!copy_path || !path || !name)
        return false;
    node = create_add_node(copy_path, 4, name, engine->scenes);
    if (!node)
        return false;
    return true;
}

scene_t *init_scene_by_list(list_t *scene_list, engine_t *engine)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (!scene)
        return NULL;
    scene->buffer = create_empty_list();
    if (!init_buffer(get_value_list(scene_list, "buffer", 1), scene))
        return NULL;
    engine->buffer = scene->buffer;
    scene->object = init_objects_list(scene_list, engine, NULL);
    engine->buffer = NULL;
    if (!scene->object)
        return NULL;
    return scene;
}