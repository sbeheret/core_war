# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 11:27:03 by rfibigr           #+#    #+#              #
#    Updated: 2018/11/30 12:14:17 by rfibigr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

ASM_PATH = assembler
COREWAR_PATH = virtual_machine
LIB_PATH =	lib/libft

NC = \033[0m
RED = \033[1;31m

all:
	@echo "\n\tLIBFT"
	@make -C $(LIB_PATH)
	@echo "\n\tASSEMBLER"
	@make -C $(ASM_PATH)
	@echo "\n\tVIRTUAL MACHINE"
	@make -C $(COREWAR_PATH)

clean:
	@echo "$(RED) --Cleaning--\t\tobject folders$(NC)"
	@make clean -C $(ASM_PATH)
	@make clean -C $(LIB_PATH)
	@make clean -C $(COREWAR_PATH)

fclean:
	@echo "$(RED) --Cleaning--\t\tobject folders"
	@echo " --Cleaning--\t\texecutables$(NC)"
	@make fclean -C $(ASM_PATH)
	@make fclean -C $(LIB_PATH)
	@make fclean -C $(COREWAR_PATH)

re: fclean all

debug:
	make debug -C $(COREWAR_PATH)
