NAME        = libftprintf.a
HEADER		= libftprintf.h
INCLUDES	= -Idouble_lst -I.
FLAGS      	= -Wall -Wextra -Werror -g
RM          = rm -f
SRCS        = ft_printf.c ft_printers.c ft_base_printers.c 
OBJS        = $(SRCS.c=.o)

%.o %.c
	@gcc $(FLAGS) $(INCLUDES) -c -o $@ $ $(NAME) $(OBJS)
	@ar -rs $(NAME) $(OBJS)

.c.o
			@$(CC) $(CFLAGS) -c $ -o $(.c=.o)

all		$(NAME)

$(NAME)	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
clean
			$(RM) $(OBJS)

fclean		clean
			$(RM) $(NAME)

re			fclean all
ap			all clean
.PHONY		all clean fclean re 