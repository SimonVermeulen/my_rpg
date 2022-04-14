/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** scene.c
*/

#include "game_engine.h"

scene_t *load_scene_by_path(char const *path, engine_t *engine)
{
    list_t *scene = launch_parsing(path);
    scene_t *map = NULL;

    if (scene == NULL)
        return NULL;
    map = init_scene_by_list(scene, engine);
    free_json_object(scene);
    return map;
}

sfBool change_scene(char const *name, engine_t *engine)
{
    char *current = NULL;

    if (engine == NULL)
        return sfFalse;
    current = get_value_list(engine->scenes, name, 4);
    if (current == NULL)
        return sfFalse;
    if (engine->actual_scene)
        on_end(engine->actual_scene->object, engine);
    engine->prev_scene = engine->actual_scene;
    engine->actual_scene = load_scene_by_path(current, engine);
    if (engine->actual_scene == NULL) {
        exit_game(engine, 84);
        return sfFalse;
    }
    on_start(engine->actual_scene->object, engine);
    return sfTrue;
}

sfBool set_const_scene(char const *name, engine_t *engine)
{
    char *current = NULL;

    if (engine == NULL)
        return sfFalse;
    current = get_value_list(engine->scenes, name, 4);
    if (current == NULL)
        return sfFalse;
    engine->const_scene = load_scene_by_path(current, engine);
    if (engine->const_scene == NULL) {
        exit_game(engine, 84);
        return sfFalse;
    }
    on_start(engine->const_scene->object, engine);
    return sfTrue;
}

int destroy_objects_list(list_t *scene)
{
    node_t *node = NULL;

    if (!scene)
        return 0;
    while (scene->nb_elements != 0) {
        node = scene->head;
        destroy_object(node->value);
    }
    free(scene);
    return 0;
}

int destroy_scene(scene_t *scene)
{
    if (scene == NULL)
        return ERROR;
    destroy_objects_list(scene->object);
    destroy_buffer(scene->buffer);
    free(scene);
    return 0;
}
