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

button_t *make_loop_minus(button_t *loop_minus, int image)
{
    sfVector2f pos;
    sfVector2f size;

    if (loop_minus == NULL) {
        pos = (sfVector2f){1040, 10};
        size = (sfVector2f){200, 100};
        loop_minus = malloc(sizeof(button_t));
        set_button_size(loop_minus, pos, size);
        set_color_button(loop_minus, sfWhite, sfWhite, THICKNESS);
        set_texture_button(loop_minus, image);
    }
    return loop_minus;
}

button_t *make_loop_plus(button_t *loop_plus, int image)
{
    sfVector2f pos;
    sfVector2f size;

    if (loop_plus == NULL) {
        pos = (sfVector2f){1250, 10};
        size = (sfVector2f){200, 100};
        loop_plus = malloc(sizeof(button_t));
        set_button_size(loop_plus, pos, size);
        set_color_button(loop_plus, sfWhite, sfWhite, THICKNESS);
        set_texture_button(loop_plus, image);
    }
    return loop_plus;
}

button_t *make_edit(button_t *edit, int image)
{
    sfVector2f pos;
    sfVector2f size;

    if (edit == NULL) {
        pos = (sfVector2f){1460, 10};
        size = (sfVector2f){200, 100};
        edit = malloc(sizeof(button_t));
        set_button_size(edit, pos, size);
        set_color_button(edit, sfWhite, sfWhite, THICKNESS);
        set_texture_button(edit, image);
    }
    return edit;
}

button_t *make_grill(button_t *edit, int image)
{
    sfVector2f pos;
    sfVector2f size;

    if (edit == NULL) {
        pos = (sfVector2f){1660, 10};
        size = (sfVector2f){200, 100};
        edit = malloc(sizeof(button_t));
        set_button_size(edit, pos, size);
        set_color_button(edit, sfWhite, sfWhite, THICKNESS);
        set_texture_button(edit, image);
    }
    return edit;
}
