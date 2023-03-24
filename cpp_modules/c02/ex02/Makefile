NAME = operators

CC = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98 

INC = Fixed.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp Fixed.cpp

TESTS = tests.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

tests: 
	$(CC) $(CFLAGS) -o tests $(TESTS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f tests

re: fclean all

.PHONY: all clean fclean re
