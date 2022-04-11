/*
** EPITECH PROJECT, 2021
** my_defender [WSL: Ubuntu]
** File description:
** get_mouse_position.c
*/

#include "game_engine.h"

sfVector2f get_mouse_position(engine_t *engine)
{
    if (engine == NULL)
        return (sfVector2f) {0, 0};
    return sfRenderWindow_mapPixelToCoords(engine->window,
        sfMouse_getPositionRenderWindow(engine->window), engine->view);
}
