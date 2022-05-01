/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** tick
*/

#include "game.h"

int tick_pokemon_anim(object_t *object, engine_t *engine)
{
    pokemon_anim_t *pok = get_addon_data("pokemons_animation", object);
    sfIntRect rect = sfSprite_getTextureRect(pok->object->entity->data);
    sfFloatRect bounds = get_global_bounds(pok->object);
    
    pok->wait -= (pok->wait > 0) ? get_delta(engine) : 0;
    if (pok->wait > 0 || pok->time == -500)
        return 0;
    pok->count -= (pok->count > 0) ? get_delta(engine) : 0;
    if (pok->count > 0)
        return 0;
    rect.left = (rect.left == pok->bounds.width - pok->size) ? 0 :
        rect.left + pok->size;
    if (rect.left == 0 && pok->infini)
        pok->time = -500;
    pok->count = pok->time;
    set_texture_rect(pok->object, rect);
}