# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 01:22:18 by samusanc          #+#    #+#              #
#    Updated: 2024/08/10 23:02:21 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
COMMIT_D	:= $(shell date)
COMMIT_U	:= ${USER}

#=============================== INCLUDES ===============================#

INC			= -I./includes/ 
INC			+= -I./libft/ 
INC			+= -I./mlx_utils/ 
INC			+= -I./mlx_utils/includes/ 
INC			+= -I./T-Engine/ 
INC			+= -I./T-Engine/includes/ 
INC			+= -I./ft_math/
INC			+= -I./ft_math/includes/
INC			+= -I/usr/include -O3 -I./minilibx-linux/ 

#============================== LIBRARIES ===============================#

SUBMODLIB	= ./libft/libft.a
SUBMODLIB	+= ./T-Engine/libT_Engine.a
SUBMODLIB	+= ./ft_math/libft_math.a
SUBMODLIB	+= ./mlx_utils/libmlx_utils.a

#================================= GCC ==================================#

# GCC WITH LIBS AND INCLUDES
CFLAGS		= -Wextra -fsanitize=address
CFLAGS		+= -mavx
CC			= gcc $(CFLAGS) $(INC)

#================================= SCRS =================================#

SRCS		= \
				./mandatory/main.c \
				./mandatory/parsing/check_file.c \
				./mandatory/parsing/check_map.c \
				./mandatory/parsing/check_path.c \
				./mandatory/parsing/check_player.c \
				./mandatory/parsing/check_textures.c \
				./mandatory/parsing/clean_close.c \
				./mandatory/parsing/fill_map.c \
				./mandatory/parsing/fill_textures.c \
				./mandatory/parsing/ft_is_space.c \
				./mandatory/parsing/init_parsing.c \
				./mandatory/parsing/map.c \
				./mandatory/parsing/parse_color.c \
				./mandatory/parsing/parse_map.c \
				./mandatory/parsing/parsing.c \
				./mandatory/parsing/player_dir.c \
				./mandatory/parsing/print_error.c \

#================================= OBJS =================================#

O_DIR		= ./objects/
OBJS		= $(addprefix $(O_DIR)/, $(SRCS:.c=.o))

#========================================================================#

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -D BONUS=1 $(INC) -g -c $< -o $(O_DIR)/$(<:.c=.o)
	@echo ""

all: title submodules $(NAME)
	@echo "===================================="
	@echo ""
	@echo "usage: $$./cub3d map.cub"

$(NAME): .mandatory
	@echo "mandatory done..."

title:
	@echo "===================================="
	@echo " _____ _   _______  ___________ "
	@echo "/  __ \\ | | | ___ \\|____ |  _  \\"
	@echo "| /  \\/ | | | |_/ /    / / | | |"
	@echo "| |   | | | | ___ \    \\ \\ | | |"
	@echo "| \\__/\\ |_| | |_/ /.___/ / |/ / "
	@echo " \\____/\\___/\\____/ \\____/|___/  "
	@echo ""
	@echo "===================================="
	@echo "Graphics:samusanc, Parsing:afelicia"
	@echo ""

#============================= GIT RULES ==============================#

add: fclean 
	@-git pull
	@git add .

commit: add
	@echo "" >> .TODO
	@cp .TODO .TODO.tmp
	sed -i '1s/^/$(COMMIT_D) by $(COMMIT_U)\n/' .TODO.tmp
	echo "======================= end of git description" >> .TODO.tmp
	git commit -F .TODO.tmp 
	@rm -rf .TODO.tmp

push: commit
	git push


#======================= MANDATORY AND BONUS =========================#

.mandatory: .mlx submodules $(OBJS)
	@make -sC ./minilibx-linux/ all
	$(CC) -o $(NAME) $(OBJS) $(SUBMODLIB) -L./minilibx-linux/ -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
	@touch .mandatory

.mlx:
	@make -sC ./minilibx-linux/ all
	@touch .mlx

re: fclean all

.submod:
	@make -sC ./mlx_utils/ all
	@make -sC ./libft/ all
	@make -sC ./T-Engine/ all
	@make -sC ./ft_math/ all
	@touch .submod


submodules: .submod
	@echo all submodules done

fclean: clean
	@echo "cleaning binaries..."
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus
	@rm -rf .bonus
	@rm -rf .mandatory
	@rm -rf .clean
	@rm -rf .mlx
	@rm -rf .submod


clean: .clean
	@echo "objects removed!"

.clean: .mlx 
	@echo "cleaning objects..."
	@make -sC ./minilibx-linux/ clean
	@rm -f $(OBJS)
	@rm -f $(B_OBJS)
	@rm -rf $(O_DIR)
	@rm -rf $(B_O_DIR)
	@touch .clean

.PHONY: all clean fclean re title  add commit push
