CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = hello-world

all: $(TARGET)

$(TARGET): hello-world.o
	     $(CC) $(CFLAGS) $^ -o $@

hello-world.o: hello-world.c
	     $(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(TARGET)

.PHONY: all clean
