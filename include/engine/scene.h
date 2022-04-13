/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef SCENE_H
    #define SCENE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

bool init_scenes_path(const char *path, engine_t *engine);
bool init_scene_path(const char *path, const char *name, engine_t *engine);
int change_scene(char const *name, engine_t *engine);
sfBool set_const_scene(char const *name, engine_t *engine);
scene_t *load_scene_by_path(char const *path, engine_t *engine);
list_t *init_objects_list(list_t *object, engine_t *engine, object_t *parent);
scene_t *init_scene_by_list(list_t *scene_list, engine_t *engine);
int destroy_scene(scene_t *scene);
int destroy_objects_list(list_t *scene);

bool init_buffer(list_t *buffer, scene_t *scene);
bool destroy_buffer(list_t *buffer);

void *get_item_buffer(object_t *object, int id, const char *name);

bool init_color(scene_t *scene, list_t *list);
bool init_font(scene_t *scene, list_t *list);
bool init_texture(scene_t *scene, list_t *list);
bool init_soundbuffer(scene_t *scene, list_t *list);
bool init_music(scene_t *scene, list_t *list);

#endif