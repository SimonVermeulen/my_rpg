##
## EPITECH PROJECT, 2021
## B-CPE-110-TLS-1-1-BSQ-younes1.bahri
## File description:
## Makefile
##

SRC				=		src/index.c	\
						src/addon.c	\

OBJ 			=		$(SRC:.c=.o)

NAME 			= 		my_defender

LIBFLAG 		= 		lib/game_engine.a -Lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio lib/liblist.a lib/libjson_parser.a lib/libmy.a -lm

CFLAGS 			+= 		-I ./include -g3

all:	$(NAME)

$(NAME): 	$(OBJ)
		$(MAKE) -C ./lib/game_engine
		$(MAKE) -C ./lib/my
		$(MAKE) -C ./lib/linked_list
		$(MAKE) -C ./lib/json_parser
		$(CC) -o $(NAME) $(OBJ) $(LIBFLAG)

clean:
		$(MAKE) -C ./lib/game_engine clean
		$(MAKE) -C ./lib/my clean
		$(MAKE) -C ./lib/linked_list clean
		$(MAKE) -C ./lib/json_parser clean
		rm -f $(OBJ)

fclean:	clean
		$(MAKE) -C ./lib/game_engine fclean
		$(MAKE) -C ./lib/my fclean
		$(MAKE) -C ./lib/linked_list fclean
		$(MAKE) -C ./lib/json_parser fclean
		rm -rf $(NAME)

re: fclean all
