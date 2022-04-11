/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef GAME_H
    #define GAME_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

engine_t *init_game(sfVideoMode video, char const *title);
int execute_game(list_t *scene, engine_t *engine);
int open_game(engine_t *engine, int fps);
int destroy_game(engine_t *engine);

float get_delta(engine_t *engine);
int set_time(engine_t *engine);
int exit_game(engine_t *engine, int code);

#endif