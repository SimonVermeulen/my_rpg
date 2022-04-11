/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** buffer.c
*/

#include "game_engine.h"

static void *(*const destroy_component[])(void *) =
{
    free,
    sfFont_destroy,
    sfTexture_destroy,
    sfSoundBuffer_destroy,
    sfMusic_destroy
};

bool destroy_buffer(list_t *buffer)
{
    while (buffer->nb_elements != 0) {
        (*destroy_component[buffer->head->type])(buffer->head->value);
        buffer->head->value = NULL;
        buffer->head->type = 0;
        shift_element(buffer);
    }
    free(buffer);
    return true;
}

void *get_item_buffer(object_t *object, int id, const char *name)
{
    object_t *parent = object;

    if (parent->engine->buffer)
        return get_value_list(parent->engine->buffer, name, id);
    for (int i = 0; parent->parent != NULL; i++)
        parent = object->parent;
    if (parent->engine->actual_scene != NULL &&
        parent->engine->actual_scene->object == parent->actual_scene)
        return get_value_list(parent->engine->actual_scene->buffer, name, id);
    if (parent->engine->const_scene != NULL &&
        parent->engine->const_scene->object == parent->actual_scene)
        return get_value_list(parent->engine->const_scene->buffer, name, id);
    return NULL;
}