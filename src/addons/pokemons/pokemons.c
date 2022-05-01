/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-adil.nouiri
** File description:
** pokemons
*/

#include "game.h"

static int pokemon_start(object_t *object, engine_t *engine)
{
    list_t *pokemon = get_addon_data("pokemons", object);
    list_t **buffer = get_value_list(pokemon, "buffer", 10);

    if (!buffer)
        return 0;
    for (int i = 0; i < search_from_key(pokemon, "buffer")->len; i++)
        init_texture(engine->actual_scene, buffer[i]);
    return 0;
}

static void *init_pokemon(list_t *list)
{
    return copy_list(list);
}

static int pokemon_end(object_t *object, engine_t *engine)
{
    node_t *node = NULL;

    node = search_from_key(object->addons_data, "pokemons");
    if (node == NULL)
        return NULL;
    free_json_object(node->value);
    node->value = NULL;
    return 0;
}

int init_pokemons_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = pokemon_end;
    addon->on_start = pokemon_start;
    addon->on_event = NULL;
    addon->on_tick = NULL;
    addon->init = init_pokemon;
    addon->on_collision = NULL;
    if (create_addon("pokemons", addon, engine) == sfFalse)
        return 84;
    return 0;
}
