##
## EPITECH PROJECT, 2020
## tetris
## File description:
## makefile
##

NAME	=	tetris

SRC	=	src/main.c		\
		src/display_help.c	\
		util/my_strlen.c	\
		util/my_putchar.c	\
		util/my_putstr.c	\
		util/my_strcmp.c	\
		util/write_error.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS=	-I./include/

all	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
