/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** init_data_entity.c
*/

#include "game_engine.h"

///////
// TYPE LIST
////////////

static const char *parameter_list[] = {
    "Position",
    "Scale",
    "Origin",
    "Texture",
    "Points",
    "Size",
    0
};
static bool (*const function_list[])(object_t *object, list_t *list) = {
    set_position_list,
    set_scale_list,
    set_origin_list,
    set_texture_list,
    set_point_list,
    set_size_list,
    0
};

///////
// TYPE FLOAT
////////////

static const char *parameter_float[] = {
    "Rotation",
    "Radius",
    "LineSpacing",
    "LetterSpacing",
    "Pitch",
    "Volume",
    "MinDistance",
    "Attenuation",
    0
};
static bool (*const function_float[])(object_t *object, float list) = {
    set_rotation,
    set_radius,
    set_line_spacing,
    set_letter_spacing,
    set_pitch,
    set_volume,
    set_min_distance,
    set_attenuation,
    0
};

///////
// TYPE CHAR *
////////////

static const char *parameter_char[] = {
    "FillColor",
    "OutlineColor",
    "OutlineThickness",
    "Color",
    "String",
    "Font",
    "SoundBuffer",
    0
};
static bool (*const function_char[])(object_t *object, char *list) = {
    set_fill_color,
    set_outline_color,
    set_outline_thickness,
    set_color,
    set_string,
    set_font,
    set_buffer,
    0
};

///////
// TYPE INT
////////////

static const char *parameter_int[] = {
    "Anchor",
    "PointCount",
    "CharacterSize",
    "Style",
    "Loop",
    "Relative",
    "PlayingOffset",
    0
};
static bool (*const function_int[])(object_t *object, int list) = {
    set_origin_anchor,
    set_point_count,
    set_character_size,
    set_style,
    set_loop,
    set_relative,
    set_playing_offset,
    0
};

void get_int_parameter(list_t *list, object_t *object)
{
    int *value = NULL;

    for (int i = 0; parameter_int[i] != 0; i++) {
        value = get_value_list(list, parameter_int[i], 3);
        if (!value)
            continue;
        (*function_int[i])(object, *value);
    }
}

void get_float_parameter(list_t *list, object_t *object)
{
    double *value = NULL;

    for (int i = 0; parameter_float[i] != 0; i++) {
        value = get_value_list(list, parameter_float[i], 2);
        if (!value)
            continue;
        (*function_float[i])(object, *value);
    }
}

void init_data_entity(list_t *entity_list, object_t *object)
{
    if (!entity_list)
        return;
    for (int i = 0; parameter_list[i] != 0; i++) {
        (*function_list[i])(object, get_value_list(entity_list,
            parameter_list[i], 1));
    }
    for (int i = 0; parameter_char[i] != 0; i++) {
        (*function_char[i])(object, get_value_list(entity_list,
            parameter_char[i], 4));
    }
    get_float_parameter(entity_list, object);
    get_int_parameter(entity_list, object);
}
