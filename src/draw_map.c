/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** draw map
*/

#include "my_world.h"
#include <stdio.h>

int draw_button(sfRenderWindow *window, entity_t *entity)
{
    if (!entity || !entity->array)
        return 1;
    for (int i = 0; entity->array[i] != NULL; i++) {
        change_size_button((entity->array[i]), window);
        sfRenderWindow_drawRectangleShape(
            window, entity->array[i]->rect, NULL);
    }
    return 0;
}

static void draw_tile(window_t *wd, map2d_t *map2D, int x, int y)
{
    sfConvexShape *tile = NULL;
    sfColor tile_color = {0, 0, 0, 0};

    if (!map2D->map || !map2D->map[x] || !map2D->map[x + 1] ||
        !map2D->map[x][y].altitude || !map2D->map[x + 1][y].altitude ||
        !map2D->map[x + 1][y + 1].altitude || !map2D->map[x][y + 1].altitude)
    tile = create_line(map2D->map[x][y].pos,
        map2D->map[x][y + 1].pos,
        map2D->map[x + 1][y + 1].pos,
        map2D->map[x + 1][y].pos);
    tile_color = get_tile_color(map2D, x, y);
    sfConvexShape_setFillColor(tile, tile_color);
    if (map2D->grid_on == YES){
        sfConvexShape_setOutlineColor(tile, sfBlack);
        sfConvexShape_setOutlineThickness(tile, 1);
    }
    sfRenderWindow_drawConvexShape(wd->window, tile, NULL);
    sfConvexShape_destroy(tile);
}

void draw_map(window_t *wd, map2d_t *map)
{
    if (!map)
        return;
    for (int x = 0; x < map->length - 1; x++){
        for (int y = 0; y < map->width - 1; y++){
            draw_tile(wd, map, x, y);
        }
    }
}

void selected(int x, int y, map3d_t *map, sfCircleShape *circ)
{
    if (x == map->selected.x && y == map->selected.y)
        sfCircleShape_setFillColor(circ, sfRed);
}

void draw_editor(window_t *wd, map3d_t *map)
{
    float len = EDITOR_LEN / map->width;
    float width = EDITOR_LEN / map->length;
    sfCircleShape *circ;
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (sfVector2f){0, 190});
    sfRectangleShape_setSize(rect, (sfVector2f){EDITOR_LEN, EDITOR_LEN});
    sfRectangleShape_setFillColor(rect, (sfColor){105, 74, 30, 255});
    sfRenderWindow_drawRectangleShape(wd->window, rect, NULL);
    for (int y = 0; y < map->width; y++){
        for (int x = 0; x < map->length; x++){
            circ = sfCircleShape_create();
            sfCircleShape_setPosition(circ,
                (sfVector2f){y * len , x * width + 200});
            selected(x, y, map, circ);
            sfCircleShape_setRadius(circ, 1);
            sfRenderWindow_drawCircleShape(wd->window, circ, NULL);
            sfCircleShape_destroy(circ);
        }
    }
    sfRectangleShape_destroy(rect);
}
