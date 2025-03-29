/*
** EPITECH PROJECT, 2025
** event loop
** File description:
** my_world
*/

#include "my_world.h"
#include <stdio.h>

void add(sfEvent event, map3d_t *map)
{
    if (event.type == sfEvtKeyPressed){
        if (event.key.code == sfKeyS && map->length < MAX_LENGTH)
            update_3d_map(map, map->length + 1, map->width);
        if (event.key.code == sfKeyZ && map->length > MIN_LENGTH)
            update_3d_map(map, map->length - 1, map->width);
        if (event.key.code == sfKeyQ && map->width > MIN_WIDTH)
            update_3d_map(map, map->length, map->width - 1);
        if (event.key.code == sfKeyD && map->width < MAX_WIDTH)
            update_3d_map(map, map->length, map->width + 1);
    }
    if (event.type == sfEvtKeyReleased){
        if (event.key.code == sfKeyR)
            map->grid_on = (map->grid_on == YES) ? NO : YES;
        if (event.key.code == sfKeyE)
            map->editor_on = (map->editor_on == YES) ? NO : YES;
    }
}

void zoom(map3d_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyW))
        map->zoom += (map->zoom < MAX_ZOOM) ? 1 : 0;
    if (sfKeyboard_isKeyPressed(sfKeyX))
        map->zoom -= (map->zoom > MIN_ZOOM) ? 1 : 0;
}

void alt(map3d_t *map)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && map->selected.x != NO){
        map->alt[map->selected.x][map->selected.y] +=
            (map->alt[map->selected.x][map->selected.y] < MAX_HEIGHT) ? 1 : 0;
    }
    if (sfMouse_isButtonPressed(sfMouseRight) && map->selected.x != -1){
        map->alt[map->selected.x][map->selected.y] -=
            (map->alt[map->selected.x][map->selected.y] > MIN_HEIGHT) ? 1 : 0;
    }
}

void event_loop(window_t *wd, map3d_t *map,
    entity_t *entity, map2d_t *map_point)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wd->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(wd->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(wd->window);
        add(event, map);
        change_size(entity, wd->window, event, map);
        change_meteo(entity, wd->window, event, map_point);
        zoom_map(entity, wd->window, event, map);
        edit_mode(entity, wd->window, event, map);
        display_grill(entity, wd->window, event, map);
    }
    alt(map);
    zoom(map);
    rotation(wd);
}
