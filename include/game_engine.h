/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** game_engine.h
*/

#ifndef GAME_ENGINE_H
    #define GAME_ENGINE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "linked_list.h"
    #include "json_parser.h"

////////////////////////////////////////////////////////////
//
//                 INIT GLOBAL PARAMETER
//
////////////////////////////////////////////////////////////

    #define ERROR 84

///////
// TIME
///////

typedef struct times_s {
    sfClock *delta_time;
    sfClock *time;
    double delta;
} times_t;

///////
// SCENE
///////

typedef struct scene_s {
    list_t *object;
    list_t *buffer;
} scene_t;

///////
// ENGINE
///////

typedef struct engine_s {
    list_t *buffer;
    list_t *scenes;
    scene_t *actual_scene;
    scene_t *prev_scene;
    scene_t *const_scene;
    sfRenderWindow *window;
    sfEvent event;
    list_t *print;
    sfView *view;
    list_t *addons;
    times_t time;
    list_t *functions;
    int code;
} engine_t;

///////
// ENTITY
///////

    #define CIRCLESHAPE 0
    #define SPRITE 1
    #define CONVEXSHAPE 2
    #define RECTANGLESHAPE 3
    #define TEXT 4
    #define SOUND 5

typedef struct entity_s {
    int type;
    void *data;
    int order;
} entity_t;

///////
// BUFFER
///////

    #define COLOR 0
    #define FONT 1
    #define TEXTURE 2
    #define SOUNDBUFFER 3
    #define MUSIC 4

///////
// OBJECT
///////

typedef struct object_s {
    sfBool is_pause;
    sfBool is_active;
    list_t *addons;
    list_t *addons_data;
    entity_t *entity;
    list_t *actual_scene;
    const char *name;
    list_t *childs;
    struct object_s *parent;
    engine_t *engine;
    struct collision {
        sfVector2f last_position;
        list_t *collisions;
    } collision;
} object_t;

///////
// COLLISION
///////

    #define BOX 0
    #define CIRCLE 1

typedef struct collision_s {
    sfBool trigger;
    object_t *object;
    int type;
    sfFloatRect box;
    struct circle {
        sfVector2f point;
        float radius;
    } circle;
} collision_t;

///////
// ADDON
///////

typedef int (*event_functions_t) (object_t *, engine_t *);
typedef int (*event_collisions_t) (collision_t *, collision_t *, engine_t *);
typedef void *(*init_addon_t) (list_t *);

typedef struct addon_s {
    void *data;
    event_functions_t on_tick;
    event_functions_t on_event;
    event_functions_t on_enable;
    event_functions_t on_disable;
    event_functions_t on_start;
    event_functions_t on_end;
    event_collisions_t on_collision;
    init_addon_t init;
} addon_t;

////////////////////////////////////////////////////////////
//
//                      INIT HEADERS
//
////////////////////////////////////////////////////////////

    #include "engine/addon.h"
    #include "engine/entity.h"
    #include "engine/functions.h"
    #include "engine/game.h"
    #include "engine/object.h"
    #include "engine/print.h"
    #include "engine/scene.h"
    #include "engine/event.h"
    #include "engine/utils.h"

#endif
