/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** init_music.c
*/

#include "game_engine.h"

bool init_music(scene_t *scene, list_t *list)
{
    char *name = get_value_list(list, "name", 4);
    char *path = get_value_list(list, "path", 4);
    sfMusic *sound = NULL;

    if (!name || !path)
        return false;
    sound = sfMusic_createFromFile(path);
    if (!sound)
        return false;
    if (create_add_node(sound, MUSIC, name, scene->buffer))
        return true;
    return false;
}