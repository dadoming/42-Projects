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

FLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs/
SRCS = $(wildcard $(SRCS_DIR)*.c)

OBJS = $(SRCS:%.c=%.o)

${LIBFT}: lib

${NAME}: lib ${LIBFT} ${OBJS}
	@echo "$(GREEN)Compiling...$(END)"
	@${CC} ${FLAGS} -o ${NAME} ${OBJS} ${LIBFT} -I.${HEADER}

lib: 
	@cd libft/ && make -s bonus

all: ${NAME}

clean:
	@echo "$(RED)Removing push_swap executable$(END)"
	@${RM} ${NAME}

fclean: clean
	@echo "$(RED)Removing libft files$(END)"
	@echo "$(RED)Removing object files$(END)"
	@cd libft/ && make -s fclean
	@${RM} ${OBJS}

re: fclean all
	@echo "$(BLUE)Done! 😃$(END)"

.PHONY: all clean fclean re
