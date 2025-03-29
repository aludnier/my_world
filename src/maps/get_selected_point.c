/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** unmake isometrique
*/


#include "my_world.h"
#include <math.h>
#include <stdio.h>

int my_round(float nb)
{
    nb *= 10;
    if ((int)nb % 10 >= 5)
        nb = (nb + 5) / 10;
    else
        nb = (nb - (int)nb % 10) / 10;
    return (int)nb;
}

int is_point_closer(map3d_t *map3d, window_t *wd)
{
    sfVector2f new;

    if (map3d->editor_on == NO){
        map3d->selected = (sfVector2i){NO, NO};
        return 0;
    }
    new.x = (float)(sfMouse_getPositionRenderWindow(wd->window).x )/
        (EDITOR_LEN / map3d->width);
    new.y = (float)(sfMouse_getPositionRenderWindow(wd->window).y - 200)/
        (EDITOR_LEN / map3d->length );
    if (new.x < map3d->width && new.y < map3d->length &&
        new.x >= 0 && new.y >= 0){
        map3d->selected = (sfVector2i){my_round(new.y), my_round(new.x)};
    } else
        map3d->selected = (sfVector2i){NO, NO};
    return 0;
}
