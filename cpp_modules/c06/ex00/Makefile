NAME = Convert

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 

INC = ScalarConverter.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp ScalarConverter.cpp


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
