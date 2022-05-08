/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** is_equal_vector.c
*/

#include "game_engine.h"
#include <math.h>

bool equal_vector2f_pov(sfVector2f a, sfVector2f b, float pov)
{
    if (abs(a.x - b.x) <= pov && abs(a.y - b.y) <= pov)
        return true;
    return false;
}

bool equal_vector2f(sfVector2f a, sfVector2f b)
{
    if (a.x == b.x && a.y == b.y)
        return true;
    return false;
}

bool equal_vector2i(sfVector2i a, sfVector2i b)
{
    if (a.x == b.x && a.y == b.y)
        return true;
    return false;
}

bool equal_vector2f2i(sfVector2f a, sfVector2i b)
{
    if (a.x == b.x && a.y == b.y)
        return true;
    return false;
}
