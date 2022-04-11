/*
** EPITECH PROJECT, 2021
** lib-2 [WSL: Ubuntu]
** File description:
** collision_circle_rect.c
*/

#include "game_engine.h"
#include <math.h>

bool get_collision_rect_circle(collision_t *a, collision_t *b)
{
    sfVector2f pa = get_position(a->object);
    sfVector2f pb = get_position(b->object);
    double dx = fabs((b->circle.point.x + pb.x) -
        (a->box.left + pa.x) - a->box.width / 2);
    double dy = fabs((b->circle.point.y + pb.y) -
        (a->box.top + pa.y) - a->box.height / 2);

    if (dx > (a->box.width / 2 + b->circle.radius))
        return false;
    if (dy > (a->box.height / 2 + b->circle.radius))
        return false;
    if (dx <= (a->box.width  / 2))
        return true;
    if (dy <= (a->box.height / 2))
        return true;
    dx = dx - a->box.width / 2;
    dy = dy - a->box.height / 2;
    return (dx * dx + dy * dy <= b->circle.radius * b->circle.radius) ?
        true : false;
}

bool get_collision_circle(collision_t *a, collision_t *b)
{
    sfVector2f pa = get_position(a->object);
    sfVector2f pb = get_position(b->object);
    float distance_radius = a->circle.radius + b->circle.radius;
    float distance = sqrt(pow((b->circle.point.x + pb.x) -
        (a->circle.point.x + pa.x), 2) + pow((b->circle.point.y + pb.y)
        - (a->circle.point.y + pa.y), 2));

    if (distance_radius > distance)
        return true;
    return false;
}

bool get_collision_rect(collision_t *a, collision_t *b)
{
    sfVector2f pa = get_position(a->object);
    sfVector2f pb = get_position(b->object);
    sfFloatRect ra = a->box;
    sfFloatRect rb = b->box;

    ra.left += pa.x;
    ra.top += pa.y;
    rb.left += pb.x;
    rb.top += pb.y;
    return sfFloatRect_intersects(&ra, &rb, NULL);
}

bool get_collision(collision_t *a, collision_t *b)
{
    if (a->type == CIRCLE && b->type == CIRCLE)
        return get_collision_circle(a, b);
    if (a->type == CIRCLE && b->type == BOX)
        return get_collision_rect_circle(b, a);
    if (a->type == BOX && b->type == CIRCLE)
        return get_collision_rect_circle(a, b);
    if (a->type == BOX && b->type == BOX)
        return get_collision_rect(a, b);
    return false;
}