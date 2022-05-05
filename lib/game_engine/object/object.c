/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** object.c
*/

#include <unistd.h>
#include "game_engine.h"
#include "my.h"

int create_secondary_step_object(object_t *object, node_t *node,
    char *name, list_t *scene)
{
    object->is_active = sfTrue;
    object->is_pause = sfFalse;
    object->entity = NULL;
    object->parent = NULL;
    object->childs = NULL;
    object->collision.collisions = create_empty_list();
    object->collision.last_position = (sfVector2f) {0, 0};
    if (!object->addons || !object->collision.collisions ||
        !object->addons_data)
        return 84;
    node->value = object;
    node->key = name;
    node->len = 0;
    return push_element(scene, node);
}

object_t *create_object(char const *name, list_t *scene, engine_t *engine)
{
    node_t *node = NULL;
    char *string = NULL;
    object_t *object = NULL;

    if (name == NULL || scene == NULL)
        return NULL;
    node = malloc(sizeof(node_t));
    string = my_strdup(name);
    object = malloc(sizeof(object_t));
    if (node == NULL || string == NULL || object == NULL)
        return NULL;
    object->name = string;
    object->actual_scene = scene;
    object->addons = create_empty_list();
    object->addons_data = create_empty_list();
    object->engine = engine;
    if (create_secondary_step_object(object, node , string, scene) == 84)
        return NULL;
    return object;
}

int destroy_object(object_t *object)
{
    node_t *next = NULL;

    if (object == NULL)
        return 84;
    destroy_addons(object->addons, sfTrue);
    free_json_object(object->addons_data);
    destroy_entity(object);
    destroy_objects_list(object->childs);
    destroy_collision(object);
    next = object->actual_scene->head;
    for (int i = 0; i < object->actual_scene->nb_elements; i++) {
        if (next->value == object) {
            splice(object->actual_scene, i);
            return 0;
        }
        next = next->next;
    }
    return 84;
}

object_t **stock_object(object_t *object)
{
    object_t **stock = malloc(sizeof(object_t *));

    if (stock == NULL || object == NULL) {
        free(stock);
        return NULL;
    }
    *stock = object;
    return stock;
}

sfBool set_active(sfBool value, object_t *object, engine_t *engine)
{
    if (object == NULL || engine == NULL || object->is_active == value)
        return sfFalse;
    object->is_active = value;
    on_active(object, engine);
    return sfTrue;
}
