NAME = Instatiation

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 

INC = Animal.hpp Cat.hpp Dog.hpp Brain.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re