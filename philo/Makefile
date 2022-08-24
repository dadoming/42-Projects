NAME = 		philo

HEADER = 	includes/philo.h

SRCS = 		srcs/main.c \
	   		srcs/lib_utils.c \
			srcs/load_and_check.c \

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
