/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** change_scene
*/

#include "game.h"

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "change_scene");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

static int start_addon(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("change_scene", object);
    int *bloc = get_value_list(list, "bloc", 3);
    char *name = get_value_list(list, "name", 4);
    secondary_screen_t *screens = get_secondary_screen_data(engine);

    if (!bloc || !name || !screens || !screens->bloc_1 || !screens->bloc_2)
        return exit_game(engine, 84);
    if (*bloc == 1) {
        sfView_setCenter(screens->bloc_1, (sfVector2f) {270, 270});
        return change_scene(name, engine);
    }
    sfView_setCenter(screens->bloc_2, (sfVector2f) {270, 270});
    return change_secondary_screen(name, engine);
}

static void *init_addon(list_t *list)
{
    return copy_list(list);
}

int init_change_scene_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = start_addon;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = start_addon;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("change_scene", addon, engine) == sfFalse)
        return 84;
    return 0;
}