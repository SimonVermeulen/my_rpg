/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** sleep.c
*/

#include "game.h"

void sleep(double ms)
{
    sfClock *clock = sfClock_create();
    double time = 0;

    while (true) {
        time = sfClock_getElapsedTime(clock).microseconds / 1000;
        if (time >= ms)
            break;
    }
    sfClock_destroy(clock);
}
