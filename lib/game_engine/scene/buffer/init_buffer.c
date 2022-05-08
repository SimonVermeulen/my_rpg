/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** init_buffer.c
*/

#include "game_engine.h"

static bool (*const init_component[])(scene_t *, list_t *) =
{
    init_color,
    init_font,
    init_texture,
    init_soundbuffer,
    init_music
};

bool execute_array_buffer(node_t *node, scene_t *scene,
    bool (*const init)(scene_t *, list_t *))
{
    list_t **array = NULL;

    if (!node || node->type != 10)
        return true;
    array = node->value;
    for (int i = 0; i < node->len; i++) {
        if (!(*init)(scene, array[i]))
            return false;
    }
    return true;
}

bool init_buffer(list_t *buffer, scene_t *scene)
{
    node_t *lists[5] = {
        search_from_key(buffer, "Colors"), search_from_key(buffer, "Fonts"),
        search_from_key(buffer, "Textures"),
        search_from_key(buffer, "SoundBuffers"),
        search_from_key(buffer, "Musics")};

    if (!buffer)
        return true;
    for (int i = 0; i < 5; i++) {
        if (!execute_array_buffer(lists[i], scene, init_component[i]))
            return false;
    }
    return true;
}
