/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** texture.c
*/

#include "game_engine.h"

static void (*const set_textures[])(void *, const sfTexture *, sfBool) =
{
    sfCircleShape_setTexture,
    sfSprite_setTexture,
    sfConvexShape_setTexture,
    sfRectangleShape_setTexture,
    NULL,
    NULL
};

bool set_texture(object_t *object, const char *name, sfBool reset_rect)
{
    sfTexture *texture = get_item_buffer(object, TEXTURE, name);

    if (!object->entity || !set_textures[object->entity->type] || !texture)
        return false;
    (*set_textures[object->entity->type])
        (object->entity->data, texture, reset_rect);
    return true;
}

static void (*const set_textures_rect[])(void *, const sfIntRect) =
{
    sfCircleShape_setTextureRect,
    sfSprite_setTextureRect,
    sfConvexShape_setTextureRect,
    sfRectangleShape_setTextureRect,
    NULL,
    NULL
};

bool set_texture_rect(object_t *object, sfIntRect rect)
{
    if (!object->entity || !set_textures[object->entity->type])
        return false;
    (*set_textures_rect[object->entity->type])(object->entity->data, rect);
    return true;
}

bool set_texture_with_rect(object_t *object, const char *name, sfIntRect rect)
{
    if (!set_texture(object, name, false))
        return false;
    return set_texture_rect(object, rect);
}

bool set_rect_by_list(sfIntRect *rect, list_t *list)
{
    int *left = get_value_list(list, "left", 3);
    int *top = get_value_list(list, "top", 3);
    int *width = get_value_list(list, "width", 3);
    int *height = get_value_list(list, "height", 3);

    if (!list || !left || !top || !width || !height)
        return false;
    rect->left = *left;
    rect->top = *top;
    rect->width = *width;
    rect->height = *height;
    return true;
}

bool set_texture_list(object_t *object, list_t *list)
{
    char *name = get_value_list(list, "TextureName", 4);
    sfIntRect rect;

    if (!name || !set_texture(object, name, false))
        return false;
    if (set_rect_by_list(&rect, get_value_list(list, "Rect", 1)))
        return set_texture_rect(object, rect);
    return false;
}