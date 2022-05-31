# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 13:04:49 by dadoming          #+#    #+#              #
#    Updated: 2022/05/24 17:36:38 by dadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#need to finish makefile commands

NAME = pipex

LIBFT = libft/libft.a

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

HEADER = pipex.h

CC = gcc

FLAGS = -Wextra -Wall -Werror -o

SRCS = pipex.c here_doc.c error_handling.c childs.c free.c pipes.c

all: ${LIBFT}
	@echo Compiling...
	@${CC} ${FLAGS} ${NAME} ${SRCS} ${GNL} ${LIBFT} -I.${HEADER}

${NAME}: ${LIBFT} ${SRCS}

${LIBFT}:
	cd libft/ && make bonus
	cd libft/ && make clean
