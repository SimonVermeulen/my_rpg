/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** init_texture.c
*/

#include "game_engine.h"

bool init_texture(scene_t *scene, list_t *list)
{
    char *name = get_value_list(list, "name", 4);
    int *smooth = get_value_list(list, "smooth", 3);
    int *repeat = get_value_list(list, "repeat", 3);
    char *path = get_value_list(list, "path", 4);
    sfTexture *texture = NULL;

    if (!path || !name)
        return false;
    texture = sfTexture_createFromFile(path, NULL);
    if (!texture)
        return false;
    if (smooth)
        sfTexture_setSmooth(texture, (*smooth <= 0) ? sfFalse : sfTrue);
    if (repeat)
        sfTexture_setRepeated(texture, (*repeat <= 0) ? sfFalse : sfTrue);
    return (create_add_node(texture, TEXTURE, name, scene->buffer)) ? true :
        false;
}
