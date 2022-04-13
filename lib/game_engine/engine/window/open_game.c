/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** open_game.c
*/

#include "game_engine.h"

int window_on_tick(list_t *scene, engine_t *engine);

int window_on_event(list_t *scene, engine_t *engine);

int execute_game(list_t *scene, engine_t *engine)
{
    int (*event[])(list_t *, engine_t *) = {window_on_event, window_on_tick,
        NULL};

    for (int i = 0; event[i] != NULL; i++) {
        (*event[i])(scene, engine);
    }
    return 0;
}

int core_game(engine_t *engine)
{
    execute_functions(engine);
    if (engine->prev_scene != NULL) {
        destroy_scene(engine->prev_scene);
        engine->prev_scene = NULL;
    }
    if (engine->const_scene) {
        execute_game(engine->const_scene->object, engine);
        check_collision_event(engine, engine->const_scene->object);
    }
    if (engine->actual_scene) {
        execute_game(engine->actual_scene->object, engine);
        check_collision_event(engine, engine->actual_scene->object);
    }
    print_list(engine->print, engine);
    return 0;
}

int execute_end_event(engine_t *engine)
{
    if (engine->actual_scene)
        on_end(engine->actual_scene->object, engine);
    if (engine->const_scene)
        on_end(engine->const_scene->object, engine);
    execute_functions(engine);
}

int open_game(engine_t *engine, int fps)
{
    int code = 0;

    if (engine == NULL || set_time(engine) == 84)
        return ERROR;
    sfRenderWindow_setView(engine->window, engine->view);
    sfRenderWindow_setFramerateLimit(engine->window, fps);
    while (sfRenderWindow_isOpen(engine->window)) {
        sfRenderWindow_clear(engine->window, sfBlack);
        core_game(engine);
        sfClock_restart(engine->time.delta);
        sfRenderWindow_display(engine->window);
    }
    execute_end_event(engine);
    sfClock_destroy(engine->time.delta);
    sfClock_destroy(engine->time.time);
    code = engine->code;
    destroy_game(engine);
    return code;
}
