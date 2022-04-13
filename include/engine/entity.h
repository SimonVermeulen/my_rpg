/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef ENTITY_H
    #define ENTITY_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

bool init_entity(list_t *entity_list, object_t *object);
int print_entity(object_t *object, engine_t *engine);
int add_print_list_entity(object_t *object, list_t *print);
bool destroy_entity(object_t *object);
void init_data_entity(list_t *entity_list, object_t *object);

sfVector2f get_position(object_t *object);
sfFloatRect get_local_bounds(object_t *object);
sfFloatRect get_global_bounds(object_t *object);

bool set_position_vector(object_t *object, sfVector2f position);
bool set_position_float(object_t *object, float x, float y);
bool set_position_list(object_t *object, list_t *list);
bool move_vector(object_t *object, sfVector2f position);
bool move_float(object_t *object, float x, float y);

bool set_rotation(object_t *object, float angle);
bool rotate(object_t *object, float angle);

bool set_scale_vector(object_t *object, sfVector2f scale);
bool set_scale_float(object_t *object, float x, float y);
bool set_scale_list(object_t *object, list_t *list);
bool scale_vector(object_t *object, sfVector2f scale);
bool scale_float(object_t *object, float x, float y);

bool set_origin(object_t *object, sfVector2f origin);
bool set_origin_list(object_t *object, list_t *list);

///////
// ANCHOR TYPE
///////

    #define TOP_LEFT 0
    #define TOP 1
    #define TOP_RIGHT 2
    #define LEFT 3
    #define MIDDLE 4
    #define RIGHT 5
    #define BOTTOM_LEFT 6
    #define BOTTOM 7
    #define BOTTOM_RIGHT 8

bool set_origin_anchor(object_t *object, int type);

bool set_texture(object_t *object, const char *name, sfBool reset_rect);
bool set_texture_with_rect(object_t *object, const char *name, sfIntRect rect);
bool set_texture_rect(object_t *object, sfIntRect rect);
bool set_texture_list(object_t *object, list_t *list);

bool set_fill_color(object_t *object, const char *name);
bool set_outline_color(object_t *object, const char *name);
bool set_outline_thickness(object_t *object, const char *name);
bool set_color(object_t *object, const char *name);

bool set_radius(object_t *object, float radius);
bool set_point_count(object_t *object, size_t count);
bool set_point(object_t *object, size_t index, sfVector2f point);
bool set_point_list(object_t *object, list_t *list);
bool set_size(object_t *object, sfVector2f size);
bool set_size_list(object_t *object, list_t *list);

bool set_string(object_t *object, const char *string);
bool set_font(object_t *object, const char *name);
bool set_character_size(object_t *object, unsigned int size);
bool set_line_spacing(object_t *object, float spacing);
bool set_letter_spacing(object_t *object, float spacing);
bool set_style(object_t *object, sfUint32 style);

bool set_buffer(object_t *object, const char *name);
bool set_loop(object_t *object, sfBool loop);
bool set_pitch(object_t *object, float pitch);
bool set_volume(object_t *object, float volume);
bool set_relative(object_t *object, sfBool relative);
bool set_min_distance(object_t *object, float distance);
bool set_attenuation(object_t *object, float attenuation);
bool set_playing_offset(object_t *object, sfInt64 microseconds);

bool play_sound(object_t *object);
bool stop_sound(object_t *object);
bool pause_sound(object_t *object);

#endif