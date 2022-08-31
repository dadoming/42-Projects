NAME = 		philo

HEADER = 	includes/philo.h

SRCS = 		srcs/main.c \
	   		srcs/utils.c \
			srcs/parser.c \
			srcs/time.c \
			srcs/threads.c \
			srcs/close.c \
			srcs/print.c \
			srcs/actions.c \

CC = gcc

FLAGS = -Wextra -Wall -Werror #-fsanitize=address

RM = rm -f

all:
	@echo "Compiling..."
	@${CC} ${FLAGS} -g -pthread ${SRCS} -o ${NAME} -I.${HEADER}

clean: 
	@echo "philo erased..."
	@${RM} ${NAME}

re: 
	make clean && make all
