/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** translation_animation.c
*/

#include "game.h"

int tick_translation_animation(object_t *object, engine_t *engine);

int end_translation_animation(object_t *object, engine_t *engine)
{
    translation_animation_t *translation =
        get_addon_data("translation_animation", object);
    
    free_json_object(translation->positions);
    return 0;
}

list_t *create_list_positions(list_t **positions, int length)
{
    sfVector2f *position = NULL;
    list_t *positions_final = create_empty_list();
    node_t *node = NULL;

    if (!positions_final)
        return NULL;
    for (int i = 0; i < length; i++) {
        position = malloc_vector2f_list(positions[i]);
        if (!position)
            return NULL;
        node = create_add_node(position, 0, "path", positions_final);
        if (!node)
            return NULL;
    }
    return positions_final;
}

void *init_translation_animation(list_t *list)
{
    double *speed = get_value_list(list, "speed", 2);
    double *wait = get_value_list(list, "waitBeforeStart", 2);
    node_t *positions = search_from_key(list, "paths");
    translation_animation_t *translation = NULL;

    if (!speed || !wait || !positions || positions->type != 10)
        return NULL;
    translation = malloc(sizeof(translation_animation_t));
    if (!translation)
        return NULL;
    translation->step = 0;
    translation->count_wait = 0;
    translation->speed = *speed;
    translation->wait = *wait;
    translation->normal = (sfVector2f) {0, 0};
    translation->positions = create_list_positions(positions->value,
        positions->len);
    if (!translation->positions)
        return NULL;
    return translation;
}

int init_translation_animation_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_translation_animation;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_translation_animation;
    addon->init = init_translation_animation;
    addon->on_collision = NULL;
    if (create_addon("translation_animation", addon, engine) == sfFalse)
        return 84;
    return 0;
}
