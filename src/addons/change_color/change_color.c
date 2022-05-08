/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** change_color
*/

#include "game.h"

static int tick_addon(object_t *object, engine_t *engine)
{
    sfColor color = sfColor_fromRGB(rand() % 255, rand() % 255,
        rand() % 255);

    if (!object->entity || object->entity->type != CIRCLESHAPE)
        return exit_game(engine, 84);
    sfCircleShape_setFillColor(object->entity->data, color);
}

int init_change_color_addons(engine_t *engine)
{
    addon_t *addon = malloc(sizeof(addon_t));

    if (addon == NULL)
        return 84;
    addon->on_enable = NULL;
    addon->on_disable = NULL;
    addon->on_end = NULL;
    addon->on_start = NULL;
    addon->on_event = NULL;
    addon->on_tick = tick_addon;
    addon->init = NULL;
    addon->on_collision = NULL;
    if (create_addon("change_color", addon, engine) == sfFalse)
        return 84;
    return 0;
}