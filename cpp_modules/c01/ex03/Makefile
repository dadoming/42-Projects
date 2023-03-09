NAME = unnecesary_violence

CC = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98 

INC = HumanA.hpp HumanB.hpp Weapon.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
