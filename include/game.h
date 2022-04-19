/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include "game_engine.h"

typedef struct secondary_screen_s {
    sfView *bloc_1;
    sfView *bloc_2;
    scene_t *second;
    scene_t *prev;
} secondary_screen_t;

typedef struct translation_animation_s {
    float wait;
    list_t *positions;
    int step;
    float count_wait;
    sfVector2f normal;
    bool infini;
    bool reverse;
    bool is_reverse;
} translation_animation_t;

typedef struct vector_speed_s {
    sfVector2f position;
    float speed;
} vector_speed_t;

typedef struct parallax_s {
    object_t *element_1;
    object_t *element_2;
    float speed;
    float width;
} parallax_t;

typedef struct sparkles_s {
    int order;
} sparkles_t;

bool change_secondary_screen(const char *name, engine_t *engine);
secondary_screen_t *get_secondary_screen_data(engine_t *engine);

///////
// ADDONS PROTOTYPE
////

int init_secondary_screen_addons(engine_t *engine);
int init_translation_animation_addons(engine_t *engine);
int init_parallax_addons(engine_t *engine);
int init_rect_animation_addons(engine_t *engine);
int init_move_view_addons(engine_t *engine);

#endif /* !GAME_H_ */
