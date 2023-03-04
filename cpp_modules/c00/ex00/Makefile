CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98 

megaphone: megaphone.o
	$(CC) $(CFLAGS) -o megaphone megaphone.o

megaphone.o: megaphone.cpp
	$(CC) $(CFLAGS) -c megaphone.cpp

all: megaphone

clean:
	rm -f megaphone megaphone.o

re:
	make clean
	make all

.PHONY: all clean re
