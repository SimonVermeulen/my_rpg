/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** translation_action.c
*/

#include "game.h"

int move_translation_animation(engine_t *engine, sfVector2f normal,
    object_t *object, float speed)
{
    normal.x = normal.x * speed * (get_delta(engine) / 100);
    normal.y = normal.y * speed * (get_delta(engine) / 100);
    move_vector(object, normal);
    return 0;
}

int update_step_translation_animation(translation_animation_t *trans,
    vector_speed_t *vector, object_t *object)
{
    if (trans->is_reverse) {
        if (trans->step == 0)
            trans->is_reverse = 0;
        trans->step--;
        return 0;
    }
    if (trans->step == trans->positions->nb_elements - 1) {
        if (trans->infini) {
            trans->step = 0;
            set_position_vector(object, vector->position);
        }
        if (trans->reverse)
            trans->is_reverse = 1;
        return 0;
    }
    trans->step++;
    return 0;
}

int tick_translation_animation(object_t *object, engine_t *engine)
{
    translation_animation_t *trans =
        get_addon_data("translation_animation", object);
    node_t *direction = get_node_id(trans->positions, trans->step);
    sfVector2f normal;
    sfVector2f origin = sfSprite_getOrigin(object->entity->data);
    vector_speed_t *vector = NULL;

    if (!direction)
        return 0;
    trans->count_wait += get_delta(engine);
    if (trans->count_wait < trans->wait)
        return 0;
    vector = direction->value;
    normal = get_normalize_vector(get_position(object), vector->position);
    if (!equal_vector2f_pov(normal, trans->normal, 0.00001f) &&
        !equal_vector2f(trans->normal, (sfVector2f) {0, 0})) {
        update_step_translation_animation(trans, vector, object);
        trans->normal = (sfVector2f) {0, 0};
    } else
        trans->normal = normal;
    return move_translation_animation(engine, normal, object, vector->speed);
}