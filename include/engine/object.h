/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef OBJECT_H
    #define OBJECT_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

////////////////////////////////////////////////////////////
/// Avant de vouloir crée un object venez me voir
////////////////////////////////////////////////////////////
object_t *create_object(char const *name, list_t *scene, engine_t *engine);
object_t *create_object_list(list_t *list, list_t *scene, engine_t *engine,
    object_t *parent);
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// Function système
////////////////////////////////////////////////////////////
int destroy_object(object_t *object);

////////////////////////////////////////////////////////////
/// \brief cherche un object dans toute les scènes actuelle
///
/// Abusez pas de cette function sinon on va faire tourner le jeu à 2 fps
///
/// \param name le nom de l'object qu'on veut chercher
///
/// \return return l'object qu'il a trouvé sinon il renvoie NULL
///
////////////////////////////////////////////////////////////
object_t *seach_object(engine_t *engine, char const *name);

////////////////////////////////////////////////////////////
/// \brief cherche un object dans la scène donné en paramètre
///
/// \param name le nom de l'object qu'on veut chercher
///
/// \return return l'object qu'il a trouvé sinon il renvoie NULL
///
////////////////////////////////////////////////////////////
object_t *seek_object_scene(list_t *scene, char const *name);

////////////////////////////////////////////////////////////
/// \brief permet d'activer ou de désactiver un object
///
/// Si un object est désactivé elle s'affiche plus dans le jeu et
/// tout ses addons sont désactivé et donc plus executer
///
/// ses avec cette functions que les functions on_enable et on_disable
/// sont executé
///
/// \warning attention au enfant de l'object ils seront désactivé
///
/// \param value true/false
/// \param object l'object qu'on veut désactivé
///
/// \return return l'object qu'il a trouvé sinon il renvoie NULL
///
////////////////////////////////////////////////////////////
sfBool set_active(sfBool value, object_t *object, engine_t *engine);

////////////////////////////////////////////////////////////
/// Function système (function de fou surtout)
////////////////////////////////////////////////////////////
object_t **stock_object(object_t *object);

////////////////////////////////////////////////////////////
/// Function système
////////////////////////////////////////////////////////////
int on_active(object_t *object, engine_t *engine);

////////////////////////////////////////////////////////////
/// Function système
////////////////////////////////////////////////////////////
bool init_collision(list_t *list, object_t *object);
////////////////////////////////////////////////////////////
/// Function système
////////////////////////////////////////////////////////////
bool destroy_collision(object_t *object);
////////////////////////////////////////////////////////////
/// Function système
////////////////////////////////////////////////////////////
bool check_collision_event(engine_t *engine, list_t *scene);

////////////////////////////////////////////////////////////
/// \brief permet de voir si la souris est rentré en collision avec l'object
/// donné en paramètre
///
/// \return return si oui ou non la souris est à l'intérieur des collisions
/// de l'object
///
////////////////////////////////////////////////////////////
bool is_hover(engine_t *engine, object_t *object);
bool is_hover_point(object_t *object, sfVector2f point);
object_t *is_hover_all(engine_t *engine, sfVector2f point);

////////////////////////////////////////////////////////////
/// \brief permet de voir si l'object survole un autre object avec le
/// paramètre trigger d'activé
///
/// en gros lorsque une collision à le paramètre trigger d'activer
/// les collisions sont désactivé mais on va pouvoir quand même voir
/// si un object est rentré en contact avec
///
/// \warning function assez lourde donc avec modération :)
///
/// \return return collision ou il y a eu collision sinon il retourne NULL
///
////////////////////////////////////////////////////////////
collision_t *is_trigger(engine_t *engine, object_t *object);

////////////////////////////////////////////////////////////
/// Function système
////////////////////////////////////////////////////////////
bool get_collision_rect_circle(collision_t *a, collision_t *b);
bool get_collision_circle(collision_t *a, collision_t *b);
bool get_collision_rect(collision_t *a, collision_t *b);
bool get_collision(collision_t *a, collision_t *b);

bool if_collision(object_t *object_a, object_t *object_b);
bool check_collision_object(object_t *a, collision_t *b);

#endif