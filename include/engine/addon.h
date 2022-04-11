/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef ADDON_H
    #define ADDON_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

void *get_addon_data(char const *name, object_t *object);
sfBool create_addon(char const *name, addon_t *addon, engine_t *engine);
sfBool add_addon(char const *name, object_t *object, engine_t *engine,
    list_t *data);
sfBool destroy_addons(list_t *addon, sfBool boolean);

int load_addons(engine_t *engine, int (*const init_addon[])(engine_t *));

int on_end(list_t *scene, engine_t *engine);
int on_start(list_t *scene, engine_t *engine);

#endif