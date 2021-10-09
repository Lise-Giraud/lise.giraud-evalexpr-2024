CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra
DBFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra -fsanitize=address -g
LDFLAGS=-lcriterion
BINARY=evalexpr
OBJ=src/stack.o src/my_evalexpr.o src/fifo.o src/shunting_yard.o src/main.o

all: evalexpr

evalexpr: $(OBJ)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJ)

check:
	$(CC) $(DBFLAGS) $(LDFLAGS) src/my_evalexpr.c src/stack.c tests/*.c -o $(BINARY)
	./$(BINARY) --verbose
clean :
	rm -rf src/*.o
	rm -rf $(BINARY)
