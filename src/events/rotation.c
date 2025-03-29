/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** rotate angle
*/

#include "my_world.h"

void rotation(window_t *wd)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        wd->angles.y -= (wd->angles.y > 0) ? 1 : 0;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        wd->angles.y += (wd->angles.y < MAX_HEIGHT) ? 1 : 0;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        wd->angles.x += (wd->angles.x < 60) ? 1 : 0;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        wd->angles.x -= (wd->angles.x > MIN_HEIGHT) ? 1 : 0;
}
