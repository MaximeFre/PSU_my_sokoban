##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## c
##

SRC = 	source/main.c	\
		source/open_file.c	\
		source/my_putstr.c	\
		source/init.c	\
		source/loop.c	\
		source/move.c	\
		source/move_box.c	\
		source/win.c	\
		source/lose.c	\

NAME = my_sokoban

all: 	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -lncurses -Iinclude -Wall -Wextra

clean:
	rm -f $(OBJ)
	rm -f vgcore*

fclean: clean
		rm -f $(NAME)

re:		fclean all

debug:
	gcc -g -o $(NAME) $(SRC) -lncurses -Iinclude -Wall -Wextra
