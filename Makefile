##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC =	main.c	\
	fonction_display.c	\
	fonction_window_basic.c	\
	fonction_creat_objet.c	\
	fonction_to_fil_obj.c	\
	fonction_lib.c	\
	get_file.c	\
	open_help.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-audio -Wall -Wextra
clean:
	rm -f $(OBJ)
	rm my_radar
	rm *~
fclean: clean
	rm -f $(NAME)


re:	fclean all
