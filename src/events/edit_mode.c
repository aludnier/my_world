/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** event of gril and edit
*/

#include "my_world.h"
#include <stdio.h>

void edit_mode(entity_t *entity, sfRenderWindow *window,
    sfEvent event, map3d_t *map)
{
    if (mouse_inside(entity->array[EDIT], window) == 1 &&
    button_clicked(event)) {
            map->editor_on = (map->editor_on == YES) ? NO : YES;
    }
}

void display_grill(entity_t *entity, sfRenderWindow *window,
    sfEvent event, map3d_t *map)
{
    if (mouse_inside(entity->array[GRID], window) == 1 &&
    button_clicked(event)) {
        map->grid_on = (map->grid_on == YES) ? NO : YES;
    }
}
