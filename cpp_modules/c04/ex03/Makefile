NAME = Wizards

CC = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98 

INC = AMateria.hpp Character.hpp Cure.hpp Ice.hpp MateriaSource.hpp ClearMateria.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp ClearMateria.cpp


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re