/*
** EPITECH PROJECT, 2021
** include [WSL: Ubuntu]
** File description:
** scene.h
*/

#ifndef EVENT_H
    #define EVENT_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

    #include "../game_engine.h"

sfVector2f get_mouse_position(engine_t *engine);

bool get_left_click_pressed(engine_t *engine);
bool get_right_click_pressed(engine_t *engine);
bool get_middle_click_pressed(engine_t *engine);
bool get_extra_click_pressed(engine_t *engine, int number);

bool get_left_click_released(engine_t *engine);
bool get_right_click_released(engine_t *engine);
bool get_middle_click_released(engine_t *engine);
bool get_extra_click_released(engine_t *engine, int number);

bool is_scrolling(engine_t *engine);
sfMouseWheelScrollEvent *get_scrolling(engine_t *engine);

bool if_key_pressed(engine_t *engine, int key);
bool if_key_released(engine_t *engine, int key);
sfKeyEvent *get_key_pressed(engine_t *engine, int key);
sfKeyEvent *get_key_released(engine_t *engine, int key);

#endif