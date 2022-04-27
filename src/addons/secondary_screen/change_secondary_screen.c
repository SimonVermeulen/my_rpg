/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** change_secondary_screen.c
*/

#include "game.h"

secondary_screen_t *get_secondary_screen_data(engine_t *engine)
{
    object_t *object = seach_object(engine, "secondary_screen");
    secondary_screen_t *secondary_screen = NULL;

    if (!object)
        return NULL;
    secondary_screen = get_addon_data("secondary_screen", object);
    return secondary_screen;
}

bool change_secondary_screen(const char *name, engine_t *engine)
{
    char *current = NULL;
    secondary_screen_t *secondary_screen = get_secondary_screen_data(engine);

    if (engine == NULL || !secondary_screen)
        return sfFalse;
    current = get_value_list(engine->scenes, name, 4);
    if (current == NULL)
        return sfFalse;
    if (secondary_screen->second)
        on_end(secondary_screen->second->object, engine);
    secondary_screen->prev = secondary_screen->second;
    secondary_screen->second = load_scene_by_path(current, engine);
    if (secondary_screen->second == NULL) {
        exit_game(engine, 84);
        return sfFalse;
    }
    on_start(secondary_screen->second->object, engine);
    return sfTrue;
}

int destroy_secondary_screen(object_t *object, engine_t *engine)
{
    secondary_screen_t *view_controller = get_addon_data("secondary_screen",
        object);

    destroy_scene(view_controller->second);
    sfView_destroy(view_controller->bloc_1);
    sfView_destroy(view_controller->bloc_2);
    return 0;
}

int end_secondary_screen(object_t *object, engine_t *engine)
{
    secondary_screen_t *view_controller = get_addon_data("secondary_screen",
        object);

    if (view_controller->prev) {
        destroy_scene(view_controller->prev);
        view_controller->prev = NULL;
    }
    if (view_controller->second)
        on_end(view_controller->second->object, engine);
    add_function(destroy_secondary_screen, 0, object, engine);
    return 0;
}