/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** index.c
*/

#include "game.h"
#include "my.h"
#include <time.h>

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
    init_text_animation_addons,
    init_select_manager_addons,
    init_position_by_view_addons,
    init_multi_enable_addons,
    init_multi_disable_addons,
    init_play_sound_addons,
    init_player_controller_addons,
    init_pokemons_addons,
    init_pokemons_animation_addons,
    init_interact_zone_addons,
    init_data_addons,
    init_load_data_object_addons,
    init_particle_move_addons,
    init_particle_addons,
    init_grid_controller_addons,
    init_second_ai_addons,
    init_enemy_ai_addons,
    init_mobs_addons,
    init_health_check_addons,
    init_parameter_window_addons,
    init_parameter_fps_addons,
    init_parameter_volume_addons,
    init_save_scene_addons,
    init_load_scene_addons,
    init_pause_addons,
    init_click_pause_addons,
    NULL
};

int usage(int argc, char **argv)
{
    if (argc == 2 && !my_strcmp(argv[1], "-h")) {
        my_printf(stdout, "Welcome to the french version of Pokemon %s",
            "Mystery Dungeon : Explorators of the sky.\n\nThe only journey");
        my_printf(stdout, " game in which you incarnate an actual pokemon.%s",
            "\nThroughout your journey, you will have to face some pokemons");
        my_printf(stdout, " in order to completes your tasks and dungeons.");
        my_printf(stdout, "\n\n%s",
            "To start the game, you will first have to compile it.\nPleas");
        my_printf(stdout, "e type through your shell: make\nNow that the %s",
            "game compiled, please type: ./myrpg\nYour game will launch.");
        my_printf(stdout, "\n\nYou can set your own settings with the menu %s",
            "'Paramètres'.\nUse your keyboard arrows to navigate and 'A' to");
        my_printf(stdout, " interact.\nIn order to begin your journey, %s",
            "please select 'Charger partie'.\nHave fun.\n");
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    engine_t *engine = NULL;

    if (usage(argc, argv))
        return 0;
    engine = init_game((sfVideoMode) {800, 1080, 32},
        "[HACK-ROM] Pokemon donjon mystere lihme-line");
    srand(time(NULL));
    if (!engine || !load_addons(engine, load_addons_func) ||
        !init_scenes_path("./scenes", engine))
        return 84;
    if (!set_const_scene("manager", engine) ||
        !change_scene("map_guild_grodoudou_room", engine) ||
        !change_secondary_screen("intro_0-top", engine))
        return 84;
    return open_game(engine, 60);
}
