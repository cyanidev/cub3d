# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 01:22:18 by samusanc          #+#    #+#              #
#    Updated: 2024/08/10 22:14:03 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft_math.a
COMMIT_D	:= $(shell date)
COMMIT_U	:= ${USER}
CFLAGS		= -Wall -Wextra -Werror
INC			= -I./includes/
CC			= gcc $(CFLAGS)

SRCS		= \
		./deg2Rad.c \
		./ft_abs.c \
		./fx_angle.c \
		./fx_sin.c \
		./Q_rsqrt.c \
		./fx_cos.c 

O_DIR		= ./objects/
OBJS		= $(addprefix $(O_DIR)/, $(SRCS:.c=.o))

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INC) -g -c $< -o $(O_DIR)/$(<:.c=.o)
	@echo ""

all: title submodules $(NAME)
	@echo "===================================="
	@echo "Add the libft_math.a to your Makefile,"
	@echo " and the ft_math.h header to your includes..."

$(NAME): .mandatory
	@echo "T-Engine compilation done..."

title:
	@echo "===================================="
	@echo "		my own math lib"
	@echo "===================================="
	@echo "made by: samusanc aka Tagamydev"
	@echo "Github: https://github.com/Tagamydev/ft_math"
	@echo ""

# SUBMODULES

submodules: .submodule-init #.libft
	@echo "All submodules loaded..."

.submodule-init:
	@git submodule update --init --recursive
	@git submodule update --recursive --remote
	@touch .submodule-init

#.libft:
#	@make -sC ./libft/ all
#	@touch .libft

# GIT RULES

add: fclean .submodule-init
#	@make -sC ./libft/ add
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

# MANDATORY

.mandatory: $(OBJS)
	ar rcs $(NAME) $(OBJS) 
	@touch .mandatory

re: fclean all

fclean: clean
	@echo "cleaning binaries..."
#	@make -sC ./libft/ fclean
	@rm -f $(NAME)
	@rm -rf .mandatory
	@rm -rf .submodule-init
	@rm -rf .clean
	@rm -rf .libft

clean: .clean
	@echo "objects removed!"

.clean: .submodule-init
	@echo "cleaning objects..."
#	@make -sC ./libft/ clean
	@rm -f $(OBJS)
	@rm -rf $(O_DIR)
	@touch .clean

.PHONY: all title clean fclean re submodules add commit
