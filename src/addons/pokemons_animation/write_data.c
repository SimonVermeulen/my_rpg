/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** write_data
*/

#include "game.h"
#include "my.h"

static int endwritedata(pokemon_anim_t *animation, list_t *list)
{
    int *row = get_value_list(list, "row", 3);
    int *nb_rep = get_value_list(list, "nb_rep", 3);
    list_t *scale = get_value_list(list, "scale", 1);
    list_t *position = get_value_list(list, "position", 1);

    if (!nb_rep || !row || !scale)
        return (false);
    animation->nb_rep = *nb_rep;
    animation->row = *row;
    animation->scale = create_vector2f_list(scale);
    if (position)
        animation->position = create_vector2f_list(position);
    return (true);
}

int write_data(pokemon_anim_t *animation, list_t *list)
{
    double *wait = get_value_list(list, "waitbeforestart", 2);
    char *name = get_value_list(list, "animation", 4);
    char *enable = get_value_list(list, "enable", 4);
    int *infini = get_value_list(list, "infini", 3);
    double *time = get_value_list(list, "time", 2);
    char *object_name = get_value_list(list, "object", 4);

    if (!wait || !name || !enable || !infini || !time || !object_name ||
        !endwritedata(animation, list))
        return (false);
    animation->width = animation->height = 0;
    animation->object_name = my_strdup(object_name);
    animation->animation = my_strdup(name);
    animation->infini = *infini;
    animation->enable = my_strdup(enable);
    animation->wait = *wait;
    animation->time = *time;
    animation->init = false;
    animation->count = 0;
    return (true);
}
