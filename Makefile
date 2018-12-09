# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 08:38:15 by rsathiad          #+#    #+#              #
#    Updated: 2018/12/08 16:39:54 by rsathiad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = *.o

checkerSRC = check/check_util.c check/checker.c check/stack_util.c \
			 check/shared_util.c check/stdout_msg.c

pushSRC = push/push_swap_sort_util.c push/push_swap_sort.c \
		  push/push_swap.c push/shared_util.c push/sort_rank.c \
			push/command_list_one.c push/op_functions.c \
			push/validation.c

pushHDR = includes/push_swap.h

checkerHDR = includes/checker.h

all: LIBFT checker push_swap

checker:
	@gcc -o checker $(CFLAGS) $(checkerSRC) -I $(checkerHDR) -L libft -lft -g
	@echo "\033[1;32m[Compiled]\033[0m: \033[1;33m./checker\033[0m"

push_swap:
	@gcc -o push_swap $(CFLAGS) $(pushSRC) -I $(pushHDR) -L libft -lft -g
	@echo "\033[1;32m[Compiled]\033[0m: \033[1;36m./pushswap\033[0m"

LIBFT :
	@cd libft && make


clean:
	@rm -rf $(OBJ)
	@echo "\033[1;31m[Removed]\033[0m: checker object files"

fclean: clean
	@clear
	@rm -rf checker
	@rm -rf push_swap
	@cd libft && make fclean

re: fclean all

CFLAGS = -Wall -Werror -Wextra

PHONY:
	clean fclean all re
