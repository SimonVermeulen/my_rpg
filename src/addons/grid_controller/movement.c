/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** movement.c
*/

#include "game.h"
#include <math.h>

int attack_controller(grid_controller_t *controller, engine_t *engine);

static const sfVector2f position[8] =
{
    (sfVector2f) {0, -1},
    (sfVector2f) {0, 1},
    (sfVector2f) {1, 0},
    (sfVector2f) {-1, 0},
    (sfVector2f) {-1, -1},
    (sfVector2f) {1, -1},
    (sfVector2f) {-1, 1},
    (sfVector2f) {1, 1},
};

static int event_controller(grid_controller_t *controller,
    sfVector2f point, engine_t *engine)
{
    if (calc_distance(get_position(controller->object),
        controller->move_point) > 49)
        return 0;

    if (if_key_pressed(engine, sfKeyUp) &&
        !is_hover_all(engine, (sfVector2f) {point.x, point.y - 49}))
        controller->move_point.y += -49;
    if (if_key_pressed(engine, sfKeyDown) &&
        !is_hover_all(engine, (sfVector2f) {point.x, point.y + 49}))
        controller->move_point.y += 49;
    if (if_key_pressed(engine, sfKeyLeft) &&
        !is_hover_all(engine, (sfVector2f) {point.x - 50, point.y}))
        controller->move_point.x += -49;
    if (if_key_pressed(engine, sfKeyRight) &&
        !is_hover_all(engine, (sfVector2f) {point.x + 49, point.y}))
        controller->move_point.x += 49;
}

static int get_rotation(engine_t *engine, grid_controller_t *controller)
{
    for (int i = 0; i < 8; i++) {
        if (equal_vector2f(position[i], controller->direction)) {
            controller->direction = position[(i + 1) % 8];
            break;
        }
    }
}

int event_grid_controller(object_t *object, engine_t *engine)
{
    grid_controller_t *controller = get_addon_data("grid_controller", object);
    sfVector2f point = controller->move_point;

    if (controller->is_attack)
        return 0;
    if (if_key_pressed(engine, sfKeyA))
        attack_controller(controller, engine);
    if (if_key_pressed(engine, sfKeyZ))
        get_rotation(engine, controller);
    event_controller(controller, point, engine);
}

int tick_grid_controller(object_t *object, engine_t *engine)
{
    grid_controller_t *controller = get_addon_data("grid_controller", object);
    sfVector2f normal = get_normalize_vector(get_position(controller->object),
        controller->move_point);

    if (equal_vector2f(normal, (sfVector2f) {0, 0}) || controller->is_attack)
        return 0;
    controller->direction = (sfVector2f) {round(normal.x), round(normal.y)};
    normal.x *= 15 * (get_delta(engine) / 100);
    normal.y *= 15 * (get_delta(engine) / 100);
    move_vector(controller->object, normal);
    if (equal_vector2f_pov(get_position(controller->object),
        controller->move_point, 1))
        set_position_vector(controller->object, controller->move_point);
}