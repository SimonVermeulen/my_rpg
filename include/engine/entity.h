/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef ENTITY_H
    #define ENTITY_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

bool init_entity(list_t *entity_list, object_t *object);
int print_entity(object_t *object, engine_t *engine);
int add_print_list_entity(object_t *object, list_t *print);
bool destroy_entity(object_t *object);
void init_data_entity(list_t *entity_list, object_t *object);

////////////////////////////////////////////////////////////
/// \brief Renvoie la position de l'object
///
/// \param object l'object en question
///
/// \return la position de l'object, renvoie x: 0 y: 0 si l'object est pas compatible
///
////////////////////////////////////////////////////////////
sfVector2f get_position(object_t *object);

////////////////////////////////////////////////////////////
/// \brief Renvoie le local bounds de l'object
///
/// Le local bounds permet de connaître la taille (width/height) de l'object
/// le left et le top est inutile sur le local bounds
///
/// \param object l'object en question
///
/// \return la position de l'object, renvoie les valeurs à 0 si l'object est pas compatible
///
////////////////////////////////////////////////////////////
sfFloatRect get_local_bounds(object_t *object);

////////////////////////////////////////////////////////////
/// \brief Renvoie le global bounds de l'object
///
/// Le global bounds permet de connaître la taille (width/height) de l'object
/// et renvoie aussi la position de l'object dans le left [X] et top [Y]
//
/// \param object l'object en question
///
/// \return la position de l'object, renvoie les valeurs à 0 si l'object est pas compatible
///
////////////////////////////////////////////////////////////
sfFloatRect get_global_bounds(object_t *object);

////////////////////////////////////////////////////////////
/// \brief set la position de l'object
///
/// \param object l'object en question
///
/// \param position la nouvelle position de l'object
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_position_vector(object_t *object, sfVector2f position);

////////////////////////////////////////////////////////////
/// \brief set la position de l'object
///
/// \param object l'object en question
///
/// \param x la nouvelle position (x) de l'object
/// \param y la nouvelle position (y) de l'object
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_position_float(object_t *object, float x, float y);

////////////////////////////////////////////////////////////
/// \brief set la position de l'object
///
/// \param object l'object en question
///
/// \param list la nouvelle position sur forme de list
/// à l'intérieur il doit y avoir un x et un y
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_position_list(object_t *object, list_t *list);

////////////////////////////////////////////////////////////
/// \brief fait bouger l'object
///
/// c'est pareil que sfSprite_move
///
/// \param object l'object en question
///
/// \param position la velocité du mouvement de l'object
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool move_vector(object_t *object, sfVector2f position);
////////////////////////////////////////////////////////////
/// \brief fait bouger l'object
///
/// c'est pareil que sfSprite_move
///
/// \param object l'object en question
///
/// \param x la velocité (x) du mouvement de l'object
/// \param y la velocité (y) du mouvement de l'object
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool move_float(object_t *object, float x, float y);

////////////////////////////////////////////////////////////
/// \brief set la rotation de l'object
///
/// \param object l'object en question
///
/// \param angle l'angle qu'on veut mettre
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_rotation(object_t *object, float angle);

////////////////////////////////////////////////////////////
/// \brief fait tourner la position de l'object selon sa rotation actuelle
///
/// c'est pareil que le sfSprite_rotate
///
/// \param object l'object en question
///
/// \param angle l'angle qu'on veut mettre
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool rotate(object_t *object, float angle);

////////////////////////////////////////////////////////////
/// \brief scale l'object
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_scale_vector(object_t *object, sfVector2f scale);
////////////////////////////////////////////////////////////
/// \brief scale l'object
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_scale_float(object_t *object, float x, float y);
bool set_scale_list(object_t *object, list_t *list);
////////////////////////////////////////////////////////////
/// \brief scale l'object
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool scale_vector(object_t *object, sfVector2f scale);
////////////////////////////////////////////////////////////
/// \brief scale l'object
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool scale_float(object_t *object, float x, float y);

////////////////////////////////////////////////////////////
/// \brief set l'origin de l'object
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_origin(object_t *object, sfVector2f origin);
////////////////////////////////////////////////////////////
/// \brief set l'origin de l'object
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_origin_list(object_t *object, list_t *list);

///////
// ANCHOR TYPE
///////

    #define TOP_LEFT 0
    #define TOP 1
    #define TOP_RIGHT 2
    #define LEFT 3
    #define MIDDLE 4
    #define RIGHT 5
    #define BOTTOM_LEFT 6
    #define BOTTOM 7
    #define BOTTOM_RIGHT 8

////////////////////////////////////////////////////////////
/// \brief set l'anchor de l'object
///
/// En gros en déplace le point d'origin à des endroits prédéfini
/// les endroits prédéfini se ceux juste au dessus (les défines)
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_origin_anchor(object_t *object, int type);

////////////////////////////////////////////////////////////
/// \brief set la texture
///
/// La texture est stocké directement dans le buffer de la scène
/// on peut donc pas prendre un buffer extérieur (dans une autre scène)
///
/// \param name le nom de la texture
///
/// \param reset_rect si on doit reset le rect actuelle de l'object pour
/// le nouvelle object
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_texture(object_t *object, const char *name, sfBool reset_rect);

////////////////////////////////////////////////////////////
/// \brief set la texture
///
/// La texture est stocké directement dans le buffer de la scène
/// on peut donc pas prendre un buffer extérieur (dans une autre scène)
///
/// \param name le nom de la texture
///
/// \param rect La rect qu'on veut set
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_texture_with_rect(object_t *object, const char *name, sfIntRect rect);

////////////////////////////////////////////////////////////
/// \brief set la texture
///
/// \param rect La rect qu'on veut set
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_texture_rect(object_t *object, sfIntRect rect);

////////////////////////////////////////////////////////////
/// \brief set la texture
///
/// Venez me voir si vous voulez un jour utilisez cette belle function
///
/// \param list les données de la texture
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_texture_list(object_t *object, list_t *list);

////////////////////////////////////////////////////////////
/// \brief set le fill color
///
/// Pareil que la function de base de la sfml
/// la couleur est stocké dans le buffer
///
/// \param name le nom de la couleur stocké dans le buffer
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_fill_color(object_t *object, const char *name);

////////////////////////////////////////////////////////////
/// \brief set outline color
///
/// Pareil que la function de base de la sfml
/// la couleur est stocké dans le buffer
///
/// \param name le nom de la couleur stocké dans le buffer
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_outline_color(object_t *object, const char *name);

////////////////////////////////////////////////////////////
/// \brief set thickness color
///
/// Pareil que la function de base de la sfml
/// la couleur est stocké dans le buffer
///
/// \param name le nom de la couleur stocké dans le buffer
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_outline_thickness(object_t *object, const char *name);

////////////////////////////////////////////////////////////
/// \brief set le color
///
/// Pareil que la function de base de la sfml
/// la couleur est stocké dans le buffer
///
/// \param name le nom de la couleur stocké dans le buffer
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_color(object_t *object, const char *name);

////////////////////////////////////////////////////////////
/// \brief set le radius
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_radius(object_t *object, float radius);

////////////////////////////////////////////////////////////
/// \brief set le point count
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_point_count(object_t *object, size_t count);

////////////////////////////////////////////////////////////
/// \brief set le point
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_point(object_t *object, size_t index, sfVector2f point);

////////////////////////////////////////////////////////////
/// \brief set le point count
///
/// On utilisera jamais cette function mais elle est là et elle est belle
/// tu veux connaître son utilité ? Viens me voir
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_point_list(object_t *object, list_t *list);

////////////////////////////////////////////////////////////
/// \brief set size
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_size(object_t *object, sfVector2f size);

////////////////////////////////////////////////////////////
/// \brief set size
///
/// Pareil que le set size c'est juste que les coordonnées sont dans la liste
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_size_list(object_t *object, list_t *list);

////////////////////////////////////////////////////////////
/// \brief set string
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_string(object_t *object, const char *string);

////////////////////////////////////////////////////////////
/// \brief set font
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_font(object_t *object, const char *name);

////////////////////////////////////////////////////////////
/// \brief set character size
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_character_size(object_t *object, unsigned int size);

////////////////////////////////////////////////////////////
/// \brief set line spacing
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_line_spacing(object_t *object, float spacing);

////////////////////////////////////////////////////////////
/// \brief set letter spacing
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_letter_spacing(object_t *object, float spacing);

////////////////////////////////////////////////////////////
/// \brief set style
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_style(object_t *object, sfUint32 style);

////////////////////////////////////////////////////////////
/// \brief set le buffer (pour la soundeffect)
///
/// Pareil que la function de base de la sfml
/// le bufferSound est stocké dans le buffer
///
/// \param name le nom du buffersound stocké dans le buffer
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_buffer(object_t *object, const char *name);

////////////////////////////////////////////////////////////
/// \brief set loop
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_loop(object_t *object, sfBool loop);

////////////////////////////////////////////////////////////
/// \brief set pitch
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_pitch(object_t *object, float pitch);

////////////////////////////////////////////////////////////
/// \brief set volume
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_volume(object_t *object, float volume);

////////////////////////////////////////////////////////////
/// \brief set relative
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_relative(object_t *object, sfBool relative);

////////////////////////////////////////////////////////////
/// \brief set min distance
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_min_distance(object_t *object, float distance);

////////////////////////////////////////////////////////////
/// \brief set attenuation
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_attenuation(object_t *object, float attenuation);

////////////////////////////////////////////////////////////
/// \brief set playing offset
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool set_playing_offset(object_t *object, sfInt64 microseconds);

////////////////////////////////////////////////////////////
/// \brief play sound
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool play_sound(object_t *object);

////////////////////////////////////////////////////////////
/// \brief stop sound
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool stop_sound(object_t *object);

////////////////////////////////////////////////////////////
/// \brief pause sound
///
/// Pareil que la function de base de la sfml
///
/// \return renvoie si il a réussi à le set ou non
///
////////////////////////////////////////////////////////////
bool pause_sound(object_t *object);

#endif