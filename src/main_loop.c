/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** main loop
*/

#include "my_world.h"
#include <stdlib.h>
#include <stdio.h>

window_t *init_window(void)
{
    window_t *wd = malloc(sizeof(struct window_s));
    sfVideoMode v_mode = {WIDTH, HEIGTH, BPS};
    sfIntRect area = {0, 0, WIDTH, HEIGTH};

    wd->window = sfRenderWindow_create(v_mode,
        "my_world", sfDefaultStyle, NULL);
    wd->area = area;
    wd->angles = (sfVector2f){ANGLE_X, ANGLE_Y};
    sfRenderWindow_setFramerateLimit(wd->window, MAX_HEIGHT);
    return wd;
}

static void save_fleche(entity_t *entity)
{
    button_t *plus = NULL;
    button_t *minus = NULL;
    button_t *up = NULL;
    button_t *down = NULL;

    entity->array[RIGHT] = make_right_button(plus, FLECHE_RIGHT);
    entity->array[LEFT] = make_left_button(minus, FLECHE_LEFT);
    entity->array[UP] = make_up_button(up, FLECHE_UP);
    entity->array[DOWN] = make_down_button(down, FLECHE_DOWN);
}

static entity_t init_button(void)
{
    button_t *button = NULL;
    button_t *loop_plus = NULL;
    button_t *loop_minus = NULL;
    button_t *edit = NULL;
    button_t *grill = NULL;
    entity_t entity = {0};

    entity.array = malloc(sizeof(button_t *) * SIZE);
    entity.array[METEO] = make_button_one(button, DAY);
    save_fleche(&entity);
    entity.array[ZOOM_PLUS] = make_loop_plus(loop_plus, LOOP_PLUS);
    entity.array[ZOOM_MINUS] = make_loop_minus(loop_minus, LOOP_MINUS);
    entity.array[EDIT] = make_edit(edit, EDIT_MODE);
    entity.array[GRID] = make_grill(grill, GRILL_ON);
    entity.array[END] = NULL;
    return entity;
}

static void destroy_button(entity_t *entity)
{
    for (int i = 0; entity->array[i] != NULL; i++) {
        sfRectangleShape_destroy(entity->array[i]->rect);
        sfTexture_destroy(entity->array[i]->texture);
        free(entity->array[i]);
    }
    free(entity->array);
}

static void draw_all(entity_t entity, window_t *wd, map2d_t *map)
{
    draw_map(wd, map);
    draw_button(wd->window, &entity);
}

static void free_map(map2d_t *map)
{
    if (!map)
        return;
    for (int i = 0; i < map->length; i++)
        free(map->map[i]);
    free(map->map);
    free(map);
    return;
}

void main_loop(void)
{
    window_t *wd = init_window();
    map2d_t *map = NULL;
    map3d_t *map_3d = create_3d_map(SIZE, SIZE);
    entity_t entity = init_button();

    while (sfRenderWindow_isOpen(wd->window)){
        map = create_2d_map(map_3d, wd->angles, wd);
        sfRenderWindow_clear(wd->window, sfBlack);
        event_loop(wd, map_3d, &entity, map);
        draw_all(entity, wd, map);
        if (map_3d->editor_on == YES)
            draw_editor(wd, map_3d);
        sfRenderWindow_display(wd->window);
        free_map(map);
    }
    destroy_button(&entity);
}
