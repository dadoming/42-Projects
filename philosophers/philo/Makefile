NAME = philo
CFLAGS = -Wall -Werror -Wextra -fsanitize=thread
CC = gcc
RM = rm -f
HEADER = philo.h
OBJS = $(SRCS:%.c=%.o)
SRCS = srcs/actions.c \
	srcs/check_philo_status.c \
	srcs/close.c \
	srcs/main.c \
	srcs/parser.c \
	srcs/print.c \
	srcs/threads.c \
	srcs/time.c \
	srcs/utils.c


all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -g -o ${NAME} -pthread ${OBJS}

clean: 
	${RM} ${NAME}

fclean: clean 
	${RM} ${OBJS}

re: fclean all

.PHONY: all clean fclean re
