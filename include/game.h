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
    float speed;
    float wait;
    list_t *positions;
    int step;
    float count_wait;
    sfVector2f normal;
} translation_animation_t;

bool change_secondary_screen(const char *name, engine_t *engine);

///////
// ADDONS PROTOTYPE
////

int init_secondary_screen_addons(engine_t *engine);
int init_translation_animation_addons(engine_t *engine);

#endif /* !GAME_H_ */
