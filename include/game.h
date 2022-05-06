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
    double time;
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
    bool all;
} multi_enable_t;

typedef struct player_contoller_s {
    sfVector2f direction;
    list_t *list;
    const char *last;
} player_contoller_t;

typedef struct pokemon_anim_s {
    char *object_name;
    object_t *object;
    char *animation;
    double time;
    double count;
    double wait;
    char *enable;
    int infini;
    int width;
    int height;
    int row;
    sfFloatRect bounds;
    int init;
} pokemon_anim_t;

typedef struct data_s {
    char *path;
    list_t *data;
} data_t;

typedef struct grid_controller_s {
    sfVector2f move_point;
    object_t *object;
    list_t *list;
    sfVector2f direction;
    sfThread *coroutine;
    bool is_attack;
    double time;
} grid_controller_t;

typedef struct grid_s {
    char **map;
    int width;
    int height;
    list_t *list;
    list_t *cells;
} grid_t;

typedef struct cell_s {
    int x;
    int y;
    bool visited;
    list_t *neighbour;
} element_t;

typedef struct second_ai_s {
    sfVector2f move;
    bool is_moving;
} second_ai_t;

bool change_secondary_screen(const char *name, engine_t *engine);
secondary_screen_t *get_secondary_screen_data(engine_t *engine);
bool save_data_addon(engine_t *engine);
data_t *get_data_addon(engine_t *engine);
list_t *get_path(engine_t *engine, sfVector2i start, sfVector2i end);
int free_path(list_t *path);

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
int init_play_sound_addons(engine_t *engine);
int init_player_controller_addons(engine_t *engine);
int init_pokemons_addons(engine_t *engine);
int init_pokemons_animation_addons(engine_t *engine);
int init_interact_zone_addons(engine_t *engine);
int init_data_addons(engine_t *engine);
int init_load_data_object_addons(engine_t *engine);
int init_particle_move_addons(engine_t *engine);
int init_particle_addons(engine_t *engine);
int init_grid_controller_addons(engine_t *engine);
int init_second_ai_addons(engine_t *engine);
int init_grid_addons(engine_t *engine);
int init_enemy_ai_addons(engine_t *engine);

#endif /* !GAME_H_ */
