/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** position_by_view
*/

#include "game.h"

static int start_addon(object_t *object, engine_t *engine)
{
    position_by_view_t *view = get_addon_data("position_by_view", object);

    if (view->inited)
        return 0;
    view->position = get_position(object);
    view->inited = true;
    return 0;
}

static int tick_addon(object_t *object, engine_t *engine)
{
    secondary_screen_t *screen = get_secondary_screen_data(engine);
    position_by_view_t *view = get_addon_data("position_by_view", object);
    sfVector2f position;

    if (!view->inited)
        start_addon(object, engine);
    if (!screen || !screen->bloc_1 || !screen->bloc_2 )
        return exit_game(engine, 84);
    position = (view->bloc == 1) ? sfView_getCenter(screen->bloc_1) :
        sfView_getCenter(screen->bloc_2);
    position.x -= 270;
    position.y -= 270;
    position.x += view->position.x;
    position.y += view->position.y;
    set_position_vector(object, position);
    return 0;
}

static void *init_addon(list_t *list)
{
    position_by_view_t *pos = NULL;
    int *bloc = get_value_list(list, "bloc", 3);

    if (!bloc)
        return NULL;
    pos = malloc(sizeof(position_by_view_t));
    if (!pos)
        return NULL;
    pos->bloc = *bloc;
    pos->inited = false;
    pos->position = (sfVector2f) {0, 0};
    return pos;
}

int init_position_by_view_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = start_addon;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_addon;
    addon->on_event = NULL;
    addon->on_tick = tick_addon;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("position_by_view", addon, engine) == sfFalse)
        return 84;
    return 0;
}