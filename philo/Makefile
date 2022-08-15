NAME = 		philo

HEADER = 	includes/philo.h
#HEADER_BONUS

SRCS = 		srcs/main.c \
	   		srcs/lib_utils.c \
			srcs/load_and_check.c \
#SRCS_BONUS

CC = gcc

FLAGS = -Wextra -Wall -Werror #-fsanitize=address

RM = rm -f

m:
	@${CC} ${FLAGS} -g -pthread ${SRCS} -o ${NAME} -I.${HEADER}

bonus:

clean:

re:
