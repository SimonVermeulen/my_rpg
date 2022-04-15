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

////////////////////////////////////////////////////////////
/// \brief Permet de crée un vecteur normaliser entre 2 points
////////////////////////////////////////////////////////////
sfVector2f get_normalize_vector(sfVector2f pos, sfVector2f direction);

////////////////////////////////////////////////////////////
/// \brief permet de comparer 2 vectors avec une valeur de tolérance
////////////////////////////////////////////////////////////
bool equal_vector2f_pov(sfVector2f a, sfVector2f b, float pov);
////////////////////////////////////////////////////////////
/// \brief permet de comparer 2 vector
////////////////////////////////////////////////////////////
bool equal_vector2f(sfVector2f a, sfVector2f b);
bool equal_vector2i(sfVector2i a, sfVector2i b);
bool equal_vector2f2i(sfVector2f a, sfVector2i b);
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// \brief permet de crée un sfVector à partir d'une liste
////////////////////////////////////////////////////////////
sfVector2f *malloc_vector2f_list(list_t *list);
sfVector2i *malloc_vector2i_list(list_t *list);
sfVector2f create_vector2f_list(list_t *list);
sfVector2i create_vector2i_list(list_t *list);
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// \brief permet de comparer 2 valeurs avec une valeur de tolérance
////////////////////////////////////////////////////////////
bool equal_prov(float a, float b, float pov);

#endif