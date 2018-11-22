# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 10:51:14 by esouza            #+#    #+#              #
#    Updated: 2018/11/22 12:34:31 by esouza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

LIBFT = ../lib/libft

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS = ./src/main.c \
       ./src/set_header.c  ./src/strjoinappend.c\
       ./src/hexatob.c ./src/get_data.c

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
