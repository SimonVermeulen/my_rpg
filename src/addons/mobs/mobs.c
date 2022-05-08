/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** mobs.c
*/

#include "game.h"

static int tick_addons(object_t *object, engine_t *engine)
{
    mobs_t *mob = get_addon_data("mobs", object);

    if (mob->life <= 0)
        add_function(destroy_object, 0, object, engine);
}

static void *init_addons(list_t *list)
{
    mobs_t *mob = malloc(sizeof(mobs_t));
    double *life = get_value_list(list, "life", 2);
    double *damage = get_value_list(list, "damage", 2);

    if (!mob || !life || !damage)
        return NULL;
    mob->life = *life;
    mob->damage = *damage;
    return mob;
}

int init_mobs_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_addons;
    addon->init = init_addons;
    addon->on_collision = NULL;
    if (create_addon("mobs", addon, engine) == sfFalse)
        return 84;
    return 0;
}
