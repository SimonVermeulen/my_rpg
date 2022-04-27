/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** style.c
*/

#include "game_engine.h"

static void (*const set_fonts[])(void *, const sfFont *) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    sfText_setFont,
    NULL
};

bool set_font(object_t *object, const char *name)
{
    sfFont *font = get_item_buffer(object, FONT, name);

    if (!object->entity || !set_fonts[object->entity->type] || !font)
        return false;
    (*set_fonts[object->entity->type])(object->entity->data, font);
    return true;
}

static void (*const set_character_sizes[])(void *, unsigned int) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    sfText_setCharacterSize,
    NULL
};

bool set_character_size(object_t *object, unsigned int size)
{
    if (!object->entity || !set_character_sizes[object->entity->type])
        return false;
    (*set_character_sizes[object->entity->type])(object->entity->data, size);
    return true;
}

static void (*const set_line_spacings[])(void *, float) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    sfText_setLineSpacing,
    NULL
};

bool set_line_spacing(object_t *object, float spacing)
{
    if (!object->entity || !set_line_spacings[object->entity->type])
        return false;
    (*set_line_spacings[object->entity->type])(object->entity->data, spacing);
    return true;
}

static void (*const set_letter_spacings[])(void *, float) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    sfText_setLetterSpacing,
    NULL
};

bool set_letter_spacing(object_t *object, float spacing)
{
    if (!object->entity || !set_letter_spacings[object->entity->type])
        return false;
    (*set_letter_spacings[object->entity->type])(object->entity->data, spacing);
    return true;
}

static void (*const set_styles[])(void *, sfUint32) =
{
    NULL,
    NULL,
    NULL,
    NULL,
    sfText_setStyle,
    NULL
};

bool set_style(object_t *object, sfUint32 style)
{
    if (!object->entity || !set_styles[object->entity->type])
        return false;
    (*set_styles[object->entity->type])(object->entity->data, style);
    return true;
}