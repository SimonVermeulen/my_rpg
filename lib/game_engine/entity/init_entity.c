/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** init_entity.c
*/

#include "game_engine.h"
#include "my.h"

static const char *entity_name[] =
{
    "CircleShape",
    "Sprite",
    "ConvexShape",
    "RectangleShape",
    "Text",
    "Sound",
    0
};

static void *(*const create_entity[])(void) =
{
    sfCircleShape_create,
    sfSprite_create,
    sfConvexShape_create,
    sfRectangleShape_create,
    sfText_create,
    sfSound_create
};

bool init_entity(list_t *entity_list, object_t *object)
{
    char *type = get_value_list(entity_list, "type", 4);
    int *order = get_value_list(entity_list, "order", 3);
    entity_t *entity = malloc(sizeof(entity_t));

    if (!type || !order || !entity_list || !entity)
        return false;
    entity->order = *order;
    for (int i = 0; entity_name[i] != 0; i++)
        if (!my_strcmp(type, entity_name[i])) {
            entity->data = (*create_entity[i])();
            entity->type = i;
            break;
        }
    if (!entity->data)
        return false;
    object->entity = entity;
    init_data_entity(get_value_list(entity_list, "parameters", 1), object);
    return true;
}

static void (*const destroy_entities[])(void *) =
{
    sfCircleShape_destroy,
    sfSprite_destroy,
    sfConvexShape_destroy,
    sfRectangleShape_destroy,
    sfText_destroy,
    sfSound_destroy
};

bool destroy_entity(object_t *object)
{
    (*destroy_entities[object->entity->type])(object->entity->data);
    free(object->entity);
    return true;
}

int print_entity(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    if (!object || !object->is_active || !object->entity)
        return 0;
    node = create_add_node(object->entity, 0, "entity", engine->print);
    return (node) ? true : false;
}