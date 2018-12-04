# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouza <esouza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 10:51:14 by esouza            #+#    #+#              #
#    Updated: 2018/12/04 12:52:23 by esouza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

LIBFT = libft

CC = gcc

#FLAGS = -Wall -Werror -Wextra
FLAGS = -g

SRCS =  ./src/main.c \
	   ./src/set_header.c \
		./src/strjoinappend.c \
		./src/hexatob.c \
		./src/get_data.c \
		./src/free_data.c \
		./src/error.c \
		./src/check_words.c \
		./src/l_labels.c \
		./src/l_size.c \
		./src/l_trim.c \
		./src/l_calc.c \
		./src/l_op.c \
		./src/l_args.c \
		./src/l_check.c \
		./src/l_errors.c \
		./src/op.c	\
		./src/extras.c \
		./src/create_file_body.c \


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
