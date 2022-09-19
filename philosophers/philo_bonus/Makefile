NAME = 		philo_bonus

HEADER = 	includes/philo_bonus.h

SRCS = 		srcs/main.c \
			srcs/sems.c \
			srcs/utils.c \
			srcs/parse_and_init.c \
			srcs/close.c \
			srcs/time.c \
			srcs/actions.c \
			#srcs/death.c 

CC = gcc

FLAGS = -Wextra -Wall -Werror #-fsanitize=thread

RM = rm -f

all:
	@echo "Compiling..."
	@${CC} ${FLAGS} -g -pthread ${SRCS} -o ${NAME} -I.${HEADER}

clean: 
	@echo "philo erased..."
	@${RM} ${NAME}

re: 
	make clean && make all
