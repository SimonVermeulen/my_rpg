/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** view_controller.c
*/

#include "game.h"

int end_secondary_screen(object_t *object, engine_t *engine);

int window_on_tick(list_t *scene, engine_t *engine);

int loop_track_on_event(list_t *scene, engine_t *engine);

int event_secondary_screen(object_t *object, engine_t *engine)
{
    secondary_screen_t *secondary_screen = get_addon_data("secondary_screen",
        object);

    if (secondary_screen->second)
        return loop_track_on_event(secondary_screen->second->object, engine);
    return 0;
}

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
        window_on_tick(secondary_screen->second->object, engine);
        print_list(engine->print, engine);
    }
    sfRenderWindow_setView(engine->window, secondary_screen->bloc_1);
}

int start_secondary_screen(object_t *object, engine_t *engine)
{
    secondary_screen_t *secondary_screen = get_addon_data("secondary_screen",
        object);

    sfView_setViewport(secondary_screen->bloc_2, (sfFloatRect)
        {0, 0, 1, 0.5f});
    sfView_setSize(secondary_screen->bloc_2, (sfVector2f) {540, 540});
    sfView_setCenter(secondary_screen->bloc_2, (sfVector2f) {270, 270});
    sfView_setViewport(secondary_screen->bloc_1, (sfFloatRect)
        {0, 0.5f, 1, 0.5f});
    sfView_setSize(secondary_screen->bloc_1, (sfVector2f) {540, 540});
    sfView_setCenter(secondary_screen->bloc_1, (sfVector2f) {270, 270});
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
    addon->on_event = event_secondary_screen;
    addon->on_tick = tick_secondary_screen;
    addon->init = init_secondary_screen;
    addon->on_collision = NULL;
    if (create_addon("secondary_screen", addon, engine) == sfFalse)
        return 84;
    return 0;
}
