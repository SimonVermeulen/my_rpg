/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-adil.nouiri
** File description:
** mobs_animation
*/

#include "game.h"

static void *init_mobs_animation(list_t *list)
{
    int *infini = get_value_list(list, "infini", 3);
    double *wait = get_value_list(list, "waitBeforeStart", 2);
    list *enable = get_value_list(list, "enable", 1);
    list *object = get_value_list(list, "object", 1);

    if (!infini || !wait || !enable || !object)
        return (NULL);
    return copy_list(list);
}

int init_mobs_animation_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = NULL;
    addon->on_collision = NULL;
    if (create_addon("mobs_animation", addon, engine) == sfFalse)
        return 84;
    return 0;
}
