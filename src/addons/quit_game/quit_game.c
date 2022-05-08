/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** quit_game
*/

#include "game.h"

static int enable_addon(object_t *object, engine_t *engine)
{
    return exit_game(engine, 0);
}

int init_quit_game_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = enable_addon;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = enable_addon;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = NULL;
    addon->on_collision = NULL;
    if (create_addon("quit_game", addon, engine) == sfFalse)
        return 84;
    return 0;
}