/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** translation_animation.c
*/

#include "game.h"

int tick_translation_animation(object_t *object, engine_t *engine);

void *init_translation_animation(list_t *list);

int end_translation_animation(object_t *object, engine_t *engine)
{
    translation_animation_t *translation =
        get_addon_data("translation_animation", object);

    free_json_object(translation->positions);
    return 0;
}

static int start_addons(object_t *object, engine_t *engine)
{
    translation_animation_t *translation =
        get_addon_data("translation_animation", object);
    object_t *object_trans = seek_object_scene(object->actual_scene,
    translation->name);

    if (object_trans)
        translation->object = object_trans;
    else
        translation->object = object;
    translation->enable = seek_object_scene(object->actual_scene,
        translation->name_enable);
}

int init_translation_animation_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = start_addons;
    addon->on_disable = NULL;
    addon->on_end = end_translation_animation;
    addon->on_start = start_addons;
    addon->on_event = NULL;
    addon->on_tick = tick_translation_animation;
    addon->init = init_translation_animation;
    addon->on_collision = NULL;
    if (create_addon("translation_animation", addon, engine) == sfFalse)
        return 84;
    return 0;
}
