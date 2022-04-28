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
    char *name;
    char *name_enable;
    object_t *enable;
    object_t *object;
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

typedef struct event_manager_s {
    list_t *data;
    list_t **actions;
    int length;
    int count;
} event_manager_t;

typedef struct sparkles_s {
    int order;
} sparkles_t;

typedef struct dialogue_s {
    list_t *data;
    list_t **texts;
    int length;
    int count;
    double wait;
    bool active;
    char *enable;
    bool disable;
} dialogue_t;

typedef struct text_animation_s {
    list_t *data;
    double prize;
    double time;
    int count;
    char *string;
    char *string_display;
} text_animation_t;

typedef struct select_manager_s {
    list_t *data;
    list_t **items;
    int length;
    int count;
} select_manager_t;

typedef struct position_by_view_s {
    int bloc;
    sfVector2f position;
    bool inited;
} position_by_view_t;

typedef struct multi_enable_s {
    list_t *data;
    char **items;
    int length;
} multi_enable_t;

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
int init_follow_view_addons(engine_t *engine);
int init_change_scene_addons(engine_t *engine);
int init_event_manager_addons(engine_t *engine);
int init_dialogue_manager_addons(engine_t *engine);
int init_text_animation_addons(engine_t *engine);
int init_select_manager_addons(engine_t *engine);
int init_position_by_view_addons(engine_t *engine);
int init_multi_enable_addons(engine_t *engine);
int init_multi_disable_addons(engine_t *engine);

#endif /* !GAME_H_ */
