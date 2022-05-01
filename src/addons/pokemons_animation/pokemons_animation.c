/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-adil.nouiri
** File description:
** pokemons_animation
*/

#include "game.h"
#include "my.h"

int tick_pokemon_anim(object_t *object, engine_t *engine);

static int write_data(pokemon_anim_t *animation, list_t *list)
{
    double *wait = get_value_list(list, "waitbeforestart", 2);
    char *name = get_value_list(list, "animation", 4);
    char *enable = get_value_list(list, "enable", 4);
    int *infini = get_value_list(list, "infini", 3);
    double *time = get_value_list(list, "time", 2);
    char *object_name = get_value_list(list, "object", 4);

    if (!wait || !name || !enable || !infini || !time || !object_name)
        return (false);
    animation->size = animation->row = 0;
    animation->object_name = my_strdup(object_name);
    animation->animation = my_strdup(name);
    animation->infini = *infini;
    animation->enable = my_strdup(enable);
    animation->wait = *wait;
    animation->time = *time;
    return (true);
}

static int start_addons(object_t *object, engine_t *engine)
{
    pokemon_anim_t *pok = get_addon_data("pokemons_animation", object);
    object_t *objecta = seek_object_scene(object->actual_scene,
        pok->object_name);
    list_t *pokemon = get_addon_data("pokemons", objecta);
    list_t *anim_pok = get_value_list(pokemon, "animations", 1);
    list_t *anim = get_value_list(anim_pok, pok->animation, 1);
    int *value = NULL;

    if (!objecta || !pokemon || !anim_pok || !anim || !objecta->entity)
        return exit_game(engine, 84);
    pok->object = objecta;
    set_texture(objecta, get_value_list(anim, "texture", 4), false);
    pok->bounds = get_local_bounds(objecta);
    printf("%f, %f\n", pok->bounds.height, pok->bounds.width);
    value = get_value_list(anim, "size", 3);
    pok->size = (value) ? *value : 0;
    value = get_value_list(anim, "row", 3);
    pok->row = (value) ? *value : 0;
    set_texture_rect(objecta, (sfIntRect) {0, pok->row, pok->size,
        pok->size});
    pok->count = pok->time;
}

static void *init_addon(list_t *list)
{
    pokemon_anim_t *animation = NULL;

    animation = malloc(sizeof(pokemon_anim_t));
    if (!animation || !write_data(animation, list))
        return (NULL);
    return (animation);
}

static int end_addon(object_t *object, engine_t *engine)
{
    pokemon_anim_t *pok = get_addon_data("pokemons_animation", object);

    free(pok->animation);
    free(pok->enable);
    free(pok->object_name);
}

int init_pokemons_animation_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = end_addon;
    addon->on_start = start_addons;
    addon->on_event = NULL;
    addon->on_tick = tick_pokemon_anim;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("pokemons_animation", addon, engine) == sfFalse)
        return 84;
    return 0;
}
