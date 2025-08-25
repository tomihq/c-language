CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = hello-world

all: $(TARGET)

hello-world: hello-world.o
	     $(CC) $(CFLAGS) $^ -o $@

hello-world.o: hello-world.c
	     $(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o hello-world

.PHONY: all clean
