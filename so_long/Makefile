# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 18:06:31 by dadoming          #+#    #+#              #
#    Updated: 2022/06/05 18:23:14 by dadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#LIBFT = libft/libft.a

#GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

HEADER = window.h

CC = gcc

#FLAGS = -Wextra -Wall -Werror -o

SRCS = so_long.c

RM = rm -f

#${FLAGS}

all:
	@echo Compiling...
	@${CC} ${NAME} ${SRCS} -I.${HEADER}

${NAME}: ${SRCS}

clean:
	@echo "Cleaning nothing"

fclean: clean
	@echo "Cleaning so_long"
	@${RM} ${NAME}

re: fclean all
	@echo "Done! 😃"
