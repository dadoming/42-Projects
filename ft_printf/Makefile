# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 14:44:42 by dadoming          #+#    #+#              #
#    Updated: 2022/03/03 14:44:42 by dadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = ft_printf.c ft_printers.c ft_base_printers.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):
	gcc $(FLAGS) -c -I. ${HEADER} $(SRCS)
	ar -rcs $(NAME) $(OBJS)

clean:
	${RM} $(OBJS)
	${RM} ft_printf.h.gch

fclean:	clean
	${RM} $(NAME)

re:	fclean all

.PHONY:	all clean fclean re 