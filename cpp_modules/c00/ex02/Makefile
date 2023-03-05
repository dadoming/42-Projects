NAME = bank

SRCS = tests.cpp Account.cpp

INCLUDES = Account.hpp

OBJS = $(SRCS:%.cpp=%.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98

LOGFILE = $(shell date +%Y%m%d_%H%M%S).log


all: $(NAME)
	./$(NAME) > $(LOGFILE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

clean_logs:
	find . -maxdepth 1 -name "*.log" ! -name "19920104_091532.log" -delete
	rm -f diff1.log diff2.log

fclean: clean clean_logs
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
