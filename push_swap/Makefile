# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 19:25:17 by dadoming          #+#    #+#              #
#    Updated: 2022/06/02 15:57:36 by dadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

all: ${LIBFT}
	@echo Compiling...
	@${CC} ${FLAGS} ${NAME} ${SRCS} ${LIBFT} -I.${HEADER}

${NAME}: ${LIBFT} ${SRCS}

${LIBFT}:
	cd libft/ && make bonus
	cd libft/ && make clean

clean:
	@echo "Nothing to be cleaned."

fclean: clean
	@echo "Cleaning ./push_swap and libft.a..."
	@${RM} ${NAME}
	@${RM} ${LIBFT}

re: fclean all
	@echo "Done! 😃"