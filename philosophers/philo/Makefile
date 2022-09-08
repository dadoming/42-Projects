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
			srcs/check_philo_status.c \

CC = gcc

FLAGS = -Wextra -Wall -Werror -fsanitize=thread

RM = rm -f

all:
	@echo "Compiling..."
	@${CC} ${FLAGS} -g -pthread ${SRCS} -o ${NAME} -I.${HEADER}

clean: 
	@echo "philo erased..."
	@${RM} ${NAME}

re: 
	make clean && make all
