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

SRCS = push_swap.c \
	stacks_init.c \
	moves_push.c \
	moves_revrotate.c \
	moves_rotate.c \
	moves_swap.c \
	sort_little.c \
	sort_mid.c \

all: ${LIBFT}
	@echo Compiling...
	@${CC} ${FLAGS} ${NAME} ${SRCS} ${LIBFT} -I.${HEADER}

${NAME}: ${LIBFT} ${SRCS}

${LIBFT}:
	cd libft/ && make bonus
	cd libft/ && make clean

tests5:
	@echo ""
	./push_swap 1 2 3 4 5
	@echo ""
	./push_swap 5 4 3 2 1
	@echo ""
	./push_swap 4 5 2 3 1
	@echo ""
	./push_swap 1 3 2 4 5
	@echo ""
	./push_swap 3 5 4 1 2
	@echo ""
	./push_swap 4 2 1 5 3
	@echo ""
	./push_swap 2 4 3 1 5

tests4:
	@echo ""
	./push_swap 1 2 3 4
	@echo ""
	./push_swap 5 4 3 2
	@echo ""
	./push_swap 4 5 2 3
	@echo ""
	./push_swap 1 3 2 4
	@echo ""
	./push_swap 3 5 4 1
	@echo ""
	./push_swap 4 2 1 5
	@echo ""
	./push_swap 2 4 3 1

tests3:
	@echo ""
	./push_swap 1 2 3
	@echo ""
	./push_swap 1 3 2
	@echo ""
	./push_swap 2 1 3
	@echo ""
	./push_swap 2 3 1
	@echo ""
	./push_swap 3 1 2
	@echo ""
	./push_swap 3 2 1

clean:
	@echo "Nothing to be cleaned."

fclean: clean
	@echo "Cleaning ./push_swap and libft.a..."
	@${RM} ${NAME}
	@${RM} ${LIBFT}

re: fclean all
	@echo "Done! 😃"