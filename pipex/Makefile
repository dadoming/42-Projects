NAME = pipex

LIBFT = libft/libft.a

HEADER = pipex.h

CC = gcc

FLAGS = -Wextra -Wall -Werror -o

SRCS = pipex.c pipex_utils.c var_manage.c

all: ${LIBFT}
	@echo Compiling...
	@${CC} ${FLAGS} ${NAME} ${SRCS} ${LIBFT} -I.${HEADER}

${NAME}: ${LIBFT} ${SRCS}

${LIBFT}:
	cd libft/ && make bonus
	cd libft/ && make clean
#$(NAME): libft.a				https://github.com/protsaq/pipex/blob/master/Makefile
#	gcc $(CFLAGS) -I $(HDRS) -L. -l ft -D BONUS=0 $(SRCS) $(DEFAULT) $(MAIN) -o $(NAME)
#											^
#bonus: libft.a								Ɐ
#	gcc $(CFLAGS) -I $(HDRS) -L. -l ft -D BONUS=1 $(SRCS) $(BONUS) $(MAIN) -o $(NAME)
