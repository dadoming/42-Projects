NAME = inheritfrag

CC = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98 

INC = Claptrap.hpp Scavtrap.hpp	Fragtrap.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
