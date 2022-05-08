/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** equal_prov.c
*/

#include "game_engine.h"

bool equal_prov(float a, float b, float pov)
{
    return (fabs(a - b) <= pov) ? true : false;
}
