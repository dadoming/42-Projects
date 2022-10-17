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

NAME = push_swap

LIBFT = libft/libft.a

HEADER = push_swap.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/check_errors.c \
	srcs/init_stacks.c \
	srcs/moves_push.c \
	srcs/moves_revrotate.c \
	srcs/moves_rotate.c \
	srcs/moves_swap.c \
	srcs/push_swap.c \
	srcs/sort_big_utils.c \
	srcs/sort_big.c \
	srcs/sort_little.c \
	srcs/sort_mid.c \
	srcs/sort.c \
	srcs/utils.c
	
OBJS = $(SRCS:%.c=%.o)

all: ${NAME}

${LIBFT}: 
	make -C libft/ all

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} -I.${HEADER}

clean:
	${RM} ${NAME}

fclean: clean
	make -C libft/ fclean
	${RM} ${OBJS}

re: fclean all

.PHONY: all clean fclean re
