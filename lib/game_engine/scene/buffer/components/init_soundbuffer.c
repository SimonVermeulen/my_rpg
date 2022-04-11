/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** init_soundbuffer.c
*/

#include "game_engine.h"

bool init_soundbuffer(scene_t *scene, list_t *list)
{
    char *name = get_value_list(list, "name", 4);
    char *path = get_value_list(list, "path", 4);
    sfSoundBuffer *sound = NULL;

    if (!name || !path)
        return false;
    sound = sfSoundBuffer_createFromFile(path);
    if (!sound)
        return false;
    if (create_add_node(sound, SOUNDBUFFER, name, scene->buffer))
        return true;
    return false;
}