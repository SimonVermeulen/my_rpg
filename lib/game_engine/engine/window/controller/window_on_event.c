/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** window_on_event.c
*/

#include "game_engine.h"

int loop_track_on_event(list_t *scene, engine_t *engine);

int loop_execution_on_event(object_t *object, engine_t *engine)
{
    addon_t *addon = NULL;
    node_t *node = NULL;

    node = object->addons->head;
    for (int i = 0; i < object->addons->nb_elements; i++, node = node->next) {
        addon = node->value;
        if (addon->on_event != NULL)
            addon->on_event(object, engine);
        if (object->is_active == sfTrue && object->is_pause == sfFalse)
            loop_track_on_event(object->childs, engine);
    }
    return 0;
}

int loop_track_on_event(list_t *scene, engine_t *engine)
{
    object_t *object = NULL;
    node_t *node = NULL;

    if (scene == NULL)
        return 0;
    node = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, node = node->next) {
        object = node->value;
        if (object->addons != NULL && object->is_active == sfTrue &&
            object->is_pause == sfFalse)
            loop_execution_on_event(object, engine);
    }
    return 0;
}

int window_on_event(engine_t *engine)
{
    list_t *c = (engine->const_scene) ? engine->const_scene->object : NULL;
    list_t *a = (engine->actual_scene) ? engine->actual_scene->object : NULL;

    while (sfRenderWindow_pollEvent(engine->window, &engine->event)) {
        if (engine->event.type == sfEvtClosed)
            exit_game(engine, 0);
        loop_track_on_event(c, engine);
        loop_track_on_event(a, engine);
    }
    return 0;
}
