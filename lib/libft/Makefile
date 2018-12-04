# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:20:20 by rfibigr           #+#    #+#              #
#    Updated: 2018/11/28 17:07:02 by sbeheret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re

#/******************* DIRECTORIES *******************/
SRC_PATH			=	src/
SRC_PATH_FT_PRINTF	=	src/ft_printf
SRC_PATH_LIST 		=	src/list
SRC_PATH_MEMORY		=	src/memory
SRC_PATH_NUMBER		=	src/number
SRC_PATH_PRINT		=	src/print
SRC_PATH_READ		=	src/read
SRC_PATH_STRING		=	src/string
SRC_PATH_TEST_IS	=	src/test_is

OBJ_PATH			=	obj
OBJ_PATH_FT_PRINTF	=	obj/ft_printf
OBJ_PATH_LIST		=	obj/list
OBJ_PATH_MEMORY		=	obj/memory
OBJ_PATH_NUMBER		=	obj/number
OBJ_PATH_PRINT		=	obj/print
OBJ_PATH_READ		=	obj/read
OBJ_PATH_STRING		=	obj/string
OBJ_PATH_TEST_IS	=	obj/test_is

INC_PATH =	include

#/******************* COMPILATION *******************/
CC =			gcc
CFLAGS =		-Wall -Werror -Wextra

#/********************** BINARY *********************/
NAME = libft.a

#/********************** SOURCE *********************/
SRC_FT_PRINTF	=	ft_printf.c \
					str_read.c	\
					str_verif.c \
					assign_modifier.c \
					padding_before.c \
					modifier_di_1.c \
					modifier_di_2.c \
					modifier_oux_1.c \
					modifier_oux_2.c \
					modifier_p_percent.c \
					modifier_sc.c \
					modifier_sc_cap.c \
					print_intmax.c \
					print_numbers.c \
					print_sizet.c \
					print_byte.c \
					write_buffer.c \
					tool.c \
					tool2.c \

SRC_LIST =			ft_list_clear.c \
					ft_list_last.c \
					ft_list_push_back_cpy.c \
					ft_list_push_back.c \
					ft_list_push_front.c \
					ft_list_size.c \
					ft_lstadd.c \
					ft_lstdel.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstnew.c \
					ft_lstnewcpy.c \

SRC_MEMORY =		ft_bzero.c \
					ft_memalloc.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memdel.c \
					ft_memmove.c \
					ft_memset.c \

SRC_NUMBER =		ft_itoa.c \
					ft_itoa_base.c \
					ft_lgnbr.c \
					ft_abs.c \

SRC_PRINT =			ft_putchar.c\
					ft_putchar_fd.c\
					ft_putendl_fd.c\
					ft_putendl.c\
					ft_putnbr_fd.c\
					ft_putnbr.c\
					ft_putstr_fd.c\
					ft_putstr.c\

SRC_READ = 			get_next_line.c\

SRC_STRING =		ft_atoi.c\
					ft_strcat.c\
					ft_strchr.c\
					ft_strclr.c\
					ft_strcmp.c\
					ft_strcpy.c\
					ft_strdel.c\
					ft_strdup.c\
					ft_strequ.c\
					ft_striter.c\
					ft_strjoin.c\
					ft_strlcat.c\
					ft_strlen.c\
					ft_strmap.c\
					ft_strmapi.c\
					ft_strncat.c\
					ft_strncmp.c\
					ft_strncpy.c\
					ft_strnequ.c\
					ft_strnew.c \
					ft_strnstr.c\
					ft_strrchr.c\
					ft_strrev.c\
					ft_strsplit.c\
					ft_strstr.c\
					ft_strsub.c\
					ft_strtrim.c\
					ft_tolower.c\
					ft_toupper.c\

SRC_TEST_IS =		ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_isprint.c\
					ft_isnumber.c\
					ft_isinteger.c \


#/********************** PATH  *********************/
INCP =				$(foreach dir, $(INC_PATH), -I$(dir))

OBJ_FT_PRINTF =		$(addprefix $(OBJ_PATH_FT_PRINTF)/,$(SRC_FT_PRINTF:.c=.o))
OBJ_LIST =			$(addprefix $(OBJ_PATH_LIST)/,$(SRC_LIST:.c=.o))
OBJ_MEMORY =		$(addprefix $(OBJ_PATH_MEMORY)/,$(SRC_MEMORY:.c=.o))
OBJ_NUMBER =		$(addprefix $(OBJ_PATH_NUMBER)/,$(SRC_NUMBER:.c=.o))
OBJ_PRINT =			$(addprefix $(OBJ_PATH_PRINT)/,$(SRC_PRINT:.c=.o))
OBJ_READ =			$(addprefix $(OBJ_PATH_READ)/,$(SRC_READ:.c=.o))
OBJ_STRING =		$(addprefix $(OBJ_PATH_STRING)/,$(SRC_STRING:.c=.o))
OBJ_TEST_IS =		$(addprefix $(OBJ_PATH_TEST_IS)/,$(SRC_TEST_IS:.c=.o))

###################################################
#/********************** RULES *********************/

all : $(NAME)

$(NAME) : $(OBJ_FT_PRINTF) $(OBJ_LIST) $(OBJ_MEMORY) $(OBJ_NUMBER) $(OBJ_PRINT) $(OBJ_READ) $(OBJ_STRING) $(OBJ_TEST_IS)
	@ar rc $(NAME) $(OBJ_FT_PRINTF) $(OBJ_LIST) $(OBJ_MEMORY) $(OBJ_NUMBER) $(OBJ_PRINT) $(OBJ_READ) $(OBJ_STRING) $(OBJ_TEST_IS)
	@ranlib $(NAME)

$(OBJ_PATH_FT_PRINTF)/%.o: $(SRC_PATH_FT_PRINTF)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH_FT_PRINTF) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

$(OBJ_PATH_LIST)/%.o: $(SRC_PATH_LIST)/%.c
	@mkdir $(OBJ_PATH_LIST) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

$(OBJ_PATH_MEMORY)/%.o: $(SRC_PATH_MEMORY)/%.c
	@mkdir $(OBJ_PATH_MEMORY) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

$(OBJ_PATH_NUMBER)/%.o: $(SRC_PATH_NUMBER)/%.c
	@mkdir $(OBJ_PATH_NUMBER) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

$(OBJ_PATH_PRINT)/%.o: $(SRC_PATH_PRINT)/%.c
	@mkdir $(OBJ_PATH_PRINT) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

$(OBJ_PATH_READ)/%.o: $(SRC_PATH_READ)/%.c
	@mkdir $(OBJ_PATH_READ) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

$(OBJ_PATH_STRING)/%.o: $(SRC_PATH_STRING)/%.c
	@mkdir $(OBJ_PATH_STRING) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

$(OBJ_PATH_TEST_IS)/%.o: $(SRC_PATH_TEST_IS)/%.c
	@mkdir $(OBJ_PATH_TEST_IS) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

clean :
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	@rm -rf $(NAME)

re : fclean all
