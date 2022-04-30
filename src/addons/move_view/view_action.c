/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** view_action
*/

#include "game.h"

vector_speed_t *create_vector_speed(list_t *list);

static void move_the_view(sfView *bloc, vector_speed_t *destination,
    engine_t *engine, int *start)
{
    sfVector2f position = sfView_getCenter(bloc);
    sfVector2f normal = get_normalize_vector(position, destination->position);

    if (equal_vector2f_pov(position, destination->position, 10.0)) {
        *start += 1;
        return;
    }
    normal.x = normal.x * destination->speed * get_delta(engine) / 100;
    normal.y = normal.y * destination->speed * get_delta(engine) / 100;
    sfView_move(bloc, normal);
    return;
}

static int view_apply(secondary_screen_t *secondary_screen, object_t *object,
    list_t *move_view, int length)
{
    int *start = get_value_list(move_view, "start", 3);
    list_t **path = get_value_list(move_view, "path", 10);
    int *bloc = get_value_list(move_view, "bloc", 3);
    vector_speed_t *destination = create_vector_speed(path[*start % length]);

    if (*bloc == 1)
        move_the_view(secondary_screen->bloc_1, destination, object->engine,
            start);
    else
        move_the_view(secondary_screen->bloc_2, destination, object->engine,
            start);
    if (*start >= length)
        set_active(true, seek_object_scene(object->actual_scene,
        get_value_list(move_view, "enable", 4)), object->engine);
}

int tick_move_view(object_t *object, engine_t *engine)
{
    list_t *move_view = get_addon_data("move_view", object);
    double *wait = get_value_list(move_view, "waitBeforeStart", 2);
    int *start = get_value_list(move_view, "start", 3);
    int length = search_from_key(move_view, "path")->len;
    secondary_screen_t *secondary_screen = get_secondary_screen_data(engine);

    *wait -= get_delta(engine);
    if (*wait > 0 || *start >= length)
        return 0;
    if (secondary_screen->second == NULL)
        return exit_game(engine, 84);
    view_apply(secondary_screen, object, move_view, length);
}