NAME = philo
CFLAGS = -Wall -Werror -Wextra #-fsanitize=thread
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
	srcs/simulation.c \
	srcs/check_death.c

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -g -o ${NAME} -pthread ${OBJS}

clean: 
	${RM} ${NAME}

fclean: clean 
	${RM} ${OBJS}

re: fclean all

.PHONY: all clean fclean re
