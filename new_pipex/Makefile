# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 13:04:49 by dadoming          #+#    #+#              #
#    Updated: 2022/05/06 15:24:44 by dadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft/libft.a

HEADER = pipex.h

CC = gcc

FLAGS = -Wextra -Wall -Werror -o

SRCS = pipex.c get_next_line.c here_doc.c error_handling.c childs.c var_init.c free.c

all: ${LIBFT}
	@echo Compiling...
	@${CC} ${FLAGS} ${NAME} ${SRCS} ${LIBFT} -I.${HEADER}

${NAME}: ${LIBFT} ${SRCS}

${LIBFT}:
	cd libft/ && make bonus
	cd libft/ && make clean