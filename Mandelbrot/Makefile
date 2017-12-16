##
## Makefile for ok in /home/alexandre/Documents/start_project
##
## Made by alexandre Chamard-bois
## Login   <alexandre.chamard-bois@epitech.eu>
##
## Started on  Fri Jun  2 12:40:32 2017 alexandre Chamard-bois
## Last update Sun Aug 20 16:58:28 2017 Alexandre Chamard-bois
##

include ./include/depend.mk

SRC		= 	main.c				\
			init.c				\
			close.c				\
			input.c				\
			init_map.c			\
			map.c				\
			chunk.c				\
			camera.c			\
			mapp.c				\

MKLIB		=	make -C ./lib/

CFLAGS		+=	-I./include/ -I./lib/include/

LDFLAGS		=	-L./lib/ -lmy -lc_graph_prog_full -lm

_OBJ		=	$(SRC:.c=.o)

OBJ		=	$(patsubst %,$(ODIR)/%,$(_OBJ))

NAME		=	a.out

all		:	mkobj mlib $(NAME)

$(ODIR)/%.o	:	$(SDIR)/%.c
			$(CC) $(CFLAGS)	-c -o $@ $<

mkobj		:
			./tools/verif_odir

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean		:
			rm -f $(OBJ)
			$(MKLIB) clean

fclean		:	clean
			rm -f $(NAME)
			$(MKLIB) fclean

re		:	fclean all

mlib		:
			$(MKLIB)
