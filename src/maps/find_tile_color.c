/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** get tile colors
*/

#include "my_world.h"
#include <stdio.h>

int check_map_validity(int x, int y, map2d_t *map)
{   
    if (x >= (map->length - 1) || y >= (map->width - 1) || x < 0 || y < 0)
        return 1;
    if (!map->map || !map->map[x])
        return 1;
    return 0;
}

sfColor get_color(int alt_mean, map2d_t *map)
{
    for (int i = 0; i < 3; i++){    
        if (alt_mean >= alt_color[map->state][i].minimal &&
            alt_mean < alt_color[map->state][i].maximal)
           return alt_color[map->state][i].color;
    }
}

sfColor get_tile_color(map2d_t *map, int x, int y)
{
    int alt[NB_ALT] = {0};
    int alt_mean = 0;

    if (check_map_validity(x, y, map) == 1)
        return sfBlue;
    alt[0] = map->map[x][y].altitude;
    alt[1] = map->map[x + 1][y].altitude;
    alt[2] = map->map[x + 1][y + 1].altitude;
    alt[3] = map->map[x][y + 1].altitude;
    for (int i = 0; i < NB_ALT; i++)
        alt_mean += alt[i];
    alt_mean /= NB_ALT;
    if (map->state == 0 || map->state == 1 || map->state == 2) {
        return get_color(alt_mean, map);
    }
    return sfWhite;
}
