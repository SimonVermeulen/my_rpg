/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** index.c
*/

#include "game.h"

int (*const load_addons_func[])(engine_t *) =
{
    init_secondary_screen_addons,
    init_translation_animation_addons,
    init_set_position_addons,
    NULL
};

int main(int argc, char **argv)
{
    engine_t *engine = init_game((sfVideoMode) {700, 1080, 32},
        "[HACK ROM] Pokemon dunjeon mystery");

    if (!engine || !load_addons(engine, load_addons_func) ||
        !init_scenes_path("./map", engine))
        return 84;
    if (!set_const_scene("manager", engine) ||
        !change_scene("intro_1-bot", engine) ||
        !change_secondary_screen("intro_1-top", engine))
        return 84;
    return open_game(engine, 60);
}