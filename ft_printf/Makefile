NAME        	= libftprintf.a

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

RM          	= rm -f

SRCS        	= ft_printf.c ft_printers.c ft_base_printers.c 
OBJS        	= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

bonus:	all

.PHONY:	all clean fclean bonus re 
