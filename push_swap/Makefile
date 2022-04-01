# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 19:31:22 by dadoming          #+#    #+#              #
#    Updated: 2022/04/01 13:55:21 by dadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -o

SRCS = main.c init_stacks.c for_three.c moves_push.c moves_revrotate.c moves_rotate.c moves_swap.c for_four_or_five.c utils.c

all: ${LIBFT}
	@echo Files compiled! Executable "push_swap" generated.
	@${CC} ${FLAGS} ${NAME} ${SRCS} ${LIBFT} -I.${HEADER}

${NAME}: ${LIBFT} ${SRCS}

${LIBFT}:
	cd libft/ && make bonus
	cd libft/ && make clean
