/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** receive_damage.c
*/

#include "game.h"

int send_damage(object_t *object)
{
    list_t *list = is_trigger(object->engine, object);
    data_t *data = get_data_addon(object->engine);
    mobs_t *mobs = get_addon_data("mobs", object);
    double *life_a = get_value_list(data->data, "lifea", 2);
    double *life_b = get_value_list(data->data, "lifeb", 2);
    double *damage = get_value_list(data->data, "damage", 2);
    collision_t *enemy = get_value_list(list, "enemy", 4);
    mobs_t *mob = NULL;

    if (!life_a || !life_b || !damage)
        return exit_game(object->engine, 84);
    if (enemy)
        mob = get_addon_data("mobs", enemy->object);
    if (get_value_list(list, "second_pokemon", 4) && mobs)
        *life_b -= mobs->damage;
    if (get_value_list(list, "main_pokemon", 4) && mobs)
        *life_a -= mobs->damage;
    if (get_value_list(list, "enemy", 4) && mob)
        mob->life -= *damage;
    return destroy_addons(list, true);
}
