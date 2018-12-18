# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouza <esouza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 10:51:14 by esouza            #+#    #+#              #
#    Updated: 2018/12/18 09:25:33 by esouza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
GREEN = \033[0;32m
PURPLE = \033[0;35m

NAME_PATH = ../
NAME = asm

LIBFT = ../lib/libft
INC_PATH =	includes
OBJ_PATH =	obj
SRC_PATH =	src

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS =	main.c \
		check_words.c \
		error.c \
		free_data.c \
		ft_strchr_no_zero.c \
		ft_strndup.c \
		get_data.c \
		hexatob.c \
		l_bytes.c \
		l_check_compliance.c \
		l_check_general.c \
		l_errors.c \
		l_labels_get.c \
		l_labels_make_add.c \
		l_op_find_code.c \
		l_op_l.c \
		l_trim.c \
		set_header.c \
		strjoinappend.c \
		create_file_body.c \
		get_octet_codage.c \
		first_arg.c \
		write_direct_four.c \
		name_comment_length.c \
		long_atoi.c \

OBJS = $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

HDRS = $(addprefix $(INC_PATH)/,asm.h ft_printf.h get_next_line.h libft.h op.h)

all : $(NAME_PATH)$(NAME)

$(NAME_PATH)$(NAME) : $(OBJS) $(HDRS) Makefile $(LIBFT)/libft.a
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME_PATH)$(NAME)
	@echo "\n$(PURPLE)Executable $(NAME)\t\tdone$(NC)"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(HDRS) Makefile $(LIBFT)/libft.a
	@echo "$(GREEN)o\c"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -c $< -o $@ -I$(INC_PATH)

clean :
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	@rm -rf $(NAME_PATH)$(NAME)

debug : $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME_PATH)$(NAME) -fsanitize=address -O1 -fno-omit-frame-pointer
	@echo "\033[32;4m	   ***Executable DEBUG $(NAME) created***   \033[0;m"

re : fclean all

.PHONY : all clean fclean re libf
