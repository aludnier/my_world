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

button_t *make_button_one(button_t *button, int image)
{
    sfVector2f pos;
    sfVector2f size;

    if (button == NULL) {
        pos = (sfVector2f){10, 10};
        size = (sfVector2f){200, 100};
        button = malloc(sizeof(button_t));
        if (!button)
            return NULL;
        set_button_size(button, pos, size);
        set_color_button(button, sfWhite, sfWhite, THICKNESS);
        set_texture_button(button, image);
        (button)->state = DAY;
    }
    return button;
}

button_t *make_right_button(button_t *plus, int image)
{
    sfVector2f pos;
    sfVector2f size;

    if (plus == NULL) {
        pos = (sfVector2f){210, 10};
        size = (sfVector2f){200, 100};
        plus = malloc(sizeof(button_t));
        set_button_size(plus, pos, size);
        set_color_button(plus, sfWhite, sfWhite, THICKNESS);
        set_texture_button(plus, image);
    }
    return plus;
}

button_t *make_left_button(button_t *minus, int image)
{
    sfVector2f pos;
    sfVector2f size;

    if (minus == NULL) {
        pos = (sfVector2f){420, 10};
        size = (sfVector2f){200, 100};
        minus = malloc(sizeof(button_t));
        set_button_size(minus, pos, size);
        set_color_button(minus, sfWhite, sfWhite, THICKNESS);
        set_texture_button(minus, image);
    }
    return minus;
}

button_t *make_up_button(button_t *up, int image)
{
    sfVector2f pos;
    sfVector2f size;

    if (up == NULL) {
        pos = (sfVector2f){620, 10};
        size = (sfVector2f){200, 100};
        up = malloc(sizeof(button_t));
        set_button_size(up, pos, size);
        set_color_button(up, sfWhite, sfWhite, THICKNESS);
        set_texture_button(up, image);
    }
    return up;
}

button_t *make_down_button(button_t *down, int image)
{
    sfVector2f pos;
    sfVector2f size;

    if (down == NULL) {
        pos = (sfVector2f){830, 10};
        size = (sfVector2f){200, 100};
        down = malloc(sizeof(button_t));
        set_button_size(down, pos, size);
        set_color_button(down, sfWhite, sfWhite, THICKNESS);
        set_texture_button(down, image);
    }
    return down;
}
