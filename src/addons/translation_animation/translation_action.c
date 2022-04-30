/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** translation_action.c
*/

#include "game.h"
#include "my.h"

int move_translation_animation(engine_t *engine, sfVector2f normal,
    object_t *object, float speed)
{
    double delta = (engine->time.delta == 0) ? 0.01 : engine->time.delta;

    normal.x = normal.x * speed * (delta / 100);
    normal.y = normal.y * speed * (delta / 100);
    move_vector(object, normal);
    return 0;
}

int update_reverse_step_translation(translation_animation_t *trans)
{
    if (trans->step == 0)
        trans->is_reverse = 0;
    else
        trans->step--;
    trans->normal = (sfVector2f) {0, 0};
    return 0;
}

static void get_respawn(translation_animation_t *trans,
    object_t *object)
{
    int length = trans->positions->nb_elements;
    vector_speed_t *end = trans->positions->head->prev->value;
    sfVector2f position = get_position(object);
    vector_speed_t *start = trans->positions->head->value;

    position.x =  position.x - end->position.x;
    position.y = position.y - end->position.y;
    position.x = start->position.x + position.x;
    position.y = start->position.y + position.y;
    set_position_float(object, position.x, position.y);
}

int update_step_translation_animation(translation_animation_t *trans,
    object_t *object)
{
    if (trans->is_reverse)
        return update_reverse_step_translation(trans);
    if (trans->step == trans->positions->nb_elements - 1) {
        trans->step++;
        set_active(true, trans->enable, object->engine);
        if (trans->infini) {
            trans->step = 0;
            get_respawn(trans, object);
        }
        if (trans->reverse) {
            trans->step--;
            trans->is_reverse = 1;
        }
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
    vector_speed_t *vector = NULL;
    sfVector2f position;

    if (!direction || !trans->object)
        return 0;
    position = get_position(trans->object);
    trans->count_wait += get_delta(engine);
    if (trans->count_wait < trans->wait)
        return 0;
    vector = direction->value;
    move_translation_animation(engine,
        get_normalize_vector(position,
        vector->position), trans->object, vector->speed);
    if (equal_vector2f_pov(position, vector->position,
        vector->speed / 2))
        return update_step_translation_animation(trans, trans->object);
}
