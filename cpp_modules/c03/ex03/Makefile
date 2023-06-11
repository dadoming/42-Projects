NAME = diamond_clap

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -Wshadow -g -std=c++98 -fsanitize=address 

INC = Claptrap.hpp Scavtrap.hpp	Fragtrap.hpp DiamondTrap.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
