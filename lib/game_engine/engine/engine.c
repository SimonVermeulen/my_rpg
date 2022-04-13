/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** engine.c
*/

#include "game_engine.h"

int check_init_game(engine_t *instance)
{
    if (instance->scenes == NULL || instance->addons == NULL ||
        instance->functions == NULL || instance->view == NULL ||
        instance->window == NULL)
        return 84;
    return 0;
}

engine_t *init_game(sfVideoMode video, char const *title)
{
    engine_t *instance = malloc(sizeof(engine_t));

    if (instance == NULL)
        return NULL;
    instance->code = 0;
    instance->scenes = create_empty_list();
    instance->addons = create_empty_list();
    instance->print = create_empty_list();
    instance->functions = create_empty_list();
    instance->view = sfView_create();
    instance->window = sfRenderWindow_create(video, title,
        sfClose | sfResize, NULL);
    instance->actual_scene = NULL;
    instance->const_scene = NULL;
    instance->prev_scene = NULL;
    if (check_init_game(instance) == 84)
        return NULL;
    return instance;
}

void destroy_engine(engine_t *engine)
{
    destroy_print_list(engine, true);
    destroy_scene(engine->actual_scene);
    destroy_scene(engine->const_scene);
    destroy_addons(engine->addons, sfFalse);
    destroy_functions(engine);
    sfRenderWindow_destroy(engine->window);
    sfView_destroy(engine->view);
}

int destroy_game(engine_t *engine)
{
    if (engine == NULL)
        return ERROR;
    while (engine->scenes->nb_elements != 0) {
        shift_element(engine->scenes);
    }
    free(engine->scenes);
    destroy_engine(engine);
    free(engine);
    return 0;
}

int exit_game(engine_t *engine, int code)
{
    engine->code = code;
    sfRenderWindow_close(engine->window);
    return code;
}
