/*
** EPITECH PROJECT, 2025
** my_worls
** File description:
** create 2D map
*/

#include "my_world.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

sfVector2f project_iso_point(sfVector3f pos, float angle_x, float angle_y)
{
    float rot = (angle_x) * (PI / 180);
    float view = (angle_y) * (PI / 180);
    float c = sinf(rot) * (pos.x) + (cosf(rot) * pos.z);
    float a = cosf(rot) * (pos.x) - (sinf(rot) * pos.z);
    float b = pos.y * cosf(view) - c * sinf(view);

    return ((sfVector2f) {(a + WIDTH / 2 + 100), (b + HEIGTH / 2)});
}

static sfVector3f get_3d_point(map3d_t *map3D, int x, int y)
{
    sfVector3f point = {x, y, map3D->alt[y][x]};

    point.x -= map3D->width / 2;
    point.y -= map3D->length / 2;
    point.x *= map3D->zoom;
    point.y *= map3D->zoom;
    point.z *= map3D->zoom / 10;
    return point;
}

void update_map(map2d_t *map2D, map3d_t *map3D, window_t *wd)
{
    is_point_closer(map3D, wd);
    map2D->map[map3D->length] = NULL;
    map2D->length = map3D->length;
    map2D->state = update_meteo(map2D->state);
    map2D->width = map3D->width;
    map2D->grid_on = map3D->grid_on;
}

map2d_t *create_2d_map(map3d_t *map3D, sfVector2f angle, window_t *wd)
{
    map2d_t *map2D = malloc(sizeof(struct map2d_s));
    sfVector3f point = {0, 0, 0};

    if (!map2D)
        return NULL;
    map2D->map = malloc(sizeof(point2d_t *) * (map3D->length + 1));
    for (int y = 0; y < map3D->length; y++){
        map2D->map[y] = malloc(sizeof(point2d_t) * (map3D->width + 1));
        for (int x = 0; x < map3D->width; x++){
            point = get_3d_point(map3D, x, y);
            map2D->map[y][x].pos = project_iso_point(point, angle.x, angle.y);
            map2D->map[y][x].altitude = map3D->alt[y][x];
        }
    }
    update_map(map2D, map3D, wd);
    return map2D;
}
