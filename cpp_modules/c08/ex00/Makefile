NAME = Easyfind

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 

INC = easyfind.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

make r:
	@make re
	./$(NAME)

.PHONY: all clean fclean re
