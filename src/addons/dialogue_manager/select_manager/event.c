/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event
*/

#include "game.h"

static int turn_page(object_t *object, engine_t *engine, char *turn)
{
    set_active(true, seek_object_scene(object->actual_scene, turn),
        engine);
    set_active(false, object, engine);
}

int event_select_manager(object_t *object, engine_t *engine)
{
    select_manager_t *select = get_addon_data("select_manager", object);
    char *left = get_value_list(select->data, "left", 4);
    char *right = get_value_list(select->data, "right", 4);

    if (if_key_pressed(engine, sfKeyUp))
        select->count += (select->count + 1 < select->length) ? 1 : 0;
    if (if_key_pressed(engine, sfKeyDown))
        select->count -= (select->count - 1 >= 0) ? 1 : 0;
    if (if_key_pressed(engine, sfKeyLeft))
        turn_page(object, engine, right);
    if (if_key_pressed(engine, sfKeyRight))
        turn_page(object, engine, right);
    if (if_key_pressed(engine, sfKeyA)) {
        set_active(true, seek_object_scene(object->actual_scene,
        get_value_list(select->items[select->count], "enable", 4)), engine);
        set_active(false, object, engine);
    }
}