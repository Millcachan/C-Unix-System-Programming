##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

.SILENT:

SHELL   =   /bin/bash

CPROG   =   src/main.c\
			src/navy.c\
            src/init.c\
            src/game.c\
            src/free.c\
            src/usage.c\
            src/attack.c\
			src/player.c\
			src/connect.c\
            src/parsing.c\
            src/display.c\
            src/win_lose.c\
            src/actualize.c\

CLIB    =   lib/my/my_swap.c\
            lib/my/my_isneg.c\
            lib/my/my_isnum.c\
            lib/my/my_getnbr.c\
            lib/my/my_putstr.c\
            lib/my/my_revstr.c\
            lib/my/my_strcat.c\
            lib/my/my_strcmp.c\
            lib/my/my_strcpy.c\
            lib/my/my_strstr.c\
            lib/my/my_strlen.c\
            lib/my/my_putnbr.c\
            lib/my/my_strdup.c\
            lib/my/my_puttab.c\
            lib/my/my_putchar.c\
            lib/my/my_strncat.c\
            lib/my/my_strncmp.c\
            lib/my/my_strncpy.c\
            lib/my/my_isalpha.c\
            lib/my/my_islower.c\
            lib/my/my_isupper.c\
            lib/my/my_is_prime.c\
            lib/my/my_strupcase.c\
            lib/my/my_power_rec.c\
            lib/my/my_prime_sup.c\
            lib/my/my_strlowcase.c\
            lib/my/my_isprintable.c\
            lib/my/my_square_root.c\
            lib/my/my_strcapitalize.c\
            lib/my/my_isalphanumeric.c\
            lib/my/my_str_to_word_array.c\

NAME    =   my_navy

LIB     =   libmy.a

OLIB	=	$(CLIB:.c=.o)

OPROG	=	$(CPROG:.c=.o)

CFLAGS  =   -g -Wall -Wextra -Wconversion -pedantic

all: $(LIB)

$(LIB): $(OLIB) $(OPROG)
	ar rc $(LIB) $(OLIB)
	bash -c "mv libmy.a lib/libmy.a"
	gcc -o $(NAME) $(OPROG) -L./lib -lmy
	printf "[%s] — Successfully compiled\n" $(NAME)

clean:
	rm -f $(OLIB) $(OPROG)
	rm -f coding-style-reports.log
	rm -f vgcore.*

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)
	bash -c "rm -f lib/libmy.a"

re: fclean all

.PHONY: all clean fclean re
