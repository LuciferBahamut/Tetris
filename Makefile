##
## EPITECH PROJECT, 2020
## tetris
## File description:
## makefile
##

NAME	=	tetris

SRC	=	src/main.c		\
		src/fill_struct.c	\
		src/fill_struct_bis.c	\
		src/gest_arg.c		\
		src/display_help.c	\
		src/display_debug.c	\
		src/sort_alpha.c	\
		src/put_debug.c		\
		src/count_tetriminos.c	\
		src/split_str.c		\
		src/count_space.c	\
		src/debug_mode.c	\
		util/my_strlen.c	\
		util/my_putchar.c	\
		util/my_putstr.c	\
		util/my_put_nbr.c	\
		util/my_strcmp.c	\
		util/my_strcmp_s.c	\
		util/my_strcpy.c	\
		util/my_strcat.c	\
		util/my_atoi.c		\
		util/write_error.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS=	-I./include/

LDFLAGS	=	-lncurses

all	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFLAGS)

debug	: 	CFLAGS += -g3
debug	:	all

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all debug clean fclean re
