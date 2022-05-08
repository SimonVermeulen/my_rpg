/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** parameter_window
*/

#include "game.h"

static int enable_addon(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("parameter_window", object);
    int *number = get_value_list(list, "number", 3);
    secondary_screen_t *second = get_secondary_screen_data(engine);

    if (!number)
        return exit_game(engine, 84);
    if (*number == 1) {
        sfView_setViewport(second->bloc_2, (sfFloatRect)
            {0, 0, 0.5f, 1});
        sfView_setViewport(second->bloc_1, (sfFloatRect)
        {0.5f, 0, 0.5f, 1});
        sfRenderWindow_setSize(engine->window, (sfVector2u) {1920, 1080});
    } else {
        sfView_setViewport(second->bloc_2, (sfFloatRect)
        {0, 0, 1, 0.5f});
        sfView_setViewport(second->bloc_1, (sfFloatRect)
        {0, 0.5f, 1, 0.5f});
        sfRenderWindow_setSize(engine->window, (sfVector2u) {800, 1080});
    }
}

static void *init_addon(list_t *list)
{
    return copy_list(list);
}

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "parameter_window");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

int init_parameter_window_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = enable_addon;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = enable_addon;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("parameter_window", addon, engine) == sfFalse)
        return 84;
    return 0;
}
