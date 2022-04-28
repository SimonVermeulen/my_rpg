/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event
*/

#include "game.h"

static int active_dialogue(object_t *object, engine_t *engine,
    text_animation_t *animation)
{
    dialogue_t *dialogue = NULL;
    object_t *parent = (object->parent) ? object->parent->parent :
        object->parent;

    dialogue = get_addon_data("dialogue_manager", seek_object_scene(
    object->actual_scene, get_value_list(animation->data, "enable", 4)));
    if (!dialogue)
        dialogue = get_addon_data("dialogue_manager", parent);
    if (dialogue) {
        dialogue->active = false;
        dialogue->count++;
        set_active(false, object->parent, engine);
    }
}

int event_text_animation(object_t *object, engine_t *engine)
{
    text_animation_t *animation = get_addon_data("text_animation", object);

    if (animation->count >= my_strlen(animation->string) &&
        if_key_pressed(engine, sfKeyA)) {
        set_active(false, seek_object_scene(object->childs,
            get_value_list(animation->data, "cursor", 4)), engine);
        set_active(true, seek_object_scene(object->actual_scene,
            get_value_list(animation->data, "enable", 4)), engine);
        active_dialogue(object, engine, animation);
        animation->prize = 0;
    }
}