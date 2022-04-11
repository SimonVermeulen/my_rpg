/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** init_scenes_path.c
*/

#include "game_engine.h"
#include <dirent.h>
#include "my.h"

char *create_path_by_name(char const *path, char const *name)
{
    int length = my_strlen(path);
    char *new_directory = malloc(sizeof(char) *
        (length + my_strlen(name) + 2));
    int i = length;

    my_strcpy(new_directory, path);
    if (new_directory[length - 1] != '/') {
        new_directory[length] = '/';
        i++;
    }
    for (int o = 0; name[o] != '\0'; o++, i++) {
        new_directory[i] = name[o];
    }
    new_directory[i] = '\0';
    return new_directory;
}

bool init_scenes_path(const char *path, engine_t *engine)
{
    DIR *directory = opendir(path);
    struct dirent *sub;
    char *path_name = NULL;

    if (directory == NULL)
        return false;
    for (int i = 0; (sub = readdir(directory)) != NULL; i++) {
        if (!my_strcmp(sub->d_name, ".") || !my_strcmp(sub->d_name, ".."))
            continue;
        path_name = create_path_by_name(path, sub->d_name);
        if (sub->d_type == DT_DIR)
            init_scenes_path(path_name, engine);
        if (sub->d_type == DT_REG)
            init_scene_path(path_name, sub->d_name, engine);
        free(path_name);
    }
    closedir(directory);
    return true;
}