/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef PRINT_H
    #define PRINT_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

typedef struct print_node_s {
    void *data;
    int type;
    int order;
} print_node_t;

int print_list(engine_t *engine);
sfBool add_print(void *data, int type, int order, engine_t *engine);
int destroy_print_list(engine_t *engine, sfBool final);

#endif