# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 18:06:31 by dadoming          #+#    #+#              #
#    Updated: 2022/06/21 04:16:44 by dadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft/libft.a

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

INCLUDES = /includes

CC = gcc

FLAGS = -Wextra -Wall -Werror
#-fsanitize=address

SRCS = srcs/so_long.c \
		srcs/window.c \
		srcs/error.c \
		srcs/init.c \
		srcs/checker.c \
		srcs/print.c \
		srcs/move.c \
		srcs/animations.c \
		srcs/close.c \
		srcs/img_control.c \

RM = rm -f


all: ${LIBFT}
	@${CC} ${FLAGS} -o ${NAME} -I /usr/local/include ${SRCS} ${GNL} ${LIBFT} -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit -I.${INCLUDES} 
	
	@printf "                                    \r"
	@printf "\033[2;32m               DONE!            \r"
	@sleep 0.2
	@printf "\033[1;;32m               DONE! \n"
	@sleep 0.3

${NAME}: ${LIBFT} ${SRCS}

${LIBFT}:
	@cd libft/ && make bonus
	@cd libft/ && make clean

man:
	@echo ""
	@echo "gcc -I /usr/local/include so_long.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit"
	@echo ""
	@echo "man /usr/share/man/man3/mlx.1"
	@echo "man /usr/share/man/man3/mlx_new_window.1"
	@echo "man /usr/share/man/man3/mlx_new_image.1"
	@echo "man /usr/share/man/man3/mlx_pixel_put.1"
	@echo "man /usr/share/man/man3/mlx_loop.1"
	@echo ""

clean:

fclean: clean
	@${RM} ${NAME}
	@${RM} ${LIBFT}
	@printf "\033[1;91m       CLEANING\r"
		@sleep 0.2
		@printf "       CLEANING .\r"
		@sleep 0.2
		@printf "       CLEANING . . \r"
		@sleep 0.2
		@printf "       CLEANING . . . \r"
		@sleep 0.2
		@printf "                                     \r"

re: fclean all

.PHONY: all man clean fclean re