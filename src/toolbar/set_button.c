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

int set_button_size(button_t *button, sfVector2f pos, sfVector2f size)
{
    button->rect = sfRectangleShape_create();
    button->size = size;
    sfRectangleShape_setSize(button->rect, button->size);
    button->pos = pos;
    sfRectangleShape_setPosition(button->rect, button->pos);
    return 0;
}

int set_color_button(button_t *button, sfColor color_fill,
    sfColor outline_color, float thickness)
{
    sfRectangleShape_setFillColor(button->rect, color_fill);
    sfRectangleShape_setOutlineThickness(button->rect, thickness);
    sfRectangleShape_setOutlineColor(button->rect, outline_color);
    return 0;
}

sfText *set_text(char *title, char *font_choosen,
    sfColor color_text, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(font_choosen);

    sfText_setString(text, title);
    sfText_setColor(text, color_text);
    sfText_setFont(text, font);
    sfText_setScale(text, (sfVector2f){2.5, 1.5});
    sfText_setPosition(text, pos);
    return text;
}

button_t *set_texture_button(button_t *button, int image)
{
    button->texture =
        sfTexture_createFromFile(TEXTURE_BUTTON_ONE[image], NULL);
    sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
    return button;
}
