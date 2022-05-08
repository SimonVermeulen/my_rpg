/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** pause
*/

#include "game.h"

int on_pause(list_t *scene, engine_t *engine, bool condition, object_t *out)
{
    object_t *object = NULL;
    node_t *node = NULL;

    if (scene == NULL)
        return 0;
    node = scene->head;
    for (int i = 0; i < scene->nb_elements; i++, node = node->next) {
        object = node->value;
        if (object == out)
            continue;
        object->is_pause = condition;
        //on_pause(object->childs, engine, condition, out);
    }
    return 0;
}

static int enable_addon(object_t *object, engine_t *engine)
{
    on_pause(object->actual_scene, engine, true, object);
}

static int end_addon(object_t *object, engine_t *engine)
{
    on_pause(object->actual_scene, engine, false, object);
}

int init_pause_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = enable_addon;
    addon->on_disable = end_addon;
    addon->on_end = end_addon;
    addon->on_start = enable_addon;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = NULL;
    addon->on_collision = NULL;
    if (create_addon("pause", addon, engine) == sfFalse)
        return 84;
    return 0;
}