/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** init_object_by_list.c
*/

#include "game_engine.h"

int add_addon_by_list(list_t *object_list, engine_t *engine, object_t *object)
{
    list_t *addons = get_value_list(object_list, "addons", 1);
    node_t *travel = NULL;

    if (!addons)
        return ERROR;
    travel = addons->head;
    for (int i = 0; i < addons->nb_elements; i++) {
        if (travel->type != 1)
            continue;
        if (!add_addon(travel->key, object, engine, travel->value))
            return exit_game(engine, 84);
        travel = travel->next;
    }
    return 0;
}

object_t *add_object_child(list_t *object_list,
    object_t *object, engine_t *engine)
{
    list_t *scene = get_value_list(object_list, "children", 1);

    if (scene == NULL)
        return object;
    object->childs = init_objects_list(scene, engine, object);
    if (object->childs == NULL)
        return NULL;
    return object;
}

object_t *init_object_list(list_t *list, list_t *scene, engine_t *engine,
    object_t *parent)
{
    object_t *object = NULL;
    char *name = get_value_list(list, "name", 4);

    if (!name)
        return NULL;
    object = create_object(name, scene, engine);
    if (object == NULL)
        return NULL;
    object->parent = parent;
    init_entity(get_value_list(list, "entity", 1), object);
    if (!init_collision(list, object))
        return NULL;
    add_addon_by_list(list, engine, object);
    return add_object_child(list, object, engine);
}

object_t *create_object_list(list_t *list, list_t *scene, engine_t *engine,
    object_t *parent)
{
    object_t *object = NULL;
    char *prefab = get_value_list(list, "PrefabPath", 4);
    list_t *object_list = NULL;
    
    if (!prefab)
        return init_object_list(list, scene, engine, parent);
    object_list = launch_parsing(prefab);
    if (!object_list)
        return NULL;
    object = init_object_list(object_list, scene, engine, parent);
    free_json_object(object_list);
    return object;
}