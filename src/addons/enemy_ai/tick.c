/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** tick.c
*/

#include "game.h"

static sfVector2f get_next_position(object_t *object, engine_t *engine)
{
    object_t *main = seach_object(engine, "main_pokemon");
    object_t *cont = seach_object(engine, "controller");
    grid_controller_t *controller = get_addon_data("grid_controller", cont);
    sfVector2f normal = get_normalize_vector(get_position(object),
        get_position(main));
    
    if (!controller)
        return get_position(object);
    normal.x = round(normal.x);
    normal.y = round(normal.y);
    normal.x *= 49;
    normal.y *= 49;
    normal.x += get_position(object).x;
    normal.y += get_position(object).y;
    if (equal_vector2f(controller->move_point, normal) ||
        !if_collision(object, main))
        return get_position(object);
    return normal;
}

int tick_enemy_ai(object_t *object, engine_t *engine)
{
    grid_controller_t *controller = get_addon_data("enemy_ai", object);
    object_t *main = seach_object(engine, "main_pokemon");
    sfVector2f normal = get_normalize_vector(get_position(object),
        controller->move_point);
    
    normal.x *= 15 * (get_delta(engine) / 100);
    normal.y *= 15 * (get_delta(engine) / 100);
    controller->time -= (controller->time > 0) ? get_delta(engine) : 0;
    move_vector(object, normal);
    if (equal_vector2f_pov(get_position(object),
        controller->move_point, 1)) {
        set_position_vector(object, controller->move_point);
        controller->move_point = get_next_position(object, engine);
    }
    if (equal_vector2f(get_position(object), controller->move_point) &&
        controller->time <= 0) {
        attack_ai(controller, main, engine);
        controller->time = 1000;
    }
}