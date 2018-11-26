# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:20:20 by rfibigr           #+#    #+#              #
#    Updated: 2018/11/26 19:12:54 by rfibigr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re

#/******************* DEFINE COLOR *******************/
NC = \033[0m
RED = \033[1;31m
GREEN = \033[0;32m
LOW_GREEN = \033[1;32m
BLUE = \033[1;34m
PURPLE = \033[0;35m
WHITE = \033[1;37m
YELLOW = \033[1;33m
CYAN = \033[0;36m
BLACK = \033[0;30m
DARK_GRAY = \033[1;30m


#/******************* DIRECTORIES *******************/
SRC_PATH =	src
OBJ_PATH =	obj
INC_PATH =	include
LIB_PATH =	../lib

#/******************* COMPILATION *******************/
CC =			gcc
CFLAGS =		-Wall -Werror -Wextra

#/********************** BINARY *********************/
NAME_PATH = ../
NAME = 		our_coreware

#/********************** SOURCE *********************/
SRC =		corewar.c 	\
			check_parameters.c	\
			check_parameters2.c	\
			initialization.c 	\
			tools.c				\
			exit.c				\
			lib_list.c			\
			convert.c			\
			load_in_ram.c		\
			#where_star.c		\

LIBNAME =	libft/libft.a \

#/********************** PATH  *********************/
INCP =		$(foreach dir, $(INC_PATH), -I$(dir))
LIBP = 		$(addprefix $(LIB_PATH)/,$(LIBNAME))
OBJ	 =		$(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

###################################################
#/********************** RULES *********************/

all : $(NAME_PATH)$(NAME)

$(NAME_PATH)$(NAME) : $(OBJ)
	@echo "$(LOW_GREEN) --Compiling lib--\tlibft"
	@make -C $(LIB_PATH)/libft
	@echo "$(PURPLE) --Linking--\t\t$(NAME)"
	$(CC) -o $@ $^ $(LIBP)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@echo "$(GREEN) --Compiling--\t\t$(NAME)"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

clean :
	@echo "$(RED) --Cleaning--\t\tobject folder"
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED) --Cleaning--\t\tlibrary libft"
	@make clean -C $(LIB_PATH)/libft

fclean : clean
	@echo "$(RED) --Cleaning--\t\texecutable"
	@rm -rf $(NAME_PATH)$(NAME)
	@make fclean -C $(LIB_PATH)/libft

re: fclean all

debug : $(OBJ)
	@echo "$(PURPLE) --Linking--\t\t"
	$(CC) -o $(NAME) $^ $(LIBP) -fsanitize=address -O1 -fno-omit-frame-pointer
