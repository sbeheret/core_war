# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouza <esouza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 10:51:14 by esouza            #+#    #+#              #
#    Updated: 2018/12/05 09:31:29 by esouza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PATH = ../
NAME = asm

LIBFT = ../lib/libft
INC_PATH =	includes
OBJ_PATH =	obj
SRC_PATH =	src

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

SRCS =	main.c \
		check_words.c \
		error.c \
		extras.c \
		free_data.c \
		ft_strchr_no_zero.c \
		get_data.c \
		hexatob.c \
		l_args.c \
		l_calc.c \
		l_check.c \
		l_errors.c \
		l_labels.c \
		l_op.c \
		l_size.c \
		l_trim.c \
		op.c \
		set_header.c \
		strjoinappend.c \
		create_file_body.c \


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

.PHONY : all clean fclean re libf
