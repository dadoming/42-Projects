# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 15:56:02 by dadoming          #+#    #+#              #
#    Updated: 2022/11/14 15:56:39 by dadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CFLAGS = -Wall -Werror -Wextra -fsanitize=thread

CC = gcc

RM = rm -f

HEADER = header/philo_bonus.h

OBJS = $(SRCS:%.c=%.o)

SRCS = srcs/main.c \
	srcs/timer.c \
	srcs/init_program.c \
	srcs/start_program.c \
	srcs/check_input.c \
	srcs/utils.c \
	srcs/utils2.c \
	srcs/destroy.c \
	srcs/actions.c \
	srcs/death.c

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -g -o ${NAME} ${OBJS} -pthread ${HEADER}

clean: 
	${RM} ${NAME}

fclean: clean 
	${RM} ${OBJS}

re: fclean all

.PHONY: all clean fclean re
