NAME = triangle

CC = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98 

INC = Fixed.hpp Point.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re