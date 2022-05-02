/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event
*/

#include "game.h"

static int turn_page(object_t *object, engine_t *engine, char *turn)
{
    object_t *page = seek_object_scene(object->actual_scene, turn);

    if (!page)
        return 0;
    set_active(true, page, engine);
    set_active(false, object, engine);
}

static int active_dialogue(object_t *object, engine_t *engine,
    select_manager_t *select)
{
    dialogue_t *dialogue = NULL;
    object_t *parent = (object->parent) ? object->parent->parent :
        object->parent;
    int *count = get_value_list(select->data, "indexDialogue", 3);

    if (!parent)
        parent = object->parent;
    if (!parent)
        parent = object->actual_scene;
    dialogue = get_addon_data("dialogue_manager", seek_object_scene(
        parent->actual_scene, get_value_list(select->data,
        "dialogue_manager", 4)));
    if (dialogue) {
        dialogue->active = false;
        dialogue->count = (count) ? *count : dialogue->count + 1;
        if (dialogue->count < 0 || dialogue->count >= dialogue->length)
            dialogue->count = 0;
    }
}

int event_select_manager(object_t *object, engine_t *engine)
{
    select_manager_t *select = get_addon_data("select_manager", object);
    char *left = get_value_list(select->data, "left", 4);
    char *right = get_value_list(select->data, "right", 4);

    if (select->time > 0)
        return 0;
    if (if_key_pressed(engine, sfKeyUp))
        select->count -= (select->count - 1 >= 0) ? 1 : 0;
    if (if_key_pressed(engine, sfKeyDown))
        select->count += (select->count + 1 < select->length) ? 1 : 0;
    if (if_key_pressed(engine, sfKeyLeft))
        turn_page(object, engine, left);
    if (if_key_pressed(engine, sfKeyRight))
        turn_page(object, engine, right);
    if (if_key_pressed(engine, sfKeyA)) {
        set_active(true, seach_object(engine, get_value_list(
            select->items[select->count], "enable", 4)), engine);
        active_dialogue(object, engine, select);
        set_active(false, object, engine);
    }
}