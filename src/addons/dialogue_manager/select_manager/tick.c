/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** tick
*/

#include "game.h"

static int apply_select(object_t *object, object_t *cursor,
    select_manager_t *select, list_t *list)
{
    sfVector2f position = create_vector2f_list(get_value_list(list,
        "position", 1));
    char *hover = get_value_list(object, "hover", 4);

    set_position_vector(cursor, position);
    set_active(true, seek_object_scene(object->actual_scene, hover),
        object->engine);
    return 0;
}

int tick_select_manager(object_t *object, engine_t *engine)
{
    select_manager_t *select = get_addon_data("select_manager", object);
    object_t *cursor = seek_object_scene(object->actual_scene,
        get_addon_data("cursor", cursor));
    
    return apply_select(object, cursor, select, select->items[select->count]);
}