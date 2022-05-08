/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** vector_distance
*/

#include "game_engine.h"
#include <math.h>

double calc_distance(sfVector2f a, sfVector2f b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}
