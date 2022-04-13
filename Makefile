##
## EPITECH PROJECT, 2021
## B-CPE-110-TLS-1-1-BSQ-younes1.bahri
## File description:
## Makefile
##

SRC				=		src/index.c	\
						src/addons/secondary_screen/secondary_screen.c	\
						src/addons/secondary_screen/change_secondary_screen.c	\
						src/addons/translation_animation/translation_animation.c	\
						src/addons/translation_animation/translation_action.c	\
						src/addons/set_position/set_position.c	\

OBJ 			=		$(SRC:.c=.o)

NAME 			= 		my_rpg

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
