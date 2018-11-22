# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 11:27:03 by rfibigr           #+#    #+#              #
#    Updated: 2018/11/22 14:38:29 by rfibigr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

ASM_PATH = assembler
COREWAR_PATH = virtual_machine

all:
	make -C $(ASM_PATH)
	make -C $(COREWAR_PATH)

clean:
	make clean -C $(ASM_PATH)
	make clean -C $(COREWAR_PATH)

fclean:
	make fclean -C $(ASM_PATH)
	make fclean -C $(COREWAR_PATH)

re:
	make fclean all -C $(ASM_PATH)
	make fclean all -C $(COREWAR_PATH)
