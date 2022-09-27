# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 19:25:17 by dadoming          #+#    #+#              #
#    Updated: 2022/09/27 17:38:22 by dadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m

RED=\033[0;31m

BLUE=\033[0;34m

END=\033[0m

NAME = push_swap

LIBFT = libft/libft.a

HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -o

SRCS = srcs/push_swap.c \
	srcs/init_stacks.c \
	srcs/moves_push.c \
	srcs/moves_revrotate.c \
	srcs/moves_rotate.c \
	srcs/moves_swap.c \
	srcs/sort_little.c \
	srcs/sort_mid.c \
	srcs/sort_big.c \
	srcs/check_errors.c \
	srcs/sort_big_utils.c \
	srcs/utils.c \
	srcs/sort.c

${NAME}: all

lib: 
	@cd libft/ && make -s bonus

all: lib ${LIBFT} 
	@echo "$(GREEN)Compiling...$(END)"
	@${CC} ${FLAGS} ${NAME} ${SRCS} ${LIBFT} -I.${HEADER}

clean:
	@echo "$(RED)Removing push_swap executable$(END)"
	@${RM} ${NAME}

fclean: clean
	@echo "$(RED)Removing library files$(END)"
	@${RM} ${NAME}
	@cd libft/ && make -s fclean

re: fclean all
	@echo "$(BLUE)Done! 😃$(END)"