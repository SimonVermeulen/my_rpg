/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** view_controller.c
*/

#include "game.h"

int tick_secondary_screen(object_t *object, engine_t *engine)
{
    secondary_screen_t *secondary_screen = get_addon_data("secondary_screen",
        object);

    sfRenderWindow_setView(engine->window, secondary_screen->bloc_2);
    if (secondary_screen->prev) {
        destroy_scene(secondary_screen->prev);
        secondary_screen->prev = NULL;
    }
    if (secondary_screen->second) {
        execute_game(secondary_screen->second->object, engine);
        print_list(engine->print, engine);
    }
    sfRenderWindow_setView(engine->window, secondary_screen->bloc_1);
}

int end_secondary_screen(object_t *object, engine_t *engine)
{
    secondary_screen_t *view_controller = get_addon_data("secondary_screen",
        object);

    if (view_controller->second)
        on_end(view_controller->second->object, engine);
    destroy_scene(view_controller->second);
    sfView_destroy(view_controller->bloc_1);
    sfView_destroy(view_controller->bloc_2);
}

int start_secondary_screen(object_t *object, engine_t *engine)
{
    secondary_screen_t *secondary_screen = get_addon_data("secondary_screen",
        object);

    sfView_setViewport(secondary_screen->bloc_2, (sfFloatRect)
        {0, 0, 1, 0.5f});
    sfView_setSize(secondary_screen->bloc_2, (sfVector2f) {700, 500});
    sfView_setCenter(secondary_screen->bloc_2, (sfVector2f) {350, 250});
    sfView_setViewport(secondary_screen->bloc_1, (sfFloatRect)
        {0, 0.5f, 1, 0.5f});
    sfView_setSize(secondary_screen->bloc_1, (sfVector2f) {700, 500});
    sfView_setCenter(secondary_screen->bloc_1, (sfVector2f) {350, 250});
    return 0;
}

void *init_secondary_screen(list_t *list)
{
    secondary_screen_t *secondary_screen = malloc(sizeof(secondary_screen_t));

    if (!secondary_screen)
        return NULL;
    secondary_screen->prev = NULL;
    secondary_screen->second = NULL;
    secondary_screen->bloc_1 = sfView_create();
    secondary_screen->bloc_2 = sfView_create();
    if (!secondary_screen->bloc_1 || !secondary_screen->bloc_2)
        return NULL;
    return secondary_screen;
}

int init_secondary_screen_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_secondary_screen;
    addon->on_start = start_secondary_screen;
    addon->on_event = NULL;
    addon->on_tick = tick_secondary_screen;
    addon->init = init_secondary_screen;
    addon->on_collision = NULL;
    if (create_addon("secondary_screen", addon, engine) == sfFalse)
        return 84;
    return 0;
}
