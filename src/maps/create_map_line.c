/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** create convexshape for map
*/

#include "my_world.h"

sfConvexShape *create_line(sfVector2f p1, sfVector2f p2,
    sfVector2f p3, sfVector2f p4)
{
    sfConvexShape *convex = sfConvexShape_create();

    sfConvexShape_setPointCount(convex, 4);
    sfConvexShape_setPoint(convex, 0, p1);
    sfConvexShape_setPoint(convex, 1, p2);
    sfConvexShape_setPoint(convex, 2, p3);
    sfConvexShape_setPoint(convex, 3, p4);
    sfConvexShape_setFillColor(convex, sfTransparent);
    return (convex);
}
