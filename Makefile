# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Andie <Andie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 01:22:18 by samusanc          #+#    #+#              #
#    Updated: 2025/05/24 17:34:42 by acaceres         ###   ########.fr        #
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
SRCS = $(shell find mandatory mlx_utils T-Engine ft_math -type f -name "*.c")

#create object files
OBJS = $(SRCS:%.c=build/%.o)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

CFLAGS = -Wall -Werror -Wextra #-mavx #-ggbd3 #-fsanitize=address
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

title: 
	@echo " ----------------------------------------------- "
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
	@echo " ----------------------------------------------- "

#compiles both the lib and the program
all: $(LIB) $(NAME)

$(LIB): 
	@$(MAKE) -C $(LIB_PATH)

#compiles the program by linking the object files with the libraries and outputting an ex file
$(NAME): $(OBJS)

	@mkdir -p build
	@echo "${LCYAN}Making.....$@${RESET}"
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB) $(LDFLAGS) $(HEADERS)
	@printf "${GREEN}Done!${RESET}\n"
	@echo "usage: $$./cub3d map.cub"


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
