/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** tick
*/

#include "game.h"

static int set_size_anim(pokemon_anim_t *pok, list_t *anim,
    object_t *objecta)
{
    int *width = get_value_list(anim, "width", 3);
    int *height = get_value_list(anim, "height", 3);

    pok->width  = (width) ? *width : 0;
    pok->height = (height) ? *height : 0;
    set_texture_rect(objecta, (sfIntRect) {0, (pok->row - 1) * pok->height,
        pok->width, pok->height});
    set_scale_vector(objecta, pok->scale);
    set_position_vector(objecta, pok->position);
}

static int start_addons(object_t *object, engine_t *engine)
{
    pokemon_anim_t *pok = get_addon_data("pokemons_animation", object);
    object_t *objecta = seek_object_scene(object->actual_scene,
        pok->object_name);
    list_t *pokemon = get_addon_data("pokemons", objecta);
    list_t *anim_pok = get_value_list(pokemon, "animations", 1);
    list_t *anim = get_value_list(anim_pok, pok->animation, 1);

    if (!objecta || !pokemon || !anim_pok || !anim || !objecta->entity)
        return exit_game(engine, 84);
    pok->object = objecta;
    set_texture(objecta, get_value_list(anim, "texture", 4), false);
    pok->bounds = get_local_bounds(objecta);
    set_size_anim(pok, anim, objecta);
    pok->count = pok->time;
}

static int tick_addon(object_t *object, engine_t *engine,
    pokemon_anim_t *pok)
{
    sfIntRect rect = sfSprite_getTextureRect(pok->object->entity->data);

    pok->wait -= (pok->wait > 0) ? get_delta(engine) : 0;
    if (pok->wait > 0 || pok->time == -500 || pok->nb_rep < 0)
        return 0;
    pok->count -= (pok->count > 0) ? get_delta(engine) : 0;
    if (pok->count > 0)
        return 0;
    rect.left = (rect.left >= pok->bounds.width - pok->width) ? 0 :
        rect.left + pok->width;
    if (rect.left == 0 && (!pok->infini && !pok->nb_rep))
        pok->time = -500;
    pok->count = pok->time;
    pok->nb_rep -= (rect.left >= pok->bounds.width - pok->width) ? 1 : 0;
    set_texture_rect(pok->object, rect);
}

int tick_pokemon_anim(object_t *object, engine_t *engine)
{
    pokemon_anim_t *pok = get_addon_data("pokemons_animation", object);
    
    if (pok->init) {
        tick_addon(object, engine, pok);
    } else {
        start_addons(object, engine);
        pok->init = true;
    }
}
