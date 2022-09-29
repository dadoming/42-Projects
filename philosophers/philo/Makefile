NAME = philo

INCLUDES_DIR = includes/
INCLUDES = $(wildcard $(INCLUDES_DIR)*.h)

SRCS_DIR = srcs/
SRCS = $(wildcard $(SRCS_DIR)*.c)

OBJS = $(SRCS:%.c=%.o)

${NAME}: ${OBJS} 
	@echo "Compiling..."
	${CC} ${FLAGS} -g -o ${NAME} -pthread ${OBJS}

all: ${NAME}

clean: 
	${RM} ${NAME}

fclean: clean 
	${RM} ${OBJS}

re: clean all

FLAGS = -Wall -Werror -Wextra #-fsanitize=thread
CC = gcc
RM = rm -f

.PHONY: all clean fclean re
