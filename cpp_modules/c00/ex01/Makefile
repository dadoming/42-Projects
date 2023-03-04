NAME = my_awesome_phonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98 

INC = Phonebook.hpp Contact.hpp

OBJS = $(SRCS:%.cpp=%.o)

SRCS = main.cpp \
		PhoneBook.cpp \
		Contact.cpp


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re