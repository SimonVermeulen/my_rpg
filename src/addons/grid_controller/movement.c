/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** movement.c
*/

#include "game.h"

int event_grid_controller(object_t *object, engine_t *engine)
{
    grid_controller_t *controller = get_addon_data("grid_controller", object);
    sfVector2f point = controller->move_point;

    if (calc_distance(get_position(controller->object),
        controller->move_point) > 75)
        return 0;
    if (if_key_pressed(engine, sfKeyUp) &&
        !is_hover_all(engine, (sfVector2f) {point.x, point.y - 75}))
        controller->move_point.y += -75;
    if (if_key_pressed(engine, sfKeyDown) &&
        !is_hover_all(engine, (sfVector2f) {point.x, point.y + 75}))
        controller->move_point.y += 75;
    if (if_key_pressed(engine, sfKeyLeft) &&
        !is_hover_all(engine, (sfVector2f) {point.x - 75, point.y}))
        controller->move_point.x += -75;
    if (if_key_pressed(engine, sfKeyRight) &&
        !is_hover_all(engine, (sfVector2f) {point.x + 75, point.y}))
        controller->move_point.x += 75;
}

int tick_grid_controller(object_t *object, engine_t *engine)
{
    grid_controller_t *controller = get_addon_data("grid_controller", object);
    sfVector2f normal = get_normalize_vector(get_position(controller->object),
        controller->move_point);
    
    normal.x *= 15 * (get_delta(engine) / 100);
    normal.y *= 15 * (get_delta(engine) / 100);
    move_vector(controller->object, normal);
    if (equal_vector2f_pov(get_position(controller->object),
        controller->move_point, 1))
        set_position_vector(controller->object, controller->move_point);
}