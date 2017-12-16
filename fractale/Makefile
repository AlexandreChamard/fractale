##
## Makefile for ok in /home/alexandre/colle1/
##
## Made by Alexandre Chamard-bois
## Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
##
## Started on  Fri Apr 21 09:33:17 2017 Alexandre Chamard-bois
## Last update Fri Apr 21 10:44:41 2017 Antoine Caullet
##

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror -I./include

SRC	=	src/main.c			\
		src/my_pow.c 			\
		src/my_putstr.c 		\
		src/my_strlen.c 		\
		src/my_getnbr.c 		\
		src/my_str_to_wordtab.c 	\
		src/parsing.c			\
		src/algo.c

OBJ	=	$(SRC:.c=.o)

NAME	=	fractals

all	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	: 	clean
		rm -f $(NAME)

re	:	fclean all
