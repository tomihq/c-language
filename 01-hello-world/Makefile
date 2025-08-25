CC = gcc
CFLAGS = -Wall -Wextra -pedantic

all: hello-world

hello-world: hello-world.o
	     $(CC) $(CFLAGS) hello-world.o -o hello-world

hello-world.o: hello-world.c
	       $(CC) $(CFLAGS) -c hello-world.c -o hello-world.o

clean:
		rm *.o hello-world

.PHONY: all clean
