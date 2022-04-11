/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** init_font.c
*/

#include "game_engine.h"

bool init_font(scene_t *scene, list_t *list)
{
    sfFont *font = NULL;
    char *name = get_value_list(list, "name", 4);
    char *path = get_value_list(list, "path", 4);

    if (!name || !path)
        return false;
    font = sfFont_createFromFile(path);
    if (!font)
        return false;
    return (create_add_node(font, FONT, name, scene->buffer)) ? true : false;
}