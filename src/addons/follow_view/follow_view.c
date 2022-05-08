/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** follow_view
*/

#include "game.h"

static int check_limit(list_t *list, sfVector2f pos)
{
    list_t *list_a = get_value_list(list, "a", 1);
    list_t *list_b = get_value_list(list, "b", 1);
    sfVector2f a = create_vector2f_list(list_a);
    sfVector2f b = create_vector2f_list(list_b);

    if (!list_a || !list_b)
        return true;
    if (a.x >= pos.x - 270 || a.y >= pos.y - 270 || b.x <= pos.x + 270 ||
        b.y <= pos.y + 270)
        return false;
    return true;
}

static int tick_addon(object_t *object, engine_t *engine)
{
    list_t *list = get_addon_data("follow_view", object);
    object_t *object_follow = seek_object_scene(object->actual_scene,
        get_value_list(list, "object", 4));
    int *bloc = get_value_list(list, "bloc", 3);
    secondary_screen_t *secondary_screen = get_secondary_screen_data(engine);

    if (!bloc)
        return exit_game(engine, 84);
    if (!object_follow)
        object_follow = object;
    if (*bloc == 1 && check_limit(list, get_position(object_follow)))
        sfView_setCenter(secondary_screen->bloc_1,
            get_position(object_follow));
    if (*bloc == 2 && check_limit(list, get_position(object_follow)))
        sfView_setCenter(secondary_screen->bloc_2,
            get_position(object_follow));
    return 0;
}

static void *init_addon(list_t *list)
{
    return copy_list(list);
}

static int end_addon(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "follow_view");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

int init_follow_view_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_addon;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("follow_view", addon, engine) == sfFalse)
        return 84;
    return 0;
}
