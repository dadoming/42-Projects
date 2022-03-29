# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 19:31:22 by dadoming          #+#    #+#              #
#    Updated: 2022/03/29 18:10:45 by dadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -o
SRCS = main.c init_stacks.c for_three.c moves_push.c moves_revrotate.c moves_rotate.c moves_swap.c

all: ${LIBFT}
	${CC} ${FLAGS} ${NAME} ${SRCS} ${LIBFT} -I.${HEADER}

${NAME}: ${LIBFT} ${SRCS}

${LIBFT}:
	cd libft/ && make bonus
