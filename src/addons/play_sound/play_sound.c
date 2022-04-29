/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** play_music
*/

#include "game.h"

static int disable_addons(object_t *object, engine_t *engine)
{
    pause_sound(object);
}

static int end_addons(object_t *object, engine_t *engine)
{
    stop_sound(object);
}

static int start_addons(object_t *object, engine_t *engine)
{
    play_sound(object);
}

int init_play_sound_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = start_addons;
    addon->on_disable = disable_addons;
    addon->on_end = end_addons;
    addon->on_start = start_addons;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = NULL;
    addon->on_collision = NULL;
    if (create_addon("play_sound", addon, engine) == sfFalse)
        return 84;
    return 0;
}