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
    init_parallax_addons,
    init_rect_animation_addons,
    init_move_view_addons,
    init_follow_view_addons,
    init_change_scene_addons,
    init_event_manager_addons,
    init_dialogue_manager_addons,
    NULL
};

int main(int argc, char **argv)
{
    engine_t *engine = init_game((sfVideoMode) {800, 1080, 32},
        "[HACK-ROM] Pokemon donjon mystere lihme-line");

    if (!engine || !load_addons(engine, load_addons_func) ||
        !init_scenes_path("./scenes", engine))
        return 84;
    if (!set_const_scene("manager", engine) ||
        !change_scene("intro_0-bot", engine) ||
        !change_secondary_screen("intro_0-top", engine))
        return 84;
    return open_game(engine, 60);
}
