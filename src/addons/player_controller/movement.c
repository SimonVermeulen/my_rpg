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
    (sfVector2f) {0, 0},
    (sfVector2f) {-1, -1},
    (sfVector2f) {1, -1},
    (sfVector2f) {-1, 1},
    (sfVector2f) {1, 1},
};

const char *name[5] =
{
    "top",
    "bottom",
    "left",
    "right",
    "idle",
    "top-left",
    "top-right",
    "bottom-left",
    "bottom-right"
};

static int enable_object(object_t *object, engine_t *engine,
    player_contoller_t *controller)
{
    const char *last = NULL;

    for (int i = 0; i < 4; i++) {
        if (equal_vector2f(controller->direction, position[i])) {
            last = controller->last;
            set_active(false, seek_object_scene(object->actual_scene,
                get_value_list(controller->list, last, 4)), engine);
            controller->last = name[i];
            set_active(true, seek_object_scene(object->actual_scene,
                get_value_list(controller->list, name[i], 4)), engine);
        }
    }
}

static int released_move(player_contoller_t *con, engine_t *engine)
{
    if (if_key_released(engine, sfKeyUp) && con->direction.y < 1)
        con->direction.y += 1;
    if (if_key_released(engine, sfKeyDown) && con->direction.y > -1)
        con->direction.y += -1;
    if (if_key_released(engine, sfKeyLeft) && con->direction.x < 1)
        con->direction.x += 1;
    if (if_key_released(engine, sfKeyRight) && con->direction.x > -1)
        con->direction.x += -1;
}

static int pressed_move(player_contoller_t *con, engine_t *engine)
{
    if (if_key_pressed(engine, sfKeyUp) && con->direction.y > -1)
        con->direction.y += -1;
    if (if_key_pressed(engine, sfKeyDown) && con->direction.y < 1)
        con->direction.y += 1;
    if (if_key_pressed(engine, sfKeyLeft) && con->direction.x > -1)
        con->direction.x += -1;
    if (if_key_pressed(engine, sfKeyRight) && con->direction.x < 1)
        con->direction.x += 1;
}

int event_player_controller(object_t *object, engine_t *engine)
{
    player_contoller_t *con = get_addon_data("player_controller",
        object);

    pressed_move(con, engine);
    released_move(con, engine);
    if (con->direction.x > 1 || con->direction.x < -1)
        con->direction.x = 0;
    if (con->direction.y > 1 || con->direction.y < -1)
        con->direction.y = 0;
    enable_object(object, engine, con);
}