##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC = 			main.c							\
				src/main_loop.c					\

SRC_MAP	=		src/maps/create_2d_map.c		\
				src/maps/create_3d_map.c		\
				src/maps/create_map_line.c		\
				src/maps/find_tile_color.c		\
				src/maps/get_selected_point.c	\
				src/draw_map.c					\

SRC_TOOLBAR	=	src/toolbar/make_button/make_button.c		\
				src/toolbar/make_button/make_loop_button.c	\
				src/toolbar/mouse_button.c					\
				src/toolbar/set_button.c					\

SRC_EVENT	=	src/events/loop.c				\
				src/events/rotation.c			\
				src/events/clicked_button.c		\
				src/events/edit_mode.c			\

SRC += $(SRC_MAP)	$(SRC_TOOLBAR)	$(SRC_EVENT)

OBJ = $(SRC:.c=.o)

CPPFLAGS = -iquote ./include/

CFLAGS = -Wall -Wextra

LDLIBS =

LDFLAGS = -lm -lcsfml-graphics -lcsfml-window

NAME = my_world

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)  $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

debug: CPPFLAGS += -g3
debug: all

re: fclean all
