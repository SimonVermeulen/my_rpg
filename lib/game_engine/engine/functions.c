/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** functions.c
*/

#include "game_engine.h"

sfBool add_function(event_functions_t function, float time, object_t *object,
    engine_t *engine)
{
    execute_function_t *execute = malloc(sizeof(execute_function_t));
    node_t *node = malloc(sizeof(node_t));

    if (execute == NULL || node == NULL || engine == NULL || object == NULL ||
        function == NULL)
        return sfFalse;
    node->len = 0;
    execute->function = function;
    execute->time = time;
    execute->object = object;
    node->value = execute;
    push_element(engine->functions, node);
    return sfTrue;
}

int execute_functions(engine_t *engine)
{
    node_t *node = NULL;
    execute_function_t *execute = NULL;

    if (engine == NULL)
        return ERROR;
    node = engine->functions->head;
    for (int i = 0; i < engine->functions->nb_elements;) {
        execute = node->value;
        execute->time -= get_delta(engine);
        if (execute->time <= 0) {
            execute->function(execute->object, engine);
            node->key = NULL;
            node = node->next;
            splice(engine->functions, i);
            continue;
        }
        node = node->next;
        i++;
    }
    return 0;
}

int destroy_functions(engine_t *engine)
{
    node_t *node = NULL;

    if (engine == NULL)
        return ERROR;
    while (engine->functions->nb_elements != 0) {
        node = engine->functions->head;
        node->key = NULL;
        shift_element(engine->functions);
    }
    free(engine->functions);
    return 0;
}
