##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## ..
##

NAME 	=	my_hunter

SRC =  src/main.c
SRC += src/analyse_events.c
SRC += src/create_window.c
SRC += src/display_window.c
SRC += src/clock.c
SRC += lib/my_int_str.c
SRC += lib/my_revstr.c
SRC += lib/my_strlen.c
SRC += lib/my_strcatdup.c
SRC += lib/my_strcat.c
SRC += lib/my_strcpy.c
SRC += lib/my_cat.c
SRC += lib/my_catchar.c
SRC += lib/my_getnbr.c
SRC += lib/my_strdup.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I ./include/ -g
CFLAGS += -lcsfml-graphics  -lcsfml-window -lcsfml-system -lcsfml-audio

LFLAGS = -L lib_list/ -llist -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib_list/
	gcc $(OBJ) -o $(NAME) $(LFLAGS) $(CFLAGS)

clean :
	make clean -C ./lib_list/
	rm $(OBJ)

fclean: clean
	make fclean -C ./lib_list
	rm -f $(NAME)

re: fclean all
