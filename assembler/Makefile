# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouza <esouza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 10:51:14 by esouza            #+#    #+#              #
#    Updated: 2018/11/22 14:51:03 by rfibigr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PATH = ./
NAME = asm

LIBFT = ../lib/libft
INC_PATH =	includes
OBJ_PATH =	obj
SRC_PATH =	src

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS =	main.c \
		op.c	\
		set_header.c \
		strjoinappend.c \
		hexatob.c \
		get_data.c \
		labels.c \
		size.c

OBJS = $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

all : $(NAME_PATH)$(NAME)

$(NAME_PATH)$(NAME) : $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME_PATH)$(NAME)
	@echo "\033[32;4m	   ***Executable $(NAME) created***   \033[0;m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -c $< -o $@ -I$(INC_PATH)

clean :
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME_PATH)$(NAME)

re : fclean all

.PHONY : all clean fclean re libft
