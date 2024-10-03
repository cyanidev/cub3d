# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 01:22:18 by samusanc          #+#    #+#              #
#    Updated: 2024/08/10 22:17:15 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libT_Engine.a
COMMIT_D	:= $(shell date)
COMMIT_U	:= ${USER}

# SUBMODULE CHECKLIST
#	[] includes
#	[] libraries
#	[] all
#	[] fclean
#	[] clean

#=============================== INCLUDES ===============================#

# LOCAL INCLUDES
INC			= -I./includes/
# SUBMODULES INCLUDES
INC			+= -I./ft_math/
INC			+= -I./ft_math/includes/

#============================== LIBRARIES ===============================#

# SUBMODULES .a LIBRARIES
SUBMODLIB	= ./ft_math/libft_math.a

SUBMODLINK	= -L./ft_math/ -lft_math
#================================= GCC ==================================#

# GCC WITH LIBS AND INCLUDES
CFLAGS		= -Wall -Wextra -Werror
CC			= gcc $(CFLAGS) $(INC) $(SUBMODLINK)

# SRCS
SRCS		= \
			./screen/screen.c \
			./screen/resolution.c \
			./color/color.c \
			./geometry/normalize.c \
			./geometry/line.c \
			./geometry/point.c 


O_DIR		= ./objects/
OBJS		= $(addprefix $(O_DIR)/, $(SRCS:.c=.o))

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -g -c $< -o $(O_DIR)/$(<:.c=.o)
	@echo ""

all: title submodules $(NAME)
	@echo "===================================="
	@echo "Add the libT_Engine.a to your Makefile,"
	@echo " and the T_Engine.h header to your includes..."

$(NAME): .mandatory
	@echo "T-Engine compilation done..."

title:
	@echo "===================================="
	@echo "				T-Engine"
	@echo "===================================="
	@echo "made by: samusanc aka Tagamydev"
	@echo "Github: https://github.com/Tagamydev/T-Engine"
	@echo ""

#============================= SUBMODULES =============================#

submodules: .submodule-init .make_submodules
	@echo "All submodules loaded..."

.submodule-init:
	@git submodule update --init --recursive
	@git submodule update --recursive --remote
	@touch .submodule-init

.make_submodules: 
	@make -sC ./ft_math/ all
	@touch .make_submodules

#============================= GIT RULES ==============================#

add: fclean .submodule-init
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

.mandatory: submodules $(OBJS)
	@rm -rf OBJ_TMP_FOLDER
	@mkdir -p OBJ_TMP_FOLDER
	@$(foreach EXE,$(SUBMODLIB), \
		ar --output=OBJ_TMP_FOLDER -x $(EXE) ; \
	)
	ar rcs $(NAME) $(OBJS) ./OBJ_TMP_FOLDER/*.o
	@rm -rf OBJ_TMP_FOLDER
	@touch .mandatory

re: fclean all

fclean: clean submodule_fclean
	@echo "cleaning binaries..."
	@rm -f $(NAME)
	@rm -rf .mandatory
	@rm -rf .submodule-init
	@rm -rf .make_submodules
	@rm -rf .submodule_clean
	@rm -rf .clean

submodule_fclean:
	@make -sC ./ft_math/ fclean

clean: .clean
	@echo "objects removed!"

.clean: .submodule-init .submodule_clean
	@echo "cleaning objects..."
	@rm -f $(OBJS)
	@rm -rf $(O_DIR)
	@touch .clean

.submodule_clean:
	@make -sC ./ft_math/ clean
	@touch .submodule_clean

.PHONY: all clean fclean re title submodules submodule_fclean add commit push
