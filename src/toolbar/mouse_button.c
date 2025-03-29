/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** button of tool bar
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int mouse_inside(button_t *button, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect button_bounds =
        sfRectangleShape_getGlobalBounds(button->rect);

    if (((mouse_pos.x >= button_bounds.left) &&
        (mouse_pos.x <= button_bounds.left + button_bounds.width)) &&
    (mouse_pos.y >= button_bounds.top &&
        (mouse_pos.y <= button_bounds.top + button_bounds.height)))
        return 1;
    return 0;
}

void change_size_button(button_t *button, sfRenderWindow *window)
{
    sfVector2f new_size = {250, 150};

    if (mouse_inside(button, window) == 1)
        sfRectangleShape_setSize(button->rect, new_size);
    else
        sfRectangleShape_setSize(button->rect, button->size);
}
