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
    char *hover = get_value_list(list, "hover", 4);

    set_position_vector(cursor, position);
    set_active(true, seach_object(object->engine, hover),
        object->engine);
    return 0;
}

int tick_select_manager(object_t *object, engine_t *engine)
{
    select_manager_t *select = get_addon_data("select_manager", object);
    object_t *cursor = seek_object_scene(object->actual_scene,
        get_value_list(select->data, "cursor", 4));

    select->time -= (select->time > 0) ? get_delta(engine) : 0;
    return apply_select(object, cursor, select, select->items[select->count]);
}
