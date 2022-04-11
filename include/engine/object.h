/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef OBJECT_H
    #define OBJECT_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

object_t *create_object(char const *name, list_t *scene, engine_t *engine);
object_t *create_object_list(list_t *list, list_t *scene, engine_t *engine,
    object_t *parent);
int destroy_object(object_t *object);
object_t *seach_object(engine_t *engine, char const *name);
object_t *seek_object_scene(list_t *scene, char const *name);
sfBool set_active(sfBool value, object_t *object, engine_t *engine);
object_t **stock_object(object_t *object);

int on_active(object_t *object, engine_t *engine);

bool init_collision(list_t *list, object_t *object);
bool destroy_collision(object_t *object);
bool check_collision_event(engine_t *engine, list_t *scene);
bool is_hover(engine_t *engine, object_t *object);
collision_t *is_trigger(engine_t *engine, object_t *object);

bool get_collision_rect_circle(collision_t *a, collision_t *b);
bool get_collision_circle(collision_t *a, collision_t *b);
bool get_collision_rect(collision_t *a, collision_t *b);
bool get_collision(collision_t *a, collision_t *b);

#endif