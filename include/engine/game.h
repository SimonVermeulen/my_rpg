/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef GAME_H
    #define GAME_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

////////////////////////////////////////////////////////////
/// Pas besoin d'explication pour celle-ci désolé
////////////////////////////////////////////////////////////
engine_t *init_game(sfVideoMode video, char const *title);

////////////////////////////////////////////////////////////
/// Function système
////////////////////////////////////////////////////////////
int execute_game(list_t *scene, engine_t *engine);

////////////////////////////////////////////////////////////
/// Pas besoin d'explication pour celle-ci désolé
////////////////////////////////////////////////////////////
int open_game(engine_t *engine, int fps);

////////////////////////////////////////////////////////////
/// Function système
////////////////////////////////////////////////////////////
int destroy_game(engine_t *engine);

////////////////////////////////////////////////////////////
/// \brief Renvoie le temps actuelle entre le début de la boucle
/// et l'execution de cette function en ms
///
/// à savoir qu'on peut voir le temps total de la dernière boucle du jeu
/// en ms dans engine->time->delta
///
////////////////////////////////////////////////////////////
float get_delta(engine_t *engine);

////////////////////////////////////////////////////////////
/// Function système
////////////////////////////////////////////////////////////
int set_time(engine_t *engine);

////////////////////////////////////////////////////////////
/// \brief Ferme de façon propre le jeu
///
/// à utiliser si on veut arrêter le jeu par exemple pour une erreur ou autre
///
/// \param code le code qui sera envoyé à la fin du jeu (par exemple 84)
///
/// \return il return la variable code donc si ta mit 84 il return 84
///
////////////////////////////////////////////////////////////
int exit_game(engine_t *engine, int code);

#endif