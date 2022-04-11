/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

typedef struct execute_function_s {
    float time;
    event_functions_t function;
    object_t *object;
} execute_function_t;

sfBool add_function(event_functions_t function, float time, object_t *object,
    engine_t *engine);
int execute_functions(engine_t *engine);
int destroy_functions(engine_t *engine);

#endif