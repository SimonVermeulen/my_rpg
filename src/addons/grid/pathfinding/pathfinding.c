/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** pathfinding.c
*/

#include "game.h"

list_t *get_path(engine_t *engine, sfVector2i start, sfVector2i end)
{
    grid_t *grid = get_addon_data("grid", seach_object(engine, "grid"));
    element_t *element = NULL;
    sfVector2i size;
    list_t *path = NULL;

    if (!grid)
        return NULL;
    size = (sfVector2i) {grid->width, grid->height};
    element = calc_trajectory(grid->map, &size, &end,
        create_element(start.x, start.y, NULL));
    if (!element)
        return NULL;
    path = create_empty_list();
    for (int i = 0; element != NULL; i++, element = element->parent) {
        unshift_element(path, create_newnode(element, 4, 0));
    }
    return path;
}