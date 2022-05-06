/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** attack_ai.c
*/

#include "game.h"
#include <math.h>

int attack_ai(grid_controller_t *controller, object_t *enemy,
    engine_t *engine)
{
    sfVector2f direction = get_normalize_vector(
        get_position(controller->object), get_position(enemy));

    direction = (sfVector2f) {round(direction.x), round(direction.y)};
    if (!equal_vector2f(get_position(controller->object),
        controller->move_point) || calc_distance(
        get_position(controller->object), get_position(enemy)) > 75)
        return 0;
    controller->direction = direction;
    if (!controller->is_attack)
        sfThread_launch(controller->coroutine);
    return 0;
}