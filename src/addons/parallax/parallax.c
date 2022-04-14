/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** parallax.c
*/

#include "game.h"

int tick_parallax(object_t *object, engine_t *engine)
{
    parallax_t *parallax = get_addon_data("parallax", object);
    sfVector2f move = (sfVector2f) {-1, 0};

    move.x = move.x * parallax->speed * (get_delta(engine) / 100);
    move_vector(parallax->element_1, move);
    move_vector(parallax->element_2, move);
    if (get_position(parallax->element_1).x <= -parallax->width)
        set_position_float(parallax->element_1, parallax->width, 0);
    if (get_position(parallax->element_2).x <= -parallax->width)
        set_position_float(parallax->element_2, parallax->width, 0);
    return 0;
}

int start_parallax(object_t *object, engine_t *engine)
{
    object_t *element_1 = seek_object_scene(object->childs, "parallax1");
    object_t *element_2 = seek_object_scene(object->childs, "parallax2");
    parallax_t *parallax = get_addon_data("parallax", object);

    if (!element_1 || !element_2)
        return exit_game(engine, 84);
    parallax->element_1 = element_1;
    parallax->element_2 = element_2;
    return 0;
}

void *init_parallax(list_t *list)
{
    double *speed = get_value_list(list, "speed", 2);
    double *width = get_value_list(list, "width", 2);
    parallax_t *parallax = NULL;

    if (!speed || !width)
        return NULL;
    parallax = malloc(sizeof(parallax_t));
    if (!parallax)
        return NULL;
    parallax->speed = *speed;
    parallax->width = *width;
    parallax->element_1 = NULL;
    parallax->element_2 = NULL;
    return parallax;
}

int init_parallax_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_parallax;
    addon->on_event = NULL;
    addon->on_tick = tick_parallax;
    addon->init = init_parallax;
    addon->on_collision = NULL;
    if (create_addon("parallax", addon, engine) == sfFalse)
        return 84;
    return 0;
}