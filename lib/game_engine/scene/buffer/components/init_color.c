/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** init_color.c
*/

#include "game_engine.h"

bool init_color(scene_t *scene, list_t *list)
{
    sfColor *color = malloc(sizeof(sfColor));
    int *r = get_value_list(list, "r", 3);
    int *g = get_value_list(list, "g", 3);
    int *b = get_value_list(list, "b", 3);
    int *a = get_value_list(list, "a", 3);
    char *name = get_value_list(list, "name", 4);

    if (!r || !g || !b || !name || !color)
        return false;
    color->r = *r;
    color->g = *g;
    color->b = *b;
    if (a)
        color->a = *a;
    else
        color->a = 255;
    return (create_add_node(color, COLOR, name, scene->buffer)) ? true : false;
}
