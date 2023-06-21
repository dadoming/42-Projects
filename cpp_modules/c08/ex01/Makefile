NAME = Span

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 

INC = Span.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp Span.cpp


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
