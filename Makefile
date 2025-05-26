# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaceres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 23:00:43 by acaceres          #+#    #+#              #
#    Updated: 2025/05/26 17:02:26 by acaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIB_PATH = libft/
LIB_NAME = libft.a
LIB = $(LIB_PATH)$(LIB_NAME)

HEADERS = -I ./includes/ -I ./libft/includes/ -I./mlx_utils/includes/ -I./minilibx-linux/ -I./engine/includes/ -I./ft_math/includes/	

SRCS = 		./engine/color/color.c \
			./engine/geometry/line.c \
			./engine/geometry/point.c \
			./engine/geometry/normalize.c \
			./engine/screen/resolution.c \
			./ft_math/ft_abs.c \
			./ft_math/q_rsqrt.c \
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
			./mandatory/srcs/del_cub_ray_obj.c \
			./mandatory/srcs/distance.c \
			./mandatory/srcs/draw_circle.c \
			./mandatory/srcs/draw_grid.c \
			./mandatory/srcs/draw_normal.c \
			./mandatory/srcs/draw_player.c \
			./mandatory/srcs/draw_sky_n_ground.c \
			./mandatory/srcs/draw_square.c \
			./mandatory/srcs/editor_mode.c \
			./mandatory/srcs/frame_update.c \
			./mandatory/srcs/free_gen_struct.c \
			./mandatory/srcs/free_cub.c \
			./mandatory/srcs/ft_constructor.c \
			./mandatory/srcs/game_mode.c \
			./mandatory/srcs/get_dist_delt.c \
			./mandatory/srcs/get_pixel_img.c \
			./mandatory/srcs/get_real_position.c \
			./mandatory/srcs/intersection_between_lines.c \
			./mandatory/srcs/key_events.c \
			./mandatory/srcs/key_events_calcs_.c \
			./mandatory/srcs/key_events_utils.c \
			./mandatory/srcs/mouse_events.c \
			./mandatory/srcs/mouse_pos_relative.c \
			./mandatory/srcs/new_action_obj.c \
			./mandatory/srcs/new_cub_ray_obj.c \
			./mandatory/srcs/new_player.c \
			./mandatory/srcs/player_angle.c \
			./mandatory/srcs/print_map.c \
			./mandatory/srcs/ray_casting.c \
			./mandatory/srcs/remap_point.c \
			./mandatory/srcs/render_img.c \
			./mandatory/srcs/rotate_point.c \
			./mandatory/srcs/draw_wall.c \
			./mlx_utils/draw_line.c \
			./mlx_utils/fill_img.c \
			./mlx_utils/free_img.c \
			./mlx_utils/init_img.c \
			./mlx_utils/open_img.c \
			./mlx_utils/put_pixel.c 


OBJS = $(SRCS:%.c=build/%.o)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lXcursor -lXrender -lXfixes -lm -lz -lbsd


CC = cc

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

all: $(LIB) $(NAME) 

$(LIB): 
	@$(MAKE) -C $(LIB_PATH)

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


clean:
	@$(RM) -rf build
	@$(MAKE) clean -C ${LIB_PATH}
	@echo "${LGREEN}Objects cleaned from ${WHITE}${CURDIR}${RESET}"

fclean: clean
	${RM} $(NAME)
	${RM} $(LIB_PATH)$(LIB_NAME)
	@echo "${LRED}Binary ${LYELLOW}${NAME} ${LRED}has been deleted....${RESET}"

re: fclean all

asan: fclean
asan: CFLAGS += -g3 -fsanitize=address
asan: all

g: fclean
g: CFLAGS += -g3
g: all

.PHONY: all clean fclean re title asan g
