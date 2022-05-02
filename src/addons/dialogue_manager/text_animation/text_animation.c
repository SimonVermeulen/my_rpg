/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** text_animation
*/

#include "game.h"
#include "my.h"

int event_text_animation(object_t *object, engine_t *engine);

static int tick_addon(object_t *object, engine_t *engine)
{
    text_animation_t *animation = get_addon_data("text_animation", object);
    int new_count = animation->time / animation->prize;
    int i = 0;

    animation->time -= new_count * animation->prize;
    animation->time += (animation->time < 10 * 7) ? get_delta(engine) : 0;
    for (i = animation->count; i <= (animation->count + new_count) &&
        animation->string[i] != 0; i++)
        animation->string_display[i] = animation->string[i];
    set_string(object, animation->string_display);
    animation->count = i;
    if (animation->count >= my_strlen(animation->string) &&
        animation->prize != 0)
        set_active(true, seek_object_scene(object->childs,
            get_value_list(animation->data, "cursor", 4)), engine);
}

static void *init_addon(list_t *list)
{
    text_animation_t *animation = NULL;
    double *time = get_value_list(list, "time", 2);
    char *string = get_value_list(list, "string", 4);

    if (!time || !string)
        return NULL;
    animation = malloc(sizeof(text_animation_t));
    if (!animation)
        return NULL;
    animation->data = copy_list(list);
    if (!animation->data)
        return NULL;
    animation->count = 0;
    animation->prize = *time / my_strlen(string);
    animation->time = 0;
    animation->string = get_value_list(animation->data, "string", 4);
    animation->string_display = my_strdup(animation->string);
    for (int i = 0; animation->string[i] != 0; i++)
        animation->string_display[i] = 0;
    return animation;
}

static int disable_addon(object_t *object, engine_t *engine)
{
    text_animation_t *animation = get_addon_data("text_animation", object);

    animation->count = 0;
    animation->time = 0;
    for (int i = 0; animation->string[i] != 0; i++)
        animation->string_display[i] = 0;
}

static int end_addon(object_t *object, engine_t *engine)
{
    text_animation_t *animation = get_addon_data("text_animation", object);

    free_json_object(animation->data);
    free(animation->string_display);
}

int init_text_animation_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = disable_addon;
    addon->on_end = end_addon;
    addon->on_start = NULL;
    addon->on_event = event_text_animation;
    addon->on_tick = tick_addon;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("text_animation", addon, engine) == sfFalse)
        return 84;
    return 0;
}