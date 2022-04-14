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

bool equal_vector2f_pov(sfVector2f a, sfVector2f b, float pov);
bool equal_vector2f(sfVector2f a, sfVector2f b);
bool equal_vector2i(sfVector2i a, sfVector2i b);
bool equal_vector2f2i(sfVector2f a, sfVector2i b);

sfVector2f *malloc_vector2f_list(list_t *list);
sfVector2i *malloc_vector2i_list(list_t *list);
sfVector2f create_vector2f_list(list_t *list);
sfVector2i create_vector2i_list(list_t *list);

bool equal_prov(float a, float b, float pov);

#endif