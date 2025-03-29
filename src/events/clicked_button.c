/*
** EPITECH PROJECT, 2025
** event loop
** File description:
** my_world
*/

#include "my_world.h"
#include <stdio.h>

int button_clicked(sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased &&
            event.mouseButton.button == sfMouseLeft)
        return 1;
    return 0;
}

int update_meteo(int state)
{
    static int save_state = DAY;

    save_state = state;
    return save_state;
}

void change_meteo(entity_t *meteo, sfRenderWindow *window,
    sfEvent event, map2d_t *map)
{
    if (!meteo->array[METEO] || !map)
        return;
    if (mouse_inside(meteo->array[METEO], window) == 1 &&
    button_clicked(event)) {
        meteo->array[METEO]->state = (meteo->array[METEO]->state + 1) % 3;
        map->state = (map->state + 1 ) % 3;
        set_texture_button(meteo->array[METEO], meteo->array[METEO]->state);
        update_meteo(map->state);
    }
}

void change_size(entity_t *entity, sfRenderWindow *window,
    sfEvent event, map3d_t *map)
{
    if ((mouse_inside(entity->array[LEFT], window) == 1 &&
    button_clicked(event)) && map->length < MAX_LENGTH)
        update_3d_map(map, map->length + 1, map->width);
    if ((mouse_inside(entity->array[RIGHT], window) == 1 &&
    button_clicked(event)) && map->length > MIN_LENGTH)
        update_3d_map(map, map->length - 1, map->width);
    if ((mouse_inside(entity->array[UP], window) == 1 &&
    button_clicked(event)) && map->width > MIN_WIDTH)
        update_3d_map(map, map->length, map->width - 1);
    if ((mouse_inside(entity->array[DOWN], window) == 1 &&
    button_clicked(event)) && map->width < MAX_WIDTH)
        update_3d_map(map, map->length, map->width + 1);
}

void zoom_map(entity_t *entity, sfRenderWindow *window,
    sfEvent event, map3d_t *map)
{
    if (mouse_inside(entity->array[ZOOM_PLUS], window) == 1 &&
    button_clicked(event))
        map->zoom += (map->zoom < MAX_ZOOM) ? 1 : 0;
    if (mouse_inside(entity->array[ZOOM_MINUS], window) == 1
    && button_clicked(event))
        map->zoom -= (map->zoom > MIN_ZOOM) ? 1 : 0;
}
