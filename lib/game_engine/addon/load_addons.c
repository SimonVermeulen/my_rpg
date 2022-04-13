/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** load_addons.c
*/

#include "game_engine.h"

int load_addons(engine_t *engine, int (*const init_addon[])(engine_t *))
{
    for (int i = 0; init_addon[i] != NULL; i++) {
        if ((*init_addon[i])(engine) == 84)
            return 0;
    }
    return 1;
}