/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** creates and deletes list
*/

#include <stdlib.h>
#include "linked_list.h"

list_t *create_empty_list(void)
{
    list_t *new_list = NULL;

    new_list = malloc(sizeof(list_t));
    if (!new_list)
        return (NULL);
    new_list->nb_elements = 0;
    new_list->head = NULL;

    return (new_list);
}

void free_list(list_t *list)
{
    node_t *current = list->head;
    node_t *tmp = NULL;

    for (int i = 0; i < list->nb_elements; i++) {
        tmp = current->next;
        free_node(current);
        current = tmp;
    }
    free(list);
}
