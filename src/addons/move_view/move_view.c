/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-adil.nouiri
** File description:
** move_view.c
*/

#include "game.h"

int end_move_view(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "move_view");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

static void move_the_view(sfView *bloc, double speed,
    engine_t *engine, sfVector2f destination)
{
    sfVector2f position = sfView_getCenter(bloc);
    sfVector2f normal = get_normalize_vector(position, destination);

    if (equal_vector2f_pov(position, destination, 10.0))
        return;
    normal.x = normal.x * speed * get_delta(engine) / 100;
    normal.y = normal.y * speed * get_delta(engine) / 100;
    sfView_move(bloc, normal);
    return;
}

int tick_move_view(object_t *object, engine_t *engine)
{
    list_t *move_view = get_addon_data("move_view", object);
    double *wait = get_value_list(move_view, "waitBeforeStart", 2);
    double *speed = get_value_list(move_view, "speed", 2);
    list_t *path = get_value_list(move_view, "path", 1);
    secondary_screen_t *secondary_screen = get_secondary_screen_data(engine);
    int *bloc = get_value_list(move_view, "bloc", 3);
    sfVector2f destination = create_vector2f_list(path);
    sfVector2f *step = get_value_list(move_view, "step", 3);

    *wait -= get_delta(engine);
    if (*wait > 0)
        return 0;
    if (secondary_screen->second == NULL)
        return exit_game(engine, 84);
    if (*bloc == 1)
        move_the_view(secondary_screen->bloc_1, *speed, engine, destination);
    else
        move_the_view(secondary_screen->bloc_2, *speed, engine, destination);
    return 0;
}

void *init_move_view(list_t *list)
{
    double *wait = get_value_list(list, "waitBeforeStart", 2);
    double *speed = get_value_list(list, "speed", 2);
    list_t *path = get_value_list(list, "path", 1);
    int *bloc = get_value_list(list, "bloc", 3);

    if (!wait || !speed || !path || !bloc)
        return NULL;
    return copy_list(list);
}

int init_move_view_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_move_view;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_move_view;
    addon->init = init_move_view;
    addon->on_collision = NULL;
    if (create_addon("move_view", addon, engine) == sfFalse)
        return 84;
    return 0;
}
