/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** translation_action.c
*/

#include "game.h"

int move_translation_animation(engine_t *engine, sfVector2f normal,
    object_t *object, translation_animation_t *trans)
{
    normal.x = normal.x * trans->speed * (get_delta(engine) / 100);
    normal.y = normal.y * trans->speed * (get_delta(engine) / 100);
    move_vector(object, normal);
    return 0;
}

int tick_translation_animation(object_t *object, engine_t *engine)
{
    translation_animation_t *trans =
        get_addon_data("translation_animation", object);
    node_t *direction = get_node_id(trans->positions, trans->step);
    sfVector2f normal;
    sfVector2f origin = sfSprite_getOrigin(object->entity->data);

    if (!direction)
        return 0;
    trans->count_wait += get_delta(engine);
    if (trans->count_wait < trans->wait)
        return 0;
    normal = get_normalize_vector(get_position(object),
        *((sfVector2f *) (direction->value)));
    if (!equal_vector2f_pov(normal, trans->normal, 0.00001f) &&
        !equal_vector2f(trans->normal, (sfVector2f) {0, 0})) {
        trans->step++;
        trans->normal = (sfVector2f) {0, 0};
    } else
        trans->normal = normal;
    return move_translation_animation(engine, normal, object, trans);
}