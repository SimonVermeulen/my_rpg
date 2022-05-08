##
## EPITECH PROJECT, 2022
## my_defender
## File description:
## Makefile
##

SRC	=	addon/addon.c	\
		addon/event/on_end.c	\
		addon/event/on_start.c	\
		addon/load_addons.c	\
		engine/window/controller/window_on_event.c	\
		engine/window/controller/window_on_tick.c	\
		engine/window/open_game.c	\
		engine/engine.c	\
		engine/functions.c	\
		engine/time.c	\
		entity/settings/bounds/get_bounds.c	\
		entity/settings/color/color.c	\
		entity/settings/fill_color/fill_color.c	\
		entity/settings/origin/origin.c	\
		entity/settings/outline_color/outline_color.c	\
		entity/settings/outline_thickness/outline_thickness.c	\
		entity/settings/point/point.c	\
		entity/settings/point_count/point_count.c	\
		entity/settings/position/get_position.c	\
		entity/settings/position/set_position.c	\
		entity/settings/radius/radius.c	\
		entity/settings/rotation/rotation.c	\
		entity/settings/scale/scale.c	\
		entity/settings/size/size.c	\
		entity/settings/sound/3d_parameter.c	\
		entity/settings/sound/player.c	\
		entity/settings/sound/sound.c	\
		entity/settings/text/string.c	\
		entity/settings/text/style.c	\
		entity/settings/texture/texture.c	\
		entity/init_data_entity.c	\
		entity/init_entity.c	\
		events/click_pressed.c	\
		events/click_released.c	\
		events/get_mouse_position.c	\
		events/key.c	\
		events/scroll.c	\
		object/collision/check_collision.c	\
		object/collision/destroy_collision.c	\
		object/collision/detection_collision.c	\
		object/collision/init_collision.c	\
		object/collision/is_hover.c	\
		object/collision/is_trigger.c	\
		object/collision/if_collision.c	\
		object/event/on_active.c	\
		object/create_object_list.c	\
		object/object.c	\
		object/seach_object.c	\
		print/print.c	\
		scene/buffer/components/init_color.c	\
		scene/buffer/components/init_font.c	\
		scene/buffer/components/init_music.c	\
		scene/buffer/components/init_soundbuffer.c	\
		scene/buffer/components/init_texture.c	\
		scene/buffer/buffer.c	\
		scene/buffer/init_buffer.c	\
		scene/init_scene/init_objects_list.c	\
		scene/init_scene/init_scene.c	\
		scene/init_scene/init_scenes_path.c	\
		scene/scene.c	\
		utils/equal_vector.c	\
		utils/get_normalize_vector.c	\
		utils/create_vector_list.c	\
		utils/equal_prov.c	\
		utils/vector_distance.c	\
		utils/sleep.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I../../include -Wall -Wextra -pedantic -g3

LFLAGS =	-L./lib -llibma -llist -llibjson_parser

NAME	=	game_engine.a

#------------------------------

all:	$(NAME)

$(NAME): $(OBJ)
	ar -ro $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm	-f $(OBJ)

fclean: clean
	rm	-f $(NAME)
	rm	-f ../$(NAME)

re: fclean all

.PHONY: re fclean clean fclean_lib clean_lib build build_lib all
