/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** movement
*/

#include "game.h"

const sfVector2f position[5] =
{
    (sfVector2f) {0, -1},
    (sfVector2f) {0, 1},
    (sfVector2f) {1, 0},
    (sfVector2f) {1, 0},
    (sfVector2f) {0, 0}
};

const char *name[5] =
{
    "top",
    "bottom",
    "left",
    "right",
    "idle"
};

static int enable_object(object_t *object, engine_t *engine,
    player_contoller_t *controller)
{
    const char *last = NULL;

    for (int i = 0; i < 4; i++) {
        if (equal_vector2f(controller->direction, position[i])) {
            last = controller->last;
            controller->last = name[i];
            set_active(true, seek_object_scene(object->actual_scene,
                get_value_list(controller->list, name[i], 4)), engine);
        }
        if (last != controller->last) {
            set_active(false, seek_object_scene(object->actual_scene,
                get_value_list(controller->list, last, 4)), engine);
        }
    }
}

int event_player_controller(object_t *object, engine_t *engine)
{
    player_contoller_t *controller = get_addon_data("player_controller",
        object);

    if (if_key_pressed(engine, sfKeyUp))
        *controller = (player_contoller_t) {true, (sfVector2f) {0, -1}};
    if (if_key_pressed(engine, sfKeyDown))
        *controller = (player_contoller_t) {true, (sfVector2f) {0, 1}};
    if (if_key_pressed(engine, sfKeyLeft))
        *controller = (player_contoller_t) {true, (sfVector2f) {-1, 0}};
    if (if_key_pressed(engine, sfKeyRight))
        *controller = (player_contoller_t) {true, (sfVector2f) {1, 0}};
    if (if_key_released(engine, sfKeyUp) || if_key_released(engine, sfKeyDown)
        || if_key_released(engine, sfKeyLeft) ||
        if_key_released(engine, sfKeyRight))
        *controller = (player_contoller_t) {false, (sfVector2f) {0, 0}};
    enable_object(object, engine, controller);
}