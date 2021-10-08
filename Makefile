CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra
DBFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra -fsanitize=address -g
LDFLAGS=-lcriterion
BINARY=evalexpr
OBJ=src/stack.o src/my_evalexpr.o

all: evalexpr

evalexpr: $(OBJ)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJ)

check:
	$(CC) $(DBFLAGS) $(LDFLAGS) src/my_evalexpr.c tests/*.c -o $(BINARY)
	./evalexpr --verbose

clean :
	rm -rf *.o
	rm -rf $(BINARY)
