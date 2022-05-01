/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-adil.nouiri
** File description:
** pokemons_animation
*/

#include "game.h"
#include "my.h"

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
    animation->width = animation->row = animation->height = 0;
    animation->object_name = my_strdup(object_name);
    animation->animation = my_strdup(name);
    animation->infini = *infini;
    animation->enable = my_strdup(enable);
    animation->wait = *wait;
    animation->time = *time;
    animation->texture = NULL;
    animation->object = NULL;
    return (true);
}

static int start_addons(object_t *object, engine_t *engine)
{
    pokemon_anim_t *pok = get_addon_data("pokemons_animation", object);
    object_t *objecta = seek_object_scene(object->actual_scene,
        pok->object_name);
    list_t *last_values = NULL;
    node_t *anim = NULL;
    char *name = NULL;

    pok->object = (objecta) ? objecta : object;
    anim = search_from_key(get_addon_data("pokemons", pok->object),
        "animations");
    for (int i = 0; i < anim->len && !last_values; i++) {
        name = get_value_list(((list_t **)anim->value)[i], "name", 4);
        if (name && !my_strcmp(pok->animation, name))
            last_values = ((list_t **)anim->value)[i];
    }
    pok->row = *(int *)search_from_key(last_values, "row")->value;
    pok->width = *(int *)search_from_key(last_values, "width")->value;
    pok->height = *(int *)search_from_key(last_values, "height")->value;
    pok->texture = search_from_key(last_values, "texture")->value;
    if (!pok->row || !pok->texture || !pok->width || !pok->height)
        return exit_game(engine, 84);
    return (0);
}

static void *init_addon(list_t *list)
{
    char *object_name = get_value_list(list, "object", 4);
    pokemon_anim_t *animation = NULL;

    animation = malloc(sizeof(pokemon_anim_t));
    if (!animation || !write_data(animation, list) || !object_name)
        return (NULL);
    animation->object_name = my_strdup(object_name);
    return (animation);
}

int init_pokemons_animation_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = start_addons;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = init_addon;
    addon->on_collision = NULL;
    if (create_addon("pokemons_animation", addon, engine) == sfFalse)
        return 84;
    return 0;
}
