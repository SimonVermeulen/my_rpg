/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** attack_controller.c
*/

#include "game.h"

static void move_by_time(sfVector2f b, sfVector2f normal,
    double time, object_t *object)
{
    while (!equal_vector2f_pov(get_position(object), b, 2)) {
        move_vector(object, normal);
        sleep(time);
    }
}

void coroutine_attack_event(grid_controller_t *controller)
{
    sfVector2f direction = controller->direction;
    sfVector2f normal;
    
    controller->is_attack = true;
    direction.x *= 75;
    direction.y *= 75;
    direction.x += get_position(controller->object).x;
    direction.y += get_position(controller->object).y;
    normal = get_normalize_vector(direction, get_position(controller->object));
    move_by_time(direction, controller->direction, 2, controller->object);
    move_by_time(controller->move_point, normal, 2, controller->object);
    set_position_vector(controller->object, controller->move_point);
    controller->is_attack = false;
}

int attack_controller(grid_controller_t *controller, engine_t *engine)
{
    sfVector2f direction = controller->direction;

    if (!equal_vector2f(get_position(controller->object),
        controller->move_point))
        return 0;
    direction.x *= 75;
    direction.y *= 75;
    direction.x += get_position(controller->object).x;
    direction.y += get_position(controller->object).y;
    if (!controller->is_attack && !is_hover_all(engine, direction))
        sfThread_launch(controller->coroutine);
    return 0;
}