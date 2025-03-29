/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** header
*/

#ifndef WORLD
    #define WORLD
    #include <SFML/Graphics.h>
    #define WIDTH 1920
    #define HEIGTH 1080
    #define BPS 32
    #define NO -1
    #define YES 1
    #define PI 3.14159265358979323846
    #define NB_ALT 4
    #define MAX_ZOOM 100
    #define MIN_ZOOM 10
    #define MAX_LENGTH 90
    #define MIN_LENGTH 2
    #define MAX_WIDTH 120
    #define MIN_WIDTH 2
    #define ANGLE_X 0.0
    #define ANGLE_Y 56.0
    #define EDITOR_LEN 700
    #define MAX_HEIGHT 60
    #define MIN_HEIGHT -60
    #define MIN_HEIGHT_MAX -30
    #define MIDDLE_LOW_MIN -29
    #define MIDDLE_LOW_MAX 1
    #define MIDDLE_HIGHT_MIN 2
    #define MIDDLE_HIGHT_MAX 30
    #define MIN_MAX 31
    #define METEO 0
    #define LEFT 1
    #define RIGHT 2
    #define UP 3
    #define DOWN 4
    #define ZOOM_PLUS 5
    #define ZOOM_MINUS 6
    #define EDIT 7
    #define GRID 8
    #define END 9
    #define SIZE 10
    #define THICKNESS 5.0
    #define UNUSED __attribute__((unused))

typedef enum {
    DAY,
    NIGHT,
    SNOW,
    FLECHE_LEFT,
    FLECHE_RIGHT,
    FLECHE_UP,
    FLECHE_DOWN,
    LOOP_PLUS,
    LOOP_MINUS,
    EDIT_MODE,
    GRILL_ON
} color_day_t;


static const char *const TEXTURE_BUTTON_ONE[] = {
    "./image/sun.jpg", "./image/night.jpg", "./image/snoww.jpeg",
    "./image/fleche_left.png", "./image/fleche_plus.png",
    "./image/fleche_up.png", "./image/fleche_bas.png",
    "./image/plus.png", "./image/minus.png", "./image/pen.jpg",
    "./image/grid.png"};

typedef struct altitude_s {
    int minimal;
    int maximal;
    sfColor color;
} altitude_t;

typedef struct map3d_s {
    int **alt;
    int length;
    int width;
    int zoom;
    int grid_on;
    int editor_on;
    sfVector2i selected;
} map3d_t;

typedef struct point2d_s {
    sfVector2f pos;
    int altitude;
} point2d_t;

typedef struct map2d_s {
    point2d_t **map;
    int length;
    int width;
    int grid_on;
    int state;
} map2d_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfColor color[4];
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f size;
    sfTexture *texture;
    int state;
} button_t;

typedef struct all_button {
    button_t **array;
} entity_t;

static const altitude_t alt_color[3][NB_ALT] = {
        {{MIN_HEIGHT, MIN_HEIGHT_MAX, {91, 60, 17, 255}},
        {MIDDLE_LOW_MIN, MIDDLE_LOW_MAX, {0, 200, 55, 255}},
        {MIDDLE_HIGHT_MIN, MIDDLE_HIGHT_MAX, {211, 211, 0, 255}},
        {MIN_MAX, MAX_HEIGHT, {255, 255, 255, 255}}},

        {{MIN_HEIGHT, MIN_HEIGHT_MAX, {0, 0, 128, 255}},
        {MIDDLE_LOW_MIN, MIDDLE_LOW_MAX, {0, 0, 128, 255}},
        {MIDDLE_HIGHT_MIN, MIDDLE_HIGHT_MAX, {0, 0, 255, 255}},
        {MIN_MAX, MAX_HEIGHT, {0, 0, 128, 255}}},

        {{MIN_HEIGHT, MIN_HEIGHT_MAX, {255, 255, 255, 255}},
        {MIDDLE_LOW_MIN, MIDDLE_LOW_MAX, {255, 255, 255, 255}},
        {MIDDLE_HIGHT_MIN, MIDDLE_HIGHT_MAX, {192, 192, 192, 255}},
        {MIN_MAX, MAX_HEIGHT, {255, 255, 255, 255}}}
};


typedef struct image_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect area;
} image_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfIntRect area;
    image_t background;
    sfVector2f angles;
} window_t;

void main_loop(void);

//set button
int set_button_size(button_t *button, sfVector2f pos, sfVector2f size);
int set_color_button(button_t *button, sfColor color_fill,
    sfColor outline_color, float thickness);
sfText *set_text(char *title, char *font_choosen,
    sfColor color_text, sfVector2f pos);
button_t *set_texture_button(button_t *button, int image);

//event
int update_meteo(int state);
void event_loop(window_t *wd, map3d_t *map,
    entity_t *entity, map2d_t *map_point);
void rotation(window_t *wd);
void edit_mode(entity_t *entity, sfRenderWindow *window,
    sfEvent event, map3d_t *map);
void display_grill(entity_t *entity, sfRenderWindow *window,
    sfEvent event, map3d_t *map);

//map

void update_3d_map(map3d_t *map3D, int nlenght, int nwidth);
map3d_t *create_3d_map(int lenght, int width);
map2d_t *create_2d_map(map3d_t *map, sfVector2f angles, window_t *wd);
int is_point_closer(map3d_t *map3d, window_t *wd);
double get_mouse_distance(sfVector2i mouse, sfVector2f point);
//draw

void update_map(map2d_t *map2D, map3d_t *map3D, window_t *wd);
void draw_editor(window_t *wd, map3d_t *map);
void draw_map(window_t *wd, map2d_t *map);
sfColor get_tile_color(map2d_t *map, int x, int y);
sfConvexShape *create_line(sfVector2f p1, sfVector2f p2,
    sfVector2f p3, sfVector2f p4);


//make button
int mouse_inside(button_t *button, sfRenderWindow *window);
void change_size_button(button_t *button, sfRenderWindow *window);
button_t *set_texture_button(button_t *button, int image);
int button_clicked(sfEvent event);
button_t *make_button_one(button_t *button, int image);
button_t *make_right_button(button_t *plus, int image);
button_t *make_left_button(button_t *minus, int image);
button_t *make_up_button(button_t *up, int image);
button_t *make_down_button(button_t *down, int image);
button_t *make_loop_minus(button_t *loop_minus, int image);
button_t *make_loop_plus(button_t *loop_plus, int image);
button_t *make_edit(button_t *edit, int image);
button_t *make_grill(button_t *edit, int image);

//event button

void change_meteo(entity_t *meteo, sfRenderWindow *window,
    sfEvent event, map2d_t *map);
void change_size(entity_t *entity, sfRenderWindow *window,
    sfEvent event, map3d_t *map);
int draw_button(sfRenderWindow *window, entity_t *entity);
void zoom_map(entity_t *entity, sfRenderWindow *window,
    sfEvent event, map3d_t *map);
#endif
