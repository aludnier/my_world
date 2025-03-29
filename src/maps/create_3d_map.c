/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** create 3D map
*/


#include "my_world.h"
#include <stdlib.h>
#include <stdio.h>

static int get_alt(map3d_t *map3D, int i, int j)
{
    if (i < map3D->length && j < map3D->width)
        return map3D->alt[i][j];
    return 0;
}

void update_3d_map(map3d_t *map3d, int nlenght, int nwidth)
{
    int **n_alt = malloc(sizeof(int *) * (nlenght + 1));

    for (int i = 0; i < nlenght; i++){
        n_alt[i] = malloc(sizeof(int) * (nwidth + 1));
        for (int j = 0; j < nwidth; j++){
            n_alt[i][j] = get_alt(map3d, i, j);
        }
    }
    for (int y = 0; y < map3d->length; y++)
        free(map3d->alt[y]);
    free(map3d->alt);
    map3d->alt = n_alt;
    map3d->length = nlenght;
    map3d->width = nwidth;
}

map3d_t *create_3d_map(int lenght, int width)
{
    map3d_t *map = malloc(sizeof(struct map3d_s));

    map->length = lenght;
    map->width = width;
    map->zoom = 100;
    map->grid_on = YES;
    map->editor_on = NO;
    map->selected = (sfVector2i){0, 0};
    map->alt = malloc(sizeof(int *) * (lenght + 1));
    for (int i = 0; i < lenght; i++){
        map->alt[i] = malloc(sizeof(int) * (width + 1));
        for (int j = 0; j < width; j++)
            map->alt[i][j] = 0;
    }
    return map;
}
