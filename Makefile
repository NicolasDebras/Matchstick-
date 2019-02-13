##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compile the 103Cipher
##

SRC	=	main.c \
		tools.c \
		map.c \
		print.c \
		win.c \
		ia.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

FLAGS	=	-Wall -Wextra -lm

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
