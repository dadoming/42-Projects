# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:24:53 by dadoming          #+#    #+#              #
#    Updated: 2022/11/16 14:17:04 by dadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Werror -Wextra -fsanitize=thread -g

CC = gcc

RM = rm -f

HEADER = philo.h

OBJS = $(SRCS:%.c=%.o)

SRCS = srcs/main.c \
	srcs/utils.c \
	srcs/check_input.c \
	srcs/init_program.c \
	srcs/timer.c \
	srcs/start_program.c \
	srcs/print.c \
	srcs/destroy.c \
	srcs/actions.c \
	srcs/check_death.c

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} -pthread ${OBJS}

clean: 
	${RM} ${NAME}

fclean: clean 
	${RM} ${OBJS}

re: fclean all

.PHONY: all clean fclean re
