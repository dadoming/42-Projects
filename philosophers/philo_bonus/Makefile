NAME = philo
CFLAGS = -Wall -Werror -Wextra -fsanitize=thread
CC = gcc
RM = rm -f
HEADER = philo.h
OBJS = $(SRCS:%.c=%.o)
SRCS = srcs/main.c \
	srcs/timer.c \
	srcs/init_program.c \
	srcs/start_program.c \
	srcs/check_input.c \
	srcs/utils.c \
	srcs/destroy.c \
	srcs/actions.c \
	srcs/death.c

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -g -o ${NAME} -pthread ${OBJS}

clean: 
	${RM} ${NAME}

fclean: clean 
	${RM} ${OBJS}

re: fclean all

.PHONY: all clean fclean re
