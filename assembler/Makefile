# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouza <esouza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 10:51:14 by esouza            #+#    #+#              #
#    Updated: 2018/12/04 16:06:36 by esouza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PATH = ./
NAME = asm

LIBFT = libft

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
		op.c	\
		set_header.c \
		strjoinappend.c
		create_file_body.c \


OBJS = $(SRCS:.c=.o)

all : $(LIBFT) $(NAME)

$(LIBFT) :
	@make -C $(LIBFT)

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)
	@echo "\033[32;4m	   ***Executable $(NAME) created***   \033[0;m"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@make clean -C $(LIBFT)
	@rm -f $(OBJS)
fclean :
	@make clean -C $(LIBFT)
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re libft
