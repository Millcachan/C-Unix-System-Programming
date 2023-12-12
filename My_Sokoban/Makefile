##
## EPITECH PROJECT, 2023
## sokoban
## File description:
## Makefile
##

SRC     =   src/my.c\
			src/map.c\
			src/size.c\
			src/main.c\
			src/state.c\
			src/boxes.c\
			src/sokoban.c\
			src/movements.c\

OBJ	    =	$(SRC:.c=.o)

NAME    =	my_sokoban

CFLAGS  = -g -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) -lncurses

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
