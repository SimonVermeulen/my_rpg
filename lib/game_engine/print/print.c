/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** print.c
*/

#include "game_engine.h"

void switch_element_sort_print(node_t *i, node_t *j)
{
    entity_t *temp_a = i->value;
    entity_t *temp_b = j->value;

    if (temp_a->order < temp_b->order) {
        i->value = temp_b;
        j->value = temp_a;
    }
}

void make_bubble_sort_print(list_t *stack)
{
    node_t *traveler_a = stack->head;
    node_t *traveler_b = stack->head;

    for (int i = 0; i < stack->nb_elements;
        i++, traveler_a = traveler_a->next) {
        for (int j = 0; j < stack->nb_elements; j++, traveler_b =
            traveler_b->next)
            switch_element_sort_print(traveler_a, traveler_b);
        traveler_b = stack->head;
    }
}

static void (*const print_entities[])(sfRenderWindow *, const void *,
    const sfRenderStates *) =
{
    sfRenderWindow_drawCircleShape,
    sfRenderWindow_drawSprite,
    sfRenderWindow_drawConvexShape,
    sfRenderWindow_drawRectangleShape,
    sfRenderWindow_drawText
};

int print_list(list_t *print, engine_t *engine)
{
    node_t *current = NULL;
    entity_t *entity = NULL;

    make_bubble_sort_print(print);
    current = print->head;
    for (int i = 0; i < print->nb_elements; i++,
        current = current->next) {
        entity = current->value;
        if (entity->type >= 5)
            continue;
        (*print_entities[entity->type])(engine->window, entity->data, NULL);
    }
    return destroy_print_list(engine, sfFalse);
}

int destroy_print_list(engine_t *engine, sfBool final)
{
    if (engine == NULL)
        return ERROR;
    while (engine->print->nb_elements != 0) {
        engine->print->head->value = NULL;
        engine->print->head->type = 0;
        shift_element(engine->print);
    }
    if (final == sfTrue)
        free(engine->print);
    return 0;
}
