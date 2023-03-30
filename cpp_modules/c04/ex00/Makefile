NAME = CatsAndDogs

CC = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98 

INC = Animal.hpp Cat.hpp Dog.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re