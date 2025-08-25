all: hello-world

hello-world: hello-world.o
	     gcc -Wall -Wextra -pedantic hello-world.o -o hello-world

hello-world.o: hello-world.c
	       gcc -Wall -Wextra -pedantic -c hello-world.c -o hello-world.o

clean:
		rm *.o hello-world

.PHONY: all clean
