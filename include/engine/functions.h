/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

typedef struct execute_function_s {
    float time;
    event_functions_t function;
    object_t *object;
} execute_function_t;

////////////////////////////////////////////////////////////
/// \brief ajoute d'une nouvelle function qui s'executera à
/// la prochaine debut de la boucle du jeu
///
/// Le prototype de la function c'est object_t *object, engine_t *engine
///
/// \param function la function qu'on veut executer
///
/// \param time le temps d'attente avant de l'executer
/// en gros le game engine attendra jusqu'à que le temps que tu auras défini
/// sera écoulé puis il l'executera sans perturbé le jeu pendant l'attente
///
/// \return renvoie si oui ou non il l'a pu l'ajouter
///
////////////////////////////////////////////////////////////
sfBool add_function(event_functions_t function, float time, object_t *object,
    engine_t *engine);

////////////////////////////////////////////////////////////
/// Function système
////////////////////////////////////////////////////////////
int execute_functions(engine_t *engine);

////////////////////////////////////////////////////////////
/// Function système
////////////////////////////////////////////////////////////
int destroy_functions(engine_t *engine);

#endif
