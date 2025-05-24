# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Andie <Andie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 01:22:18 by samusanc          #+#    #+#              #
#    Updated: 2025/05/24 22:27:19 by afelicia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#Program Name
NAME = cub3D

#libft
LIB_PATH = libft/
LIB_NAME = libft.a
LIB = $(LIB_PATH)$(LIB_NAME)

#headers
HEADERS = -I ./includes/ -I ./libft/ -I./mlx_utils/includes/ -I./minilibx-linux/ -I./T-Engine/includes/ -I./ft_math/includes/	

#sources (command find to locate all source files in folders)
SRCS = 		./T-Engine/color/color.c \
			./T-Engine/geometry/line.c \
			./T-Engine/geometry/point.c \
			./T-Engine/geometry/normalize.c \
			./T-Engine/screen/screen.c \
			./T-Engine/screen/resolution.c \
			./ft_math/ft_abs.c \
			./ft_math/Q_rsqrt.c \
			./mandatory/controls/hooks.c \
			./mandatory/main.c \
			./mandatory/main_utils.c \
			./mandatory/parsing/check_file.c \
			./mandatory/parsing/check_map.c \
			./mandatory/parsing/check_path.c \
			./mandatory/parsing/check_player.c \
			./mandatory/parsing/check_textures.c \
			./mandatory/parsing/clean_close.c \
			./mandatory/parsing/fill_map.c \
			./mandatory/parsing/fill_textures.c \
			./mandatory/parsing/fill_structure.c \
			./mandatory/parsing/ft_is_space.c \
			./mandatory/parsing/init_parsing.c \
			./mandatory/parsing/map.c \
			./mandatory/parsing/parse_color.c \
			./mandatory/parsing/parse_map.c \
			./mandatory/parsing/parsing.c \
			./mandatory/parsing/free_textures.c \
			./mandatory/parsing/player_dir.c \
			./mandatory/parsing/print_error.c \
			./mandatory/srcs/calculate_deltas.c \
			./mandatory/srcs/calculate_x.c \
			./mandatory/srcs/calculate_y.c \
			./mandatory/srcs/check_limits.c \
			./mandatory/srcs/check_wall_in_map.c \
			./mandatory/srcs/clean_pixels.c \
			./mandatory/srcs/color.c \
			./mandatory/srcs/compare_dists.c \
			./mandatory/srcs/cross_2d.c \
			./mandatory/srcs/cub_cast_ray.c \
			./mandatory/srcs/cub_cast_ray_angles.c \
			./mandatory/srcs/cub_cast_ray_utils.c \
			./mandatory/srcs/dda_check_map.c \
			./mandatory/srcs/default_node_free.c \
			./mandatory/srcs/del_cub_ray_obj.c \
			./mandatory/srcs/distance.c \
			./mandatory/srcs/draw_circle.c \
			./mandatory/srcs/draw_grid.c \
			./mandatory/srcs/draw_normal.c \
			./mandatory/srcs/draw_player.c \
			./mandatory/srcs/draw_sky_n_ground.c \
			./mandatory/srcs/draw_square.c \
			./mandatory/srcs/editor_mode.c \
			./mandatory/srcs/engine.c \
			./mandatory/srcs/error_handling.c \
			./mandatory/srcs/frame_update.c \
			./mandatory/srcs/free_gen_struct.c \
			./mandatory/srcs/ft_constructor.c \
			./mandatory/srcs/game_mode.c \
			./mandatory/srcs/get_dist_delt.c \
			./mandatory/srcs/get_pixel_img.c \
			./mandatory/srcs/get_real_position.c \
			./mandatory/srcs/intersection_between_lines.c \
			./mandatory/srcs/key_events.c \
			./mandatory/srcs/key_events_calcs_.c \
			./mandatory/srcs/key_events_utils.c \
			./mandatory/srcs/list_insert.c \
			./mandatory/srcs/mouse_events.c \
			./mandatory/srcs/mouse_pos_relative.c \
			./mandatory/srcs/new_action_obj.c \
			./mandatory/srcs/new_cub_ray_obj.c \
			./mandatory/srcs/new_engine_game_mode.c \
			./mandatory/srcs/new_input_mapping_obj.c \
			./mandatory/srcs/new_obj_engine_obj.c \
			./mandatory/srcs/new_player.c \
			./mandatory/srcs/player_angle.c \
			./mandatory/srcs/print_map.c \
			./mandatory/srcs/ray_casting.c \
			./mandatory/srcs/remap_point.c \
			./mandatory/srcs/render_img.c \
			./mandatory/srcs/rotate_point.c \
			./mandatory/srcs/draw_wall.c \
			./mlx_utils/drawLine.c \
			./mlx_utils/fillImg.c \
			./mlx_utils/freeImg.c \
			./mlx_utils/initImg.c \
			./mlx_utils/mlx_main.c \
			./mlx_utils/openImg.c \
			./mlx_utils/putPixel.c 


#create object files
OBJS = $(SRCS:%.c=build/%.o)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address #-mavx #-ggbd3
LDFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lXcursor -lXrender -lXfixes -lm -lz -lbsd


#compiler
CC = gcc

#force remove
RM = rm -f

#########################COLORS####################################

BLACK =	\033[0;30m
RED	=	\033[0;31m
GREEN =	\033[0;32m
YELLOW =	\033[0;33m
BLUE  =	\033[0;34m
MAGENTA =	\033[0;35m
CYAN =	\033[0;36m
LGRAY = \033[0;37m
DGRAY = \033[1;30m
LBLUE = \033[1;34m
LGREEN = \033[1;32m
LCYAN = \033[1;36m
LRED = \033[1;31m
LMAGENTA =\033[1;35m
LYELLOW = \033[1;33m
WHITE = \033[1;37m
RESET = \033[0m

###################################################################

#compiles both the lib and the program
all: $(LIB) $(NAME) 

$(LIB): 
	@$(MAKE) -C $(LIB_PATH)

#compiles the program by linking the object files with the libraries and outputting an ex file
$(NAME): $(OBJS)

	@mkdir -p build
	@echo "${LCYAN}Making...............$@${RESET}"
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB) $(LDFLAGS) $(HEADERS)
	@echo "${GREEN}.....Done!  ✨${RESET}\n"
	@echo "${LBLUE}----------------------------------------------- "
	@echo "  ______   __    __  _______    ______   _______  "
	@echo " /      \ /  |  /  |/       \  /      \ /       \ "
	@echo "/000000  |00 |  00 |0000000  |/000000  |0000000  |"
	@echo "00 |  00/ 00 |  00 |00 |__00 |00 ___00 |00 |  00 |"
	@echo "00 |      00 |  00 |00    00<   /   00< 00 |  00 |"
	@echo "00 |   __ 00 |  00 |0000000  | _00000  |00 |  00 |"
	@echo "00 \__/  |00 \__00 |00 |__00 |/  \__00 |00 |__00 |"
	@echo "00    00/ 00    00/ 00    00/ 00    00/ 00    00 "
	@echo " 000000/   000000/  0000000/   000000/  0000000/  "
	@echo "                                                  "
	@echo " ----------------------------------------------- ${RESET}\n"
	@echo "${RED}  👉 usage: $$./cub3D map.cub${RESET}\n"


#removes all objects files
clean:
	@$(RM) -rf build
	@$(MAKE) clean -C ${LIB_PATH}
	@echo "${LGREEN}Objects cleaned from ${WHITE}${CURDIR}${RESET}"

#calls the clean rule also removes executable file
fclean: clean
	${RM} $(NAME)
	${RM} $(LIB_PATH)$(LIB_NAME)
	@echo "${LRED}Binary ${LYELLOW}${NAME} ${LRED}has been deleted....${RESET}"

#removes all and compiles program
re: fclean all



#Defines a list of targets that do not correspond to files(make will always 
#execute the recipes for these targets, even if there are files or directories
#with the same names)
.PHONY: all clean fclean re title
