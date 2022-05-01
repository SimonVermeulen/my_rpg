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
						src/addons/translation_animation/init_translation.c	\
						src/addons/parallax/parallax.c	\
						src/addons/rect_animation/rect_animation.c	\
						src/addons/rect_animation/rect_action.c	\
						src/addons/move_view/move_view.c	\
						src/addons/move_view/view_action.c	\
						src/addons/follow_view/follow_view.c	\
						src/addons/change_scene/change_scene.c	\
						src/addons/event_manager/event_manager.c	\
						src/addons/event_manager/func_checker_event_a.c	\
						src/addons/event_manager/func_checker_event_b.c	\
						src/addons/event_manager/event_controller.c	\
						src/addons/event_manager/tick_controller.c	\
						src/addons/dialogue_manager/dialogue_manager.c	\
						src/addons/dialogue_manager/tick.c	\
						src/addons/dialogue_manager/text_animation/text_animation.c	\
						src/addons/dialogue_manager/text_animation/event.c	\
						src/addons/dialogue_manager/select_manager/event.c	\
						src/addons/dialogue_manager/select_manager/tick.c	\
						src/addons/dialogue_manager/select_manager/init.c	\
						src/addons/position_by_view/position_by_view.c	\
						src/addons/multi_enable/multi_enable.c	\
						src/addons/multi_disable/multi_disable.c	\
						src/addons/play_sound/play_sound.c	\
						src/addons/mobs_animation/mobs_animation.c	\
						src/addons/player_controller/player_controller.c	\
						src/addons/player_controller/movement.c	\
						src/addons/pokemons/pokemons.c	\
						src/addons/pokemons_animation/pokemons_animation.c	\

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
