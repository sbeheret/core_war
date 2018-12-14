# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouza <esouza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 10:51:14 by esouza            #+#    #+#              #
#    Updated: 2018/12/14 14:59:23 by dshults          ###   ########.fr        #
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

OBJS = $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

HDRS = $(addprefix $(INC_PATH)/,asm.h ft_printf.h get_next_line.h libft.h op.h)

all : $(NAME_PATH)$(NAME)

$(NAME_PATH)$(NAME) : $(OBJS) $(HDRS) Makefile
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME_PATH)$(NAME)
	@echo "\033[32;4m	   ***Executable $(NAME) created***   \033[0;m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(HDRS) Makefile
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -c $< -o $@ -I$(INC_PATH)

clean :
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME_PATH)$(NAME)

debug : $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME_PATH)$(NAME) -fsanitize=address -O1 -fno-omit-frame-pointer
	@echo "\033[32;4m	   ***Executable DEBUG $(NAME) created***   \033[0;m"

re : fclean all

.PHONY : all clean fclean re libf
