##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =   src/main.c\
            src/my_ls.c\
            src/flag_l.c\
            src/linked_list.c\
            src/my_show_list.c\
            src/my_sort_list.c\
            src/my_sort_time.c\
            src/put_functions.c\
            src/get_functions.c\
            src/my_str_to_word_array.c\

OBJ	    =	$(SRC:.c=.o)

NAME    =	my_ls

CFLAGS  = -g -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
