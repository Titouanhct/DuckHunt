##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## ..
##

NAME	= liblist.a

SRC += create_list.c
SRC += pushback.c
SRC += popback.c
SRC += popfront.c
SRC += destroy_node.c

OBJ = $(SRC:.c=.o)

LDFLAGS = -L./ -llist

CFLAGS = -Wall -Wextra -I../include/ -g

all: $(NAME)

$(NAME): $(OBJ)
	ar rc liblist.a $(OBJ)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
