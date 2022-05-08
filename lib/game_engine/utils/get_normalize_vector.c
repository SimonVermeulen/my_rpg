/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** get_normalize_vector.c
*/

#include "game_engine.h"
#include <math.h>

sfVector2f get_normalize_vector(sfVector2f pos, sfVector2f direction)
{
    float x = direction.x - pos.x;
    float y = direction.y - pos.y;
    float hypotenuse = sqrt(pow(x, 2) + pow(y, 2));

    if (hypotenuse == 0)
        return (sfVector2f) {0, 0};
    return (sfVector2f) {(x / hypotenuse), (y / hypotenuse)};
}
