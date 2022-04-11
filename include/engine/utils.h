/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** utils.h
*/

#ifndef UTILS_H
    #define UTILS_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

sfVector2f get_normalize_vector(sfVector2f pos, sfVector2f direction);

bool equal_vector2f(sfVector2f a, sfVector2f b);
bool equal_vector2i(sfVector2i a, sfVector2i b);
bool equal_vector2f2i(sfVector2f a, sfVector2i b);

#endif