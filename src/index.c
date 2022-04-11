/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** index.c
*/

#include "game.h"

int (*const load_addons_func[])(engine_t *) = {init_example_addons, NULL};

int main(int argc, char **argv)
{
    engine_t *engine = init_game((sfVideoMode) {1920, 1080, 32}, "bonjour");

    load_addons(engine, load_addons_func);
    init_scenes_path("./map", engine);
    if (!change_scene("a", engine))
        return 84;
    return open_game(engine, 60);
}